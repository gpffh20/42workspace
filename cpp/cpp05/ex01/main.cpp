#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
//		Bureaucrat bureaucrat1("Bureaucrat1", 1);
//		std::cout << bureaucrat1 << std::endl;
//		Form form1("Form1", 1, 1);
//		std::cout << form1 << std::endl;
//
//		bureaucrat1.signForm(form1);
//		std::cout << form1 << std::endl;

		Bureaucrat bureaucrat2("Bureaucrat2", 4);
		std::cout << bureaucrat2 << std::endl;
		Form form2("Form2", 1, 1);
		std::cout << form2 << std::endl;

		bureaucrat2.signForm(form2);
		std::cout << form2 << std::endl;
	}

	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}