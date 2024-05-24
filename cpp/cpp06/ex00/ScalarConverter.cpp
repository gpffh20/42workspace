#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &input) {
	// Convert to double
	char *ptr = NULL;
	double value = std::strtod(input.c_str(), &ptr);
	
	if (ptr && *ptr) {
		// 남은 문자가 'f'이 아니고, 공백 또는 숫자 또는 부호 이외의 것인 경우
		bool invalidSuffix = std::strcmp(ptr, "f") != 0;
		for (char *check = ptr; *check; ++check) {
			if (!std::isspace(*check) && *check != 'f') {
				invalidSuffix = true;
				break;
			}
		}
		if (invalidSuffix) {
			std::cout << "Convert Failure: Invalid characters found after numeric input." << std::endl;
			return;
		}
	}
	
	// Print char
	std::cout << "char: ";
	if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max() || std::isnan(value)
			|| std::isinf(value))
		std::cout << "impossible" << std::endl;
	else if (std::isprint(static_cast<char>(value)))
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	
	// Print int
	std::cout << "int: ";
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() || std::isnan(value)
			|| std::isinf(value))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
	
	// Print float
	std::cout << "float: ";
	if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	
	// Print double
	std::cout << "double: ";
	std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}
