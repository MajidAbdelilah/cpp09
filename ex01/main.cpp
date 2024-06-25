#include "RPN.hpp"
#include <iostream>
#include <stack>
#include <cstring>
int main(int arg_num, char **args)
{

    std::stack<std::string> A;

    // char arr[][10]    = { "10", "6", "9",  "3", "+", "-11", "*",
    //         "/",  "*", "17", "+", "5", "+" };
	
	for (long i = 1; i < arg_num; i++)
	{
		char *ptr; 
		ptr = strtok(args[i], " ");  
		while (ptr != NULL)  
		{  
			A.push(ptr);
			ptr = strtok (NULL, " ");  
		}
	}
    std::stack<std::string> A2;

	while(!A.empty())
	{
		A2.push(A.top());
		A.pop();
	}

	try {
    	long long res = eval(A2);
    	std::cout << res << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}