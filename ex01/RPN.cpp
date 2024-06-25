#include "RPN.hpp"
#include <cctype>
#include <limits>
#include <stdexcept>
#include <stdlib.h>


long long get_number(std::string str)
{
	// std::cout << str << "\n";
	unsigned long i = 0;
	if(str[i] == '-' || str[i] == '+')
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
long long eval(std::stack<std::string>& arr)
{
	if(arr.empty())
		throw std::invalid_argument("Empty stack");
    std::stack<long long> st;
    while(!arr.empty()) {
		std::string str = arr.top();
		arr.pop();
        if (str != "+" && str != "-" && str != "/"
            && str != "*") {
            st.push(get_number(str));
            continue;
        }
        else {
			if(st.empty())
				throw std::invalid_argument("invalid input");
            long long b = st.top();
            st.pop();
			if(st.empty())
				throw std::invalid_argument("invalid input");
            long long a = st.top();
            st.pop();
            if (str == "+")
                st.push(a + b);
            else if (str == "-")
                st.push(a - b);
            else if (str == "*")
                st.push(a * b);
            else if(str == "/")
                st.push(a / b);
			if(st.top() < std::numeric_limits<int>::min() || st.top() > std::numeric_limits<int>::max())
				throw std::invalid_argument("Error: internal over/under flow.");
        }
		// std::cout << "here\n";
    }
	if(st.empty())
		throw std::out_of_range("error: internal stack is empty");
    if(st.size() != 1)
		throw std::invalid_argument("invalid input");
	return st.top();
}

