#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &name)
	: AForm(name, 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &form)
	: AForm(form), kName(form.kName) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &presidentialPardonForm) {
	if (this != &presidentialPardonForm) {
		AForm::operator=(presidentialPardonForm);
	}
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	AForm::execute(executor);
	std::cout << getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}