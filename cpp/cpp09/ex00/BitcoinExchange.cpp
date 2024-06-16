#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::exchange(const std::string filename) {
	loadPrice();
	loadTransactions(filename);
}

void BitcoinExchange::loadPrice(void) {
	std::ifstream csv("data.csv");
	if (!csv.is_open()) {
		std::cerr << "Error: could not open data file." << std::endl;
		return ;
	}
	std::string line;
	std::getline(csv, line);
	while (std::getline(csv, line)) {
		std::string date = line.substr(0, line.find(","));
		double price = stringToDouble(line.substr(line.find(",") + 1));
		prices_[date] = price;
	}
	csv.close();
}

void BitcoinExchange::loadTransactions(const std::string filename) {
	std::ifstream input(filename.c_str());
	if (!input.is_open()) {
		std::cerr << "Error: could not open input file." << std::endl;
		return ;
	}
	std::string line;
	std::getline(input, line);
	while (std::getline(input, line)) {
		std::string date = line.substr(0, line.find(" | "));
		if (line.length() <= 13 || !isValidDate(date)) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		double value = stringToDouble(line.substr(line.find("|") + 2));
		if (value < 0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000) {
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		std::map<std::string, double>::iterator iter = this->prices_.upper_bound(date);
		if (iter == this->prices_.begin())
			throw std::logic_error("Error: no data in database");
		std::cout << date << " => " << value << " = " << value * (--iter)->second << std::endl;
	}
	input.close();
}

double BitcoinExchange::stringToDouble(const std::string& str) {
	std::istringstream iss(str);
	double value;
 	if (!(iss >> value)) {
        throw std::runtime_error("Error: Conversion to double failed.");
    }
    return value;
}

bool BitcoinExchange::isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidDate(const std::string date) {
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    for (int i = 0; i < 4; i++) {
        if (!isdigit(yearStr[i]))
            return false;
    }
    for (int i = 0; i < 2; i++) {
        if (!isdigit(monthStr[i]) || !isdigit(dayStr[i]))
            return false;
    }

    int year = atoi(yearStr.c_str());
    int month = atoi(monthStr.c_str());
    int day = atoi(dayStr.c_str());

    if (year < 2009 || year > 2024)
        return false;
    if (year == 2009 && (month < 1 || (month == 1 && day < 1)))
        return false;
    if (year == 2024 && (month > 6 || (month == 6 && day > 16)))
        return false;
	
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }

    if (month < 1 || month > 12 || day < 1 || day > daysInMonth[month - 1])
        return false;

    return true;
}