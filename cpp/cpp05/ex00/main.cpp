#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat b("John", 1);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;

		Bureaucrat b2("Jane", 150);
		std::cout << b2 << std::endl;
		b2.decrementGrade();
		std::cout << b2 << std::endl;

		Bureaucrat b3("Jack", 151);
		std::cout << b3 << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}