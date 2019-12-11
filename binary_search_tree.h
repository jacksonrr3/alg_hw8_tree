#pragma once

#include <list>
#include <iostream>

template <typename T>
struct Node {
	Node* _left;
	size_t _key;
	std::list<T> _value;
	Node* _right;
	Node* _parent = nullptr;


	Node(const size_t& key, const T& value, Node* par) :_parent(par), _key(key), _left(nullptr), _right(nullptr) {
		_value.emplace_back(value);
	}

	/*
	~Node() {
		if (_left != nullptr) { delete _left; }
		
		if (_right != nullptr) { delete _right; }
	}
	*/

	//добавить лист по значению и ключу
	void insert_node(const size_t& key, const T& value) {
		if (_key == key) { _value.emplace_back(value); }
		else if (_key > key) {
			if (_left == nullptr) { _left = new Node(key, value, this); }
			else { _left->insert_node(key, value); }
		}
		else {
			if (_right == nullptr) { _right = new Node(key, value, this); }
			else { _right->insert_node(key, value); }
		}
	}
	
	//найти значение по ключу
	T search_node(const size_t& key) {
		if (_key == key) { return _value.back(); }
		else if (_right != nullptr && key > _key) { return _right->search_node(key); }
		else if (_left != nullptr && key < _key) { return _left->search_node(key); }
		else { return 0; }
	}
	
	//найти лист по ключу
	Node* find_node(const size_t& key) {
		if (this == nullptr) { return nullptr; }
		if (_key == key) { return this; }
		else if (_right != nullptr && key > _key) { return _right->find_node(key); }
		else if (_left != nullptr && key < _key) { return _left->find_node(key); }
		else { return nullptr; }
	}

	//распечать дерево
	void print_node() {
		if (_left != nullptr) { _left->print_node(); }
		std::cout << _value.back() << std::endl;
		if (_right != nullptr) { _right->print_node(); }
	}

	//добавить поддерево 
	void insert_node_tree(Node* node) {
		if (_key < node->_key) {
			if (_left == nullptr) { _left = node; }
			else { _left->insert_node_tree(node); }
		}
		else {
			if (_right == nullptr) { _right = node; }
			else { _right->insert_node_tree(node); }
		}
	}

};


template <typename T>
class BinarySearchTree {

	Node<T>* _root;

	//добавить дерево в дерево. метод не используется
	void insert_tree(Node<T>* node) {
		if (_root == nullptr) { _root = node; }
		else { _root->insert_node_tree(node); }
	}

public:

	BinarySearchTree() :_root(nullptr) {}
	~BinarySearchTree() { delete _root; }

	//добавление значения по ключу
	void insert(const size_t& key, const T& value) {
		if (_root == nullptr) { _root = new Node<T>(key, value, nullptr); }
		else { _root->insert_node(key, value); }
	}

	//поиск значения по ключу
	T search(const size_t& key) {
		if (_root == nullptr) { return 0; }
		else { return _root->search_node(key); }
	}

	//печать дерева в порядке возрастания
	void print() {
		if (_root != nullptr) { _root->print_node(); }
	}

	//метод позволяющий удалить по ключу лист из дерева
	void remove(const size_t& key) {
		if (_root == nullptr) { return; }
		else { 
			Node<T>* temp = _root->find_node(key);// находим нужный лист
			if (temp == nullptr) { return; }
			Node<T>* par = temp->_parent;
			//если родитель не nullptr
			if (par != nullptr) {
				//обнуляем ссылку на себя в родительском листе
				if (par->_left == temp) { par->_left = nullptr; }
				else { par->_right = nullptr; }

				if (temp->_left != nullptr) { par->insert_node_tree(temp->_left); }
				if (temp->_right != nullptr) { par->insert_node_tree(temp->_right); }
			}

			else {
				if (temp->_left != nullptr) { _root = temp->_left; }
				if (temp->_right != nullptr) { _root->insert_node_tree(temp->_right); }
			}

			temp->_left = nullptr;
			temp->_right = nullptr;
			delete temp;
		}
	}


};
