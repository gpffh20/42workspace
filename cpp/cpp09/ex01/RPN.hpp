#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cctype>
#include <stdexcept>

class RPN {
public:
	RPN();
	~RPN();

	void calculate(const std::string expression);
	
private:
	std::stack<double> stack_;
	
	RPN(const RPN& origin);
	RPN& operator=(const RPN& origin);
	
	bool processToken(const std::string &token, std::stack<double> &stack);
	bool isValidNumber(const std::string &token);
	double stringToDouble(const std::string& str);
};

#endif
