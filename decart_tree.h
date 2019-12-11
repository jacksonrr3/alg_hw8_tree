#pragma once

#include <list>
#include <iostream>

template <typename T>
class Treap {

	template <typename T>
	friend class DecartTree;

	Treap* _left;
	size_t _x;
	size_t _y;
	//std::list<T> _value;
	Treap* _right;
	Treap* _parent = nullptr;

	Treap(Treap* left = nullptr, Treap* right = nullptr): _left(left), _right(right) {}
	
	//Treap(const size_t& x, const size_t& y, const T& value, Treap* par) :_parent(par), _x(x), _y(y), _left(nullptr), _right(nullptr) {
	//	_value.emplace_back(value);
	//}

	Treap(const size_t& x, const size_t& y, Treap* left = nullptr, Treap* right= nullptr):_x(x), _y(y), _left(left), _right(right) {}


	//найти значение по ключу
	T search_treap(const size_t& x) {
		if (_x == x) { return _y; }
		else if (_right != nullptr && x > _x) { return _right->search_treap(x); }
		else if (_left != nullptr && x < _x) { return _left->search_treap(x); }
		else { return 0; }
	}

	//найти лист по ключу
	Treap* find_treap(const size_t& x) {
		//if (this == nullptr) { return nullptr; }
		if (_x == x) { return this; }
		else if (_right != nullptr && x > _x) { return _right->find_treap(x); }
		else if (_left != nullptr && x < _x) { return _left->find_treap(x); }
		else { return nullptr; }
	}

	//распечать дерево
	void print_treap() {
		if (_left != nullptr) { _left->print_treap(); }
		std::cout << _y << std::endl;
		if (_right != nullptr) { _right->print_treap(); }
	}

	void split(size_t x, Treap<T>*& L, Treap<T>*& R) {
		if (this != nullptr) {
			Treap<T>* newTree = nullptr;
			if (_x <= x) {
				if (_right == nullptr) {
					R = nullptr;
				}
				else {
					_right->split(x, newTree, R);
				}
				L = new Treap<T>(_x, _y, _left, newTree);
			}
			else {
				if (_left == nullptr) {
					L = nullptr;
				}
				else {
					_left->split(x, L, newTree);
				}
				R = new Treap<T>(_x, _y, newTree, _right);
			}
		}
	}

};


template <typename T>
class DecartTree {

	Treap<T>* _root;

public:

	DecartTree():_root(nullptr) {}

	//добавление значения по ключу
	void insert(const size_t& x, const size_t& y) {
		if (_root != nullptr) {
			Treap<T>* L = nullptr;
			Treap<T>* R = nullptr;
			_root->split(x, L, R);
			Treap<T>* m = new Treap<T>(x, y);
			_root = merge(merge(L, m), R);
		}
		else {
			_root = new Treap<T>(x, y);
		}
	}

	//поиск значения по ключу
	T search(const size_t& key) {
		if (_root == nullptr) { return 0; }
		else { return _root->search_treap(key); }
	}

	//печать дерева в порядке возрастания
	void print() {
		if (_root != nullptr) { _root->print_treap(); }
	}

	//метод позволяющий удалить по ключу лист из дерева
	void remove(const size_t& x) {
		Treap<T>* l = nullptr;
		Treap<T>* m = nullptr;
		Treap<T>* r = nullptr;

		_root->split(x - 1, l, r);
		r->split(x, m, r);
		_root = merge(l, r);
	}

	private:

		Treap<T>* merge(Treap<T>* L, Treap<T>* R) {
			if (L == nullptr) { return R; }
			if (R == nullptr) { return L; }
			if (L->_y > R->_y) {
				Treap<T>* newR = merge(L->_right, R);
				return new Treap<T>(L->_x, L->_y, L->_left, newR);
			}
			else {
				Treap<T>* newL = merge(L, R->_left);
				return new Treap<T>(R->_x, R->_y, newL, R->_right);
			}
		}

};
