#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string const &name, int signGrade, int execGrade)
	: kName(name), isSigned_(false), kSignGrade(signGrade), kExecGrade(execGrade) {
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(AForm const &form)
	: kName(form.kName), isSigned_(form.isSigned_), kSignGrade(form.kSignGrade), kExecGrade(form.kExecGrade) {}

AForm &AForm::operator=(AForm const &form) {
	if (this != &form) {
		isSigned_ = form.isSigned_;
	}
	return *this;
}

std::string const &AForm::getName() const {
	return kName;
}

bool AForm::getIsSigned() const {
	return isSigned_;
}

int AForm::getSignGrade() const {
	return kSignGrade;
}

int AForm::getExecGrade() const {
	return kExecGrade;
}

void AForm::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > kSignGrade)
		throw AForm::GradeTooLowException();
	isSigned_ = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed";
}

std::ostream &operator<<(std::ostream &os, AForm const &form) {
	os << "Form " << form.getName() << " is ";
	if (!form.getIsSigned())
		os << "not ";
	os << "signed, sign grade is " << form.getSignGrade() << ", exec grade is " << form.getExecGrade();
	return os;
}