#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm(const std::string &name);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &robotomyRequestForm);

	void execute(const Bureaucrat &executor) const;

private:
	RobotomyRequestForm();

	std::string const kName;
};

#endif
