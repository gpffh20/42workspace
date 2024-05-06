#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type_("") {
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal) {
	*this = wrongAnimal;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wrongAnimal) {
	type_ = wrongAnimal.type_;
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal sound!!!!!" << std::endl;
}

std::string WrongAnimal::getType() const {
	return type_;
}