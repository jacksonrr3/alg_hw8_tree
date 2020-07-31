#pragma once


template <typename T>
class RB_Tree {

	struct Node_RB {
		Node_RB* _parent;
		Node_RB* _left;
		Node_RB* _right;
		T _item;
		//int _item;
		bool _is_red;

		Node_RB(const T& value = T()) :
		//Node_RB(int value = 0) :
			_item(value),
			_parent (nullptr),
			_left (nullptr),
			_right (nullptr),
			_is_red (true)
		{}

		Node_RB* get_uncle() {
			if (_parent == _parent->_parent->_left) {
				return _parent->_parent->_right;
			}
			else {
				return _parent->_parent->_left;
			}
		}

		Node_RB* get_grandfather() {
			return _parent->_parent;
		}

		const T& get_item() const {
			return _item;
		}

		void print_node() {
			if (_left != nullptr) { _left->print_node(); }
			std::cout << _item << " " << _is_red << std::endl;
			if (_right != nullptr) { _right->print_node(); }
		}

		void search_node(const T& key) {
			if (_item == key) { std::cout << "Find " << key << " ok!" << std::endl;	}
			else if (_right != nullptr && key > _item) { _right->search_node(key); }
			else if (_left != nullptr && key < _item) { _left->search_node(key); }
			else { std::cout << "Find " << key << " not!" << std::endl; }
		}

	};

	Node_RB* _root;

public:

	RB_Tree() :_root(nullptr) {}

	void search(const T& key) {
		if (_root == nullptr) { std::cout << "Tree is empty." << std::endl; }
		else { return _root->search_node(key); }
	}

	void leftrotate(Node_RB* node) {
		if (node->_right == nullptr) {
			return;
		}
		else {
			Node_RB* y = node->_right;
			if (y->_left != nullptr) {
				node->_right = y->_left;
				y->_left->_parent = node;
			}
			else {
				node->_right = nullptr;
			}
			if (node->_parent != nullptr) {
				y->_parent = node->_parent;
			}
			if (node->_parent == nullptr) {
				_root = y;
			}
			else {
				if (node == node->_parent->_left) {
					node->_parent->_left = y;
				}
				else {
					node->_parent->_right = y;
				}
			}
			y->_left = node;
			node->_parent = y;
		}
	}

	void rightrotate(Node_RB* node) {
		if (node->_left == nullptr) {
			return;
		}
		else {
			Node_RB* y = node->_left;
			if (y->_right != nullptr) {
				node->_left = y->_right;
				y->_right->_parent = node;
			}
			else {
				node->_left = nullptr;
			}
			if (node->_parent != nullptr) {
				y->_parent = node->_parent;
			}
			if (node->_parent == nullptr) {
				_root = y;
			}
			else {
				if (node == node->_parent->_left) {
					node->_parent->_left = y;
				}
				else {
					node->_parent->_right = y;
				}
			}
			y->_right = node;
			node->_parent = y;
		}
	}

	void check_insert(Node_RB* node) {
		Node_RB* u;
		if (node->_parent == nullptr) {
			node->_is_red = false;
			return;
		}
		while (node->_parent != NULL && node->_parent->_is_red)
		{
			Node_RB* g = node->_parent->_parent;
			if (g->_left == node->_parent)
			{
				if (g->_right != NULL)
				{
					u = g->_right;
					if (u->_is_red)
					{
						node->_parent->_is_red = false;
						u->_is_red = false;
						g->_is_red = true;
						node = g;
					}
				}
				else
				{
					if (node->_parent->_right == node)
					{
						node = node->_parent;
						leftrotate(node);
					}
					node->_parent->_is_red = false;
					g->_is_red = true;
					rightrotate(g);
				}
			}
			else
			{
				if (g->_left != NULL)
				{
					u = g->_left;
					if (u->_is_red)
					{
						node->_parent->_is_red = false;
						u->_is_red = false;
						g->_is_red = true;
						node = g;
					}
				}
				else
				{
					if (node->_parent->_left == node)
					{
						node = node->_parent;
						rightrotate(node);
					}
					node->_parent->_is_red = false;
					g->_is_red = true;
					leftrotate(g);
				}
			}
			_root->_is_red = false;
		}
	}
	
	void insert(const T& value) {
		Node_RB* temp_node = new Node_RB(value);
		Node_RB* p = _root;
		Node_RB* q = nullptr;

		if (_root == nullptr) {
			_root = temp_node;
			_root->_is_red = false;
		}
		else {
			while (p != nullptr) {
				q = p;
				if (p->get_item() < value) {
					p = p->_right;
				}
				else if (p->get_item() == value){
					return;
				}
				else  {
					p = p->_left;
				}
			}
			temp_node->_parent = q;
			if (q->get_item() < value) {
				q->_right = temp_node;
			}
			else {
				q->_left = temp_node;
			}

			check_insert(temp_node);
		}

	}

	/*
	void del(const T& key) {
		
	}
	*/

	void print_tree() const {
		_root->print_node();
	}
	


};
