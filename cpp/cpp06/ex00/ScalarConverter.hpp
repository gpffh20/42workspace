#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <limits>
#include <cctype>
#include <iomanip>
#include <cstring>
#include <cmath>

class ScalarConverter {
  public:
	static void convert(const std::string& input);
	
  private:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(ScalarConverter const &scalarConverter);
	ScalarConverter &operator=(ScalarConverter const &scalarConverter);
};

#endif
