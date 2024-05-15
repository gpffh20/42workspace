#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : kName(name) {
	if (grade < 1) {
		throw GradeTooHighException();
	}
	else if (grade > 150) {
		throw GradeTooLowException();
	}
	grade_ = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : kName(bureaucrat.kName) {
	*this = bureaucrat;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
	grade_ = bureaucrat.grade_;
	return *this;
}

std::string Bureaucrat::getName() const {
	return kName;
}

int Bureaucrat::getGrade() const {
	return grade_;
}

void Bureaucrat::incrementGrade() {
	if (grade_ == 1) {
		throw GradeTooHighException();
	}
	grade_--;
}

void Bureaucrat::decrementGrade() {
	if (grade_ == 150) {
		throw GradeTooLowException();
	}
	grade_++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}