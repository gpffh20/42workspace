#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
public:
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &bureaucrat);
	Bureaucrat &operator=(const Bureaucrat &bureaucrat);

	std::string getName() const;
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
	const std::string kName;
	int grade_;
};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
