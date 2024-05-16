#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm(const std::string &name);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &presidentialPardonForm);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &presidentialPardonForm);

	void execute(const Bureaucrat &executor) const;

private:
	PresidentialPardonForm();

	std::string const kName;
};

#endif
