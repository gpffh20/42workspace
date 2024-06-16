#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <stdexcept>
#include <map>

class BitcoinExchange {
public:
	BitcoinExchange();
	~BitcoinExchange();

	void exchange(const std::string filename);
	

private:
	std::map<std::string, double> prices_;
	
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	
	void loadPrice(void);
	void loadTransactions(const std::string filename);
	
	double stringToDouble(const std::string& str);
	bool isLeapYear(int year);
	bool isValidDate(const std::string date);
};

#endif
