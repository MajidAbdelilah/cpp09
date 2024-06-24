#include "BitcoinExchange.hpp"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <limits>

MyFile::MyFile(std::string const &filename) : file(filename.c_str(), std::ios::in) {
	if (!file.is_open()) {
		std::cerr << "Error: " << filename << " could not be opened." << std::endl;
		exit(1);
	}
}

MyFile::MyFile(MyFile const &other) {
	(void)other;
}

MyFile &MyFile::operator=(MyFile const &other) {
	(void)other;
	return *this;
}

MyFile::~MyFile() {
	file.close();
}

std::ifstream &MyFile::getStream() {
	return file;
}

void MyFile::close() {
	file.close();
}

std::string MyFile::getLine() {
	std::string line;
	std::getline(file, line);
	return line;
}

bool isLeap(int year) 
{ 
return (((year % 4 == 0) &&  
         (year % 100 != 0)) || 
         (year % 400 == 0)); 
} 



bool isValidDate(long long  d, long long m, long long y) 
{ 
    if (y > 2023 ||  
        y < 2008) 
    	return false; 
    if (m < 1 || m > 12) 
    	return false; 
    if (d < 1 || d > 31) 
    	return false; 
  
    if (m == 2) 
    { 
        if (isLeap(y)) 
        return (d <= 29); 
        else
        return (d <= 28); 
    }

    if (m == 4 || m == 6 || 
        m == 9 || m == 11) 
        return (d <= 30); 
  
    return true; 
} 

bool checkInput(std::string const &line, const char separator, long long max, long long min) {
	if (line.empty()) {
		return false;
	}
	unsigned long i = 0;
	long long date[3];
	int j = 0;
	while(i < line.size() && std::isdigit(line[i]) && j < 3) {
		std::string tmp;
		while ((std::isdigit(line[i])) && i < line.size()) {
			tmp += line[i];
			i++;
		}
		// std::cout << tmp << "\n";
		long long res = strtoll(tmp.c_str(), NULL, 10);
		if(res < std::numeric_limits<int>::min() || res > std::numeric_limits<int>::max() || tmp.size() > 10) {
			std::cerr << "Error: " << tmp << " is not a valid integer." << std::endl;
			return false;
		}
		date[j++] = res;
		i++;
	}

	if(isValidDate(date[2], date[1], date[0]) == false)
	{
		std::cerr << "Error: date is not valid" << std::endl;
		return false;
	}

	while (std::isspace(line[i]) || line[i] == separator) {
		i++;
	}

	if(std::isdigit(line[i]) == false)
	{
		std::cerr << "Error: number is not valid" << std::endl;
		return false;
	}

	std::string value(line.c_str() + i);
	if (value.empty()) {
		std::cerr << "Error: number is not valid" << std::endl;
		return false;
	}

	i = 0;
	while(std::isspace(value[i]) == false && i < value.size()) {
		if (!std::isdigit(value[i]) && value[i] != '.') {
			std::cerr << "Error: number is not valid" << std::endl;
			return false;
		}
		i++;
	}

	value.resize(i);

	double res = strtod(value.c_str(), NULL);
	if( res != 0 && (res < std::numeric_limits<float>::min() || res > std::numeric_limits<float>::max()
		|| res < min || res > max || value.size() > 10)){
		std::cerr << "Error: "<< value << " : " << res <<" is not valid" << std::endl;
		return false;
	}

	return true;
}


Unit::Unit() {
	date[0] = 0;
	date[1] = 0;
	date[2] = 0;
	value = 0;
}

Unit::Unit(Unit const &other) {
	*this = other;
}

Unit &Unit::operator=(Unit const &other) {
	date[0] = other.date[0];
	date[1] = other.date[1];
	date[2] = other.date[2];
	value = other.value;
	return *this;
}

Unit::~Unit() {
}

long *Unit::getDate() {
	return date;
}

double &Unit::getValue() {
	return value;
}

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other) {
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other) {
	csv_data = other.csv_data;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {
}

void BitcoinExchange::extract_data(MyFile &file) {
	std::string line;
	unsigned long i = 0;
	while ((line = file.getLine()) != "") {
		if(i == 0)
		{
			if(line != "date,exchange_rate")
			{
				std::cerr << "Invalid input" << std::endl;
				exit(1);
			}
			i++;
			continue;
		}
		// std::cout << line << "\n";
		if(checkInput(line, ',', 5000000000, 0) == false)
		{
			std::cerr << "Invalid input" << std::endl;
			exit(1);
		}
		Unit unit;
		unsigned long j = 0;
		int a = 0;
		while(j < line.size() && std::isdigit(line[j]) && a < 3) {
			std::string tmp;
			while ((std::isdigit(line[j])) && j < line.size()) {
				tmp += line[j];
				j++;
			}
			long long res = strtoll(tmp.c_str(), NULL, 10);
			// std::cout << a << "\n";
			unit.getDate()[a] = res;
			a++;
			j++;
		}
		while (std::isspace(line[j]) || line[j] == ',') {
			j++;
		}
		std::string value(line.c_str() + j);
		unit.getValue() = strtod(value.c_str(), NULL);
		csv_data.push_back(unit);
		i++;
	}
}

void BitcoinExchange::print_csv_data() {
	for (std::list<Unit>::iterator it = csv_data.begin(); it != csv_data.end(); it++) {
		long *date = it->getDate();
		std::cout << date[0] << "/" << date[1] << "/" << date[2] << " " << it->getValue() << std::endl;
	}
}

Unit ParseInput(std::string const &line, const char separator) {
	Unit unit;
	unsigned long i = 0;
	int j = 0;
	while(i < line.size() && std::isdigit(line[i]) && j < 3) {
		std::string tmp;
		while ((std::isdigit(line[i])) && i < line.size()) {
			tmp += line[i];
			i++;
		}
		long long res = strtoll(tmp.c_str(), NULL, 10);
		unit.getDate()[j++] = res;
		i++;
	}
	while (std::isspace(line[i]) || line[i] == separator) {
		i++;
	}
	std::string value(line.c_str() + i);
	unit.getValue() = strtod(value.c_str(), NULL);
	return unit;
}

Unit BitcoinExchange::search_for_date_and_value(Unit input) {
	std::list<Unit>::iterator b = csv_data.begin();
	std::list<Unit>::iterator b_next = ++csv_data.begin();
	std::list<Unit>::iterator e = csv_data.end();
	
	long *input_date = input.getDate();
	long *date = b->getDate();
	// long *date_next = b_next->getDate();

	if(input_date[0] >= date[0])
	{
		if(input_date[1] >= date[1])
		{
			if(input_date[2] >= date[2])
			{
			}else
				return *b;
		}else
			return *b;
	}else
		return *b;
	e--;
	if(input_date[0] <= e->getDate()[0])
	{
		if(input_date[1] <= e->getDate()[1])
		{
			if(input_date[2] <= e->getDate()[2])
			{
			}else
				return *e;
		}else
			return *e;
	}else
		return *e;

	while(b_next != e)
	{
		long *date = b->getDate();
		long *date_next = b_next->getDate();
		if(input_date[0] == date[0])
		{
			if(input_date[1] == date[1])
			{
				if(input_date[2] == date[2])
				{
					return *b;
				}

				if((input_date[2] + input_date[1] * 30) > (date[2] + date[1] * 30)
					&& (input_date[2] + input_date[1] * 30) < (date_next[2] + date_next[1] * 30))
				{
					return *b_next;
				}
			}
		}
		b++;
		b_next++;
	}
	
	date = b->getDate();
	// date_next = b_next->getDate();
		
	if(input_date[0] == date[0])
	{
		if(input_date[1] == date[1])
		{
			if(input_date[2] == date[2])
			{
				return *b;
			}
		}
	}
	return Unit();
}
