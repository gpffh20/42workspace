#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	try {
		Bureaucrat bureaucrat("Bureaucrat", 1);

		// test for ShrubberyCreationForm
		ShrubberyCreationForm sform("SFrom");

		sform.beSigned(bureaucrat);
		bureaucrat.executeForm(sform);

		// test for RobotomyRequestForm
		RobotomyRequestForm rform("RFrom");

		rform.beSigned(bureaucrat);
		bureaucrat.executeForm(rform);
		bureaucrat.executeForm(rform);
		bureaucrat.executeForm(rform);
		bureaucrat.executeForm(rform);

		// test for PresidentialPardonForm
		PresidentialPardonForm pform("PFrom");

		pform.beSigned(bureaucrat);
		bureaucrat.executeForm(pform);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}