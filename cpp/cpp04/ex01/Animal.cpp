#include "Animal.hpp"

Animal::Animal() : type_("") {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &animal) {
	*this = animal;
}

Animal &Animal::operator=(const Animal &animal) {
	type_ = animal.type_;
	return *this;
}

void Animal::makeSound() const {
	std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const {
	return type_;
}