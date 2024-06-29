#include <iostream>
#include <vector>
#include <deque>
#include "PmergeMe.hpp"

long long get_number(std::string str)
{
	// // std::cout<< str << "\n";
	unsigned long i = 0;
	if(str[i] == '+')
		i++;
	while(i < str.size() && std::isdigit(str[i])) {
		i++;
	}
	if(i != str.size())
		throw std::invalid_argument("Error: |" + str + "| is not a valid integer.");

	long long res = strtoll(str.c_str(), NULL, 10);
	
	if(res < std::numeric_limits<int>::min() || res > std::numeric_limits<int>::max() || str.size() > 11) {
		throw std::invalid_argument("Error: " + str + " is not a valid integer.");
	}
	return res;
}

void insertionSort_vec(std::vector<int> &A, int p, int q) {
    for (int i = p; i < q; i++) {
        int tempVal = A[i + 1];
        int j = i + 1;
        while (j > p && A[j - 1] > tempVal) {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = tempVal;
    }
    // int[] temp = Arrays.copyOfRange(A, p, q +1);
    std::vector<int> tmp;
	tmp.resize(((q +1) - p));
	// std::cout<< p << " " << (q +1) << "\n";
	// memcpy(temp, A + p, sizeof(int) * ((q +1) - p));
	std::copy(A.begin() + p, A.begin() + ((q +1)), tmp.begin());
	unsigned long i = 0;
	while(i < tmp.size())
	{
		// std::cout<< tmp[i] << " ";
		i++;
	}
	// std::cout<< "\n";
    // Arrays.stream(temp).forEach(i -> System.out.print(i + " "));
    // System.out.println();
}

void merge_vec(std::vector<int> &arr, int l, int m, int r) 
{ 
	// std::cout << "merged\n";
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    // Create temp arrays 
    int L[n1], R[n2]; 
  
    // Copy data to temp arrays 
    // L[] and R[] 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    // Merge the temp arrays back 
    // into arr[l..r] 
    // Initial index of first subarray 
    i = 0; 
  
    // Initial index of second subarray 
    j = 0; 
  
    // Initial index of merged subarray 
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    // Copy the remaining elements 
    // of L[], if there are any 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    // Copy the remaining elements of 
    // R[], if there are any 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void sort_vec(std::vector<int> &A, int p, int r) {
    if (r - p > K) {
        int q = (p + r) / 2;
        sort_vec(A, p, q);
        sort_vec(A, q + 1, r);
        merge_vec(A, p, q, r);
    } else {
        insertionSort_vec(A, p, r);
		unsigned long i = 0;
		// std::cout<< "----------\n";
		while(i < A.size())
		{
		 // std::cout<< A[i] << " "; 
			i++;
		}
		// std::cout<< "\n----------\n";
    }
}

void insertionSort_deq(std::deque<int> &A, int p, int q) {
    for (int i = p; i < q; i++) {
        int tempVal = A[i + 1];
        int j = i + 1;
        while (j > p && A[j - 1] > tempVal) {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = tempVal;
    }
    // int[] temp = Arrays.copyOfRange(A, p, q +1);
    std::deque<int> tmp;
	tmp.resize(((q +1) - p));
	// std::cout<< p << " " << (q +1) << "\n";
	// memcpy(temp, A + p, sizeof(int) * ((q +1) - p));
	std::copy(A.begin() + p, A.begin() + ((q +1)), tmp.begin());
	unsigned long i = 0;
	while(i < tmp.size())
	{
		// std::cout<< tmp[i] << " ";
		i++;
	}
	// std::cout<< "\n";
    // Arrays.stream(temp).forEach(i -> System.out.print(i + " "));
    // System.out.println();
}


void merge_deq(std::deque<int> &arr, int l, int m, int r) 
{ 
	// std::cout << "merged\n";
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    // Create temp arrays 
    int L[n1], R[n2]; 
  
    // Copy data to temp arrays 
    // L[] and R[] 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    // Merge the temp arrays back 
    // into arr[l..r] 
    // Initial index of first subarray 
    i = 0; 
  
    // Initial index of second subarray 
    j = 0; 
  
    // Initial index of merged subarray 
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    // Copy the remaining elements 
    // of L[], if there are any 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    // Copy the remaining elements of 
    // R[], if there are any 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void sort_deq(std::deque<int> &A, int p, int r) {
    if (r - p > K) {
        int q = (p + r) / 2;
        sort_deq(A, p, q);
        sort_deq(A, q + 1, r);
        merge_deq(A, p, q, r);
    } else {
        insertionSort_deq(A, p, r);
		unsigned long i = 0;
		// std::cout<< "----------\n";
		while(i < A.size())
		{
		 // std::cout<< A[i] << " "; 
			i++;
		}
		// std::cout<< "\n----------\n";
    }
}

