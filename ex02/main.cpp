#include <exception>
#include <iostream>
#include <vector>
#include <deque>
#include "PmergeMe.hpp"


int main(int arg_num, char **args) {
	std::vector<int> A;
	std::deque<int> B;
	clock_t begin_vec = {0};
	clock_t begin_deq = {0};
	clock_t end_vec = {0};
	clock_t end_deq = {0};
	double time_spent_vec;
	double time_spent_deq;

	if(arg_num < 2) {
		std::cerr << "Usage: " << args[0] << " <int1> <int2> ... <intN>\n";
		return 1;
	}

	std::cout << "Before: ";
	for(int i = 1; i < arg_num; i++) {
		std::cout << args[i] << " ";
	}
	std::cout << "\n";

	try{
		begin_vec = clock();
		for(int i = 1; i < arg_num; i++) {
			A.push_back(get_number(args[i]));
		}

		sort_vec(A, 0, A.size() - 1);
		end_vec = clock();
		time_spent_vec = (double)(end_vec - begin_vec) / CLOCKS_PER_SEC;
	}catch(std::exception &e) {
		std::cerr << "Invalid argument: " << e.what() << "\n";
		return 1;
	}
	std::cout << "After: ";	
	for(unsigned long i = 0; i < A.size(); i++) {
		std::cout << A[i] << " ";
	}
	std::cout << "\n";
	
	try{
		begin_deq = clock();
		for(int i = 1; i < arg_num; i++) {
			B.push_back(get_number(args[i]));
		}

		sort_deq(B, 0, B.size() - 1);
		end_deq = clock();
		time_spent_deq = (double)(end_deq - begin_deq) / CLOCKS_PER_SEC;
	}catch(std::exception &e) {
		std::cerr << "Invalid argument: " << e.what() << "\n";
		return 1;
	}
	
	std::cout << "Time to process a range of " << arg_num - 1 << " elements with std::vector : " << time_spent_vec << "s\n";
	std::cout << "Time to process a range of " << arg_num - 1 << " elements with std::deque : " << time_spent_deq << "s\n";
	
	return 0;
}