#include "BitcoinExchange.hpp"
#include <iostream>

int main(int arg_num, char **args) {
	
	if (arg_num != 2) {
		std::cout << "Invalid number of arguments\n";
		return 1;
	}

	MyFile file(args[1]);
	MyFile file2("../data.csv");

	BitcoinExchange exchange;
	exchange.extract_data(file2);
	// exchange.print_csv_data();
	std::string line;
	unsigned long i = 0;
	while ((line = file.getLine()) != "") {
		// std::cout << line << "\n";
		if(i == 0)
		{
			if(line != "date | value")
			{
				std::cout << "Invalid input\n";
				return 1;
			}
			i++;
			continue;
		}

		if(checkInput(line, '|', 1000, 0) == false)
		{
			// std::cout << "Invalid input\n";
			i++;
			continue;
		}
		Unit input = ParseInput(line, '|');
		Unit result = exchange.search_for_date_and_value(input);
		if (result.getDate()[0] == 0)
			std::cout << "No data found\n";
		else
			std::cout << input.getDate()[0] << "-" << input.getDate()[1] 
			<< "-" << input.getDate()[2] << " => " << input.getValue() 
			<< " = " << result.getValue() * input.getValue() << "\n";
		i++;
	}
	file.close();
	return 0;
}