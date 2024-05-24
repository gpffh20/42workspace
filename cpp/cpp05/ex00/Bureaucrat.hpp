#ifndef BUERAUCRAT_HPP
#define BUERAUCRAT_HPP

#include <iostream>

class Bureaucrat {
public:
	Bureaucrat(const std::string &name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &bureaucrat);

	const std::string &getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
private:
	Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &bureaucrat);

	const std::string kName;
	int grade_;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif