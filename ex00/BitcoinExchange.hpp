#pragma once
#include <fstream>
#include <list>
#include <string>

class MyFile {
	public:
	MyFile(std::string const &filename);
	MyFile(MyFile const &other);
	MyFile &operator=(MyFile const &other);
	~MyFile();
	
	std::ifstream &getStream();
	std::string getLine();
	void close();
	
	private:
	std::ifstream file;
};

class Unit{
	public:
	Unit();
	Unit(Unit const &other);
	Unit &operator=(Unit const &other);
	~Unit();
	long *getDate();
	double &getValue();

	private:
	long date[3];
	double value;
};


class BitcoinExchange {
	public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &other);
	BitcoinExchange &operator=(BitcoinExchange const &other);
	~BitcoinExchange();
	void extract_data(MyFile &file);
	Unit search_for_date_and_value(Unit input);
	void print_csv_data();
	private:
	std::list<Unit> csv_data;
};

bool checkInput(std::string const &line, const char separator, long long max, long long min);
Unit ParseInput(std::string const &line, const char separator);