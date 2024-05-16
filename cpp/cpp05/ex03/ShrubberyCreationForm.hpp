#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
  public:
	ShrubberyCreationForm(std::string const &name);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const &form);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &form);

	void execute(Bureaucrat const &executor) const;

	class FileNotOpenedException : public std::exception {
	  public:
		virtual const char *what() const throw();
	};

  private:
	ShrubberyCreationForm();

	std::string const kName;
};

#endif
