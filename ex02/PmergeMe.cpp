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

void merge_vec(std::vector<int> &A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    // int[] LA = Arrays.copyOfRange(A, p, q +1);
    std::vector<int> LA;
	LA.resize(((q + 1) - p));
	// memcpy(LA, A + p, sizeof(int) * ((q + 1) - p));
    std::copy(A.begin() + p, A.begin() + ((q + 1)), LA.begin());
	// int[] RA = Arrays.copyOfRange(A, q+1, r +1);
    std::vector<int> RA;
	RA.resize(((r + 1) - (q + 1)));
	// memcpy(RA, A + (q + 1), sizeof(int) * ((r + 1) - (q + 1)));
    std::copy(A.begin() + (q + 1), A.begin() + ((r + 1)), RA.begin());

	// std::cout<< (q + 1) << "\n" << ((r + 1)) << "\n";
	int RIDX = 0;
    int LIDX = 0;
    for (int i = p; i < r - p + 1; i++) {
        if (RIDX == n2) {
            A[i] = LA[LIDX];
            LIDX++;
        } else if (LIDX == n1) {
            A[i] = RA[RIDX];
            RIDX++;
        } else if (RA[RIDX] > LA[LIDX]) {
            A[i] = LA[LIDX];
            LIDX++;
        } else {
            A[i] = RA[RIDX];
            RIDX++;
        }
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

void merge_deq(std::deque<int> &A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    // int[] LA = Arrays.copyOfRange(A, p, q +1);
    std::deque<int> LA;
	LA.resize(((q + 1) - p));
	// memcpy(LA, A + p, sizeof(int) * ((q + 1) - p));
    std::copy(A.begin() + p, A.begin() + ((q + 1)), LA.begin());
	// int[] RA = Arrays.copyOfRange(A, q+1, r +1);
    std::deque<int> RA;
	RA.resize(((r + 1) - (q + 1)));
	// memcpy(RA, A + (q + 1), sizeof(int) * ((r + 1) - (q + 1)));
    std::copy(A.begin() + (q + 1), A.begin() + ((r + 1)), RA.begin());

	// std::cout<< (q + 1) << "\n" << ((r + 1)) << "\n";
	int RIDX = 0;
    int LIDX = 0;
    for (int i = p; i < r - p + 1; i++) {
        if (RIDX == n2) {
            A[i] = LA[LIDX];
            LIDX++;
        } else if (LIDX == n1) {
            A[i] = RA[RIDX];
            RIDX++;
        } else if (RA[RIDX] > LA[LIDX]) {
            A[i] = LA[LIDX];
            LIDX++;
        } else {
            A[i] = RA[RIDX];
            RIDX++;
        }
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

