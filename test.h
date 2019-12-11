#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <vector>
#include <algorithm>
#include <string>

#include "binary_search_tree.h"
#include "decart_tree.h"


template <typename T>
int gen()
{
	static T i = 1;
	return i++;
}

template <typename T>
void make_vec(std::vector<T>& v) {
	std::generate(v.begin(), v.end(), gen<T>);
}

template <typename T>
void shaffl_vec(std::vector<T>& v) {
	size_t n = v.size();
	for (int i = 0; i < n; i++) {
		T temp = v[i];
		int r = rand() % (n - 1);
		v[i] = v[r];
		v[r] = temp;
	}
}



template<typename T>
void test_bst_time(size_t N) {

	BinarySearchTree<T> test_tree_1;
	BinarySearchTree<T> test_tree_2;

	std::vector<T> vec(N);
	make_vec(vec);

	std::cout << "Test BST------------------------" << std::endl;
	//добавить последовательно N чисел
	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < N; i++) {
		test_tree_1.insert(vec[i], vec[i]*10);
	}
	end = std::chrono::high_resolution_clock::now();
	std::cout << "Fill tree, N =" << N << ", time:" << std::chrono::duration_cast<std::chrono::milliseconds>
		(end - start).count() << " ms;" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	//Найти N/10 чисел
	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < (N/10); i++) {
		int temp = rand() % (N-1);
		test_tree_1.search(temp);
	}
	end = std::chrono::high_resolution_clock::now();
	std::cout << "Search tree, N =" << N << ", time:" << std::chrono::duration_cast<std::chrono::milliseconds>
		(end - start).count() << " ms;" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	//Удалить N/10 чисел
	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < (N / 10); i++) {
		int temp = rand() % (N-1);
		test_tree_1.remove(temp);
	}
	end = std::chrono::high_resolution_clock::now();
	std::cout << "Remove tree, N =" << N << ", time:" << std::chrono::duration_cast<std::chrono::milliseconds>
		(end - start).count() << " ms;" << std::endl;
	std::cout << "-----------------------------------" << std::endl;

	//N = N * 10;
	//добавить случайно N чисел
	shaffl_vec(vec);
	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < N; i++) {
		//int temp = rand() % (N-1);
		test_tree_2.insert(vec[i], vec[i] * 10);
	}
	end = std::chrono::high_resolution_clock::now();
	std::cout << "Fill tree, N =" << N << ", time:" << std::chrono::duration_cast<std::chrono::milliseconds>
		(end - start).count() << " ms;" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	//Найти N/10 чисел
	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < (N / 10); i++) {
		int temp = rand() % (N - 1);
		test_tree_2.search(temp);
	}
	end = std::chrono::high_resolution_clock::now();
	std::cout << "Search tree, N =" << N << ", time:" << std::chrono::duration_cast<std::chrono::milliseconds>
		(end - start).count() << " ms;" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	//Удалить N/10 чисел
	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < (N / 10); i++) {
		int temp = rand() % (N-1);
		test_tree_2.remove(temp);
	}
	end = std::chrono::high_resolution_clock::now();
	std::cout << "Remove tree, N =" << N << ", time:" << std::chrono::duration_cast<std::chrono::milliseconds>
		(end - start).count() << " ms;" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	
}


template<typename T>
void test_dec_time(size_t N) {

	DecartTree<T> test_tree_1;
	DecartTree<T> test_tree_2;

	std::vector<T> vec(N);
	make_vec(vec);
	std::cout << "Test Dec------------------------------" << std::endl;
	//добавить последовательно N чисел
	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < N; i++) {
		test_tree_1.insert(vec[i], rand()%(N-1));
	}
	end = std::chrono::high_resolution_clock::now();
	std::cout << "Fill tree, N =" << N << ", time:" << std::chrono::duration_cast<std::chrono::milliseconds>
		(end - start).count() << " ms;" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	//Найти N/10 чисел
	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < (N / 10); i++) {
		int temp = rand() % (N - 1);
		test_tree_1.search(temp);
	}
	end = std::chrono::high_resolution_clock::now();
	std::cout << "Search tree, N =" << N << ", time:" << std::chrono::duration_cast<std::chrono::milliseconds>
		(end - start).count() << " ms;" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	//Удалить N/10 чисел
	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < (N / 10); i++) {
		int temp = rand() % (N-1);
		test_tree_1.remove(temp);
	}
	end = std::chrono::high_resolution_clock::now();
	std::cout << "Remove tree, N =" << N << ", time:" << std::chrono::duration_cast<std::chrono::milliseconds>
		(end - start).count() << " ms;" << std::endl;
	std::cout << "-----------------------------------" << std::endl;

	//N = N * 10;
	//добавить случайно N чисел

	std::vector<T> vec2(N);
	make_vec(vec2);
	shaffl_vec(vec2);

	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < N; i++) {
		
		test_tree_2.insert(vec2[i], rand() % (N - 1));
	}
	end = std::chrono::high_resolution_clock::now();
	std::cout << "Fill tree, N =" << N << ", time:" << std::chrono::duration_cast<std::chrono::milliseconds>
		(end - start).count() << " ms;" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	//Найти N/10 чисел
	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < (N / 10); i++) {
		int temp = rand() % (N - 1);
		test_tree_2.search(temp);
	}
	end = std::chrono::high_resolution_clock::now();
	std::cout << "Search tree, N =" << N << ", time:" << std::chrono::duration_cast<std::chrono::milliseconds>
		(end - start).count() << " ms;" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	//Удалить N/10 чисел
	start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < (N / 10); i++) {
		int temp = rand() % (N-1);
		test_tree_2.remove(temp);
	}
	end = std::chrono::high_resolution_clock::now();
	std::cout << "Remove tree, N =" << N << ", time:" << std::chrono::duration_cast<std::chrono::milliseconds>
		(end - start).count() << " ms;" << std::endl;
	std::cout << "-----------------------------------" << std::endl;

}
