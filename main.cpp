#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "binary_search_tree.h"
#include "decart_tree.h"
#include "test.h"




int main() {

	std::srand(std::time(nullptr));

	test_bst_time<int>(2500);
	test_dec_time<int>(2500);
	

	return 0;
}
