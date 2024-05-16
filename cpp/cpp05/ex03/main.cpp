#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	try {
		Intern intern;

		AForm *form1 = intern.makeForm("ShrubberyCreationForm", "target1");
		AForm *form2 = intern.makeForm("RobotomyRequestForm", "target2");
		AForm *form3 = intern.makeForm("PresidentialPardonForm", "target3");

		delete form1;
		delete form2;
		delete form3;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}