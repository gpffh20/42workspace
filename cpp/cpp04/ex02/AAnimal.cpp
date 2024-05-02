#include "AAnimal.hpp"

AAnimal::AAnimal() : type_("") {
	std::cout << "Animal constructor called" << std::endl;
}

AAnimal::~AAnimal() {
	std::cout << "Animal destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &animal) {
	*this = animal;
}

AAnimal &AAnimal::operator=(const AAnimal &animal) {
	type_ = animal.type_;
	return *this;
}

std::string AAnimal::getType() const {
	return type_;
}