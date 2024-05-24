#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm {
	public:
	AForm(std::string const &name, int signGrade, int execGrade);
	virtual ~AForm();
	AForm(AForm const &form);
	AForm &operator=(AForm const &form);

	std::string const &getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;

	void beSigned(Bureaucrat const &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const;

	class GradeTooHighException : public std::exception {
	  public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	  public:
		virtual const char *what() const throw();
	};

	class FormNotSignedException : public std::exception {
	  public:
		virtual const char *what() const throw();
	};

  private:
	AForm();

	std::string const kName;
	bool isSigned_;
	int const kSignGrade;
	int const kExecGrade;
};

std::ostream &operator<<(std::ostream &os, AForm const &form);

#endif
