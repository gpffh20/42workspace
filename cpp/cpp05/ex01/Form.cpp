#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string const &name, int signGrade, int execGrade)
	: kName(name), isSigned_(false), kSignGrade(signGrade), kExecGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::~Form() {}

Form::Form(Form const &form)
	: kName(form.kName), isSigned_(form.isSigned_), kSignGrade(form.kSignGrade), kExecGrade(form.kExecGrade) {}

Form &Form::operator=(Form const &form) {
	if (this != &form) {
		isSigned_ = form.isSigned_;
	}
	return *this;
}

std::string const &Form::getName() const {
	return kName;
}

bool Form::getIsSigned() const {
	return isSigned_;
}

int Form::getSignGrade() const {
	return kSignGrade;
}

int Form::getExecGrade() const {
	return kExecGrade;
}

void Form::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > kSignGrade)
		throw Form::GradeTooLowException();
	isSigned_ = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, Form const &form) {
	os << "Form " << form.getName() << " is ";
	if (!form.getIsSigned())
		os << "not ";
	os << "signed, sign grade is " << form.getSignGrade() << ", exec grade is " << form.getExecGrade();
	return os;
}