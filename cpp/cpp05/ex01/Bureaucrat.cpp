#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : kName(name) {
	if (grade < 1) {
		throw GradeTooHighException();
	}
	if (grade > 150) {
		throw GradeTooLowException();
	}
	grade_ = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : kName(bureaucrat.kName) {
	*this = bureaucrat;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
	if (this != &bureaucrat) {
		grade_ = bureaucrat.grade_;
	}
	return *this;
}

const std::string &Bureaucrat::getName() const {
	return kName;
}

int Bureaucrat::getGrade() const {
	return grade_;
}

void Bureaucrat::incrementGrade() {
	if (grade_ <= 1) {
		throw GradeTooHighException();
	}
	grade_--;
}

void Bureaucrat::decrementGrade() {
	if (grade_ >= 150) {
		throw GradeTooLowException();
	}
	grade_++;
}

void Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout << this->kName << " signed " << form.getName() << std::endl;
	} catch (const std::exception &e) {
		std::cout << this->kName << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}