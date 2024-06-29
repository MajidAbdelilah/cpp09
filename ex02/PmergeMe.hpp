#include <iostream>
#include <vector>
#include <deque>

// #define K 390000000
#define K 32

long long get_number(std::string str);
void insertionSort_vec(std::vector<int> &A, int p, int q);
void merge_vec(std::vector<int> &A, int p, int q, int r);
void sort_vec(std::vector<int> &A, int p, int r);
void insertionSort_deq(std::deque<int> &A, int p, int q);
void merge_deq(std::deque<int> &A, int p, int q, int r);
void sort_deq(std::deque<int> &A, int p, int r);
