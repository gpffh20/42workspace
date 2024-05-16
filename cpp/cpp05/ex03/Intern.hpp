#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
  public:
	Intern();
	~Intern();
	Intern(Intern const &intern);
	Intern &operator=(Intern const &intern);

	AForm *makeForm(std::string const &formName, std::string const &target) const;

	class FormNotFoundException : public std::exception {
	  public:
		virtual const char *what() const throw();
	};
};

#endif
