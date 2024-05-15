#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form {
	public:
	Form(std::string const &name, int signGrade, int execGrade);
	~Form();
	Form(Form const &src);
	Form &operator=(Form const &rhs);

	std::string const &getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;

	void beSigned(Bureaucrat const &bureaucrat);

	class GradeTooHighException : public std::exception {
	  public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	  public:
		virtual const char *what() const throw();
	};

  private:
	Form();

	std::string const kName;
	bool isSigned_;
	int const kSignGrade;
	int const kExecGrade;
};

std::ostream &operator<<(std::ostream &os, Form const &form);

#endif
