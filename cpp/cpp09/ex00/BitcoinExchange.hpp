#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <cstdlib>
#include <cctype>

class BitcoinExchange {
public:
	BitcoinExchange();
	~BitcoinExchange();

	void exchange(const std::string filename);
	void loadPrice(void);
	void loadTransactions(const std::string filename);

private:
	std::map<std::string, double> prices_;
	
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	
	bool isValidDate(const std::string date);
	bool isLeapYear(int year);
};

#endif
