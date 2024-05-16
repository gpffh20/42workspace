#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &name)
	: AForm("ShrubberyCreationForm", 145, 137), kName(name) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &form)
	: AForm(form), kName(form.kName) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &form) {
	if (this != &form) {
		AForm::operator=(form);
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!getIsSigned()) {
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > getExecGrade()) {
		throw AForm::GradeTooLowException();
	}
	std::ofstream file(kName + "_shrubbery");
	if (!file.is_open()) {
		throw FileNotOpenedException();
	}
	file << "      /\\      " << std::endl;
	file << "     /\\*\\     " << std::endl;
	file << "    /\\O\\*\\    " << std::endl;
	file << "   /*/\\/\\/\\   " << std::endl;
	file << "  /\\O\\/\\*\\/\\  " << std::endl;
	file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
	file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;
	file << std::endl;
	file.close();
}

const char *ShrubberyCreationForm::FileNotOpenedException::what() const throw() {
	return "File not opened";
}
