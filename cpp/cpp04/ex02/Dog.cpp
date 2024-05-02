#include "Dog.hpp"

Dog::Dog() : AAnimal() {
	type_ = "Dog";
	brain_ = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &dog) {
	*this = dog;
}

Dog &Dog::operator=(const Dog &dog) {
	type_ = dog.type_;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Bark bark" << std::endl;
}

std::string Dog::getType() const {
	return type_;
}