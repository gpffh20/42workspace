#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &name)
	: AForm("RobotomyRequestForm", 72, 45), kName(name) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm)
	: AForm("RobotomyRequestForm", 72, 45), kName(robotomyRequestForm.kName) {
	*this = robotomyRequestForm;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &robotomyRequestForm) {
	if (this != &robotomyRequestForm) {
		AForm::operator=(robotomyRequestForm);
	}
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (!getIsSigned()) {
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > getExecGrade()) {
		throw AForm::GradeTooLowException();
	}
	std::cout << "*drilling noises* " << std::endl;
	if (rand() % 2 == 0) {
		std::cout << kName << " has been robotomized successfully" << std::endl;
	} else {
		std::cout << kName << " robotomization failed" << std::endl;
	}
}