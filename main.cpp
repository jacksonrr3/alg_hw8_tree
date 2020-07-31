#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "binary_search_tree.h"
#include "decart_tree.h"
#include "test.h"
#include "RB_tree.h"



int main() {
//тесты BST
	std::srand(std::time(nullptr));

	test_bst_time<int>(2500);
	test_dec_time<int>(2500);
	
//тест RB_tree	
	RB_Tree<int> test_tree;

	test_tree.insert(5);
	test_tree.insert(6);
	test_tree.insert(3);
	test_tree.insert(9);
	test_tree.insert(10);
	test_tree.insert(1);
	test_tree.insert(4);
	test_tree.insert(7);
	test_tree.insert(2);

	test_tree.search(2);

	test_tree.print_tree();

	return 0;
}
