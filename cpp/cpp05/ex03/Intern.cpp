#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &intern) {
	*this = intern;
}

Intern &Intern::operator=(const Intern &intern) {
	(void)intern;
	return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const {
	std::string const form_types[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	for (int i = 0; i < 3; i++) {
		if (formName == form_types[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			switch (i) {
				case 0:
					return new ShrubberyCreationForm(target);
				case 1:
					return new RobotomyRequestForm(target);
				case 2:
					return new PresidentialPardonForm(target);
			}
		}
	}
	throw FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw() {
	return "Form not found";
}