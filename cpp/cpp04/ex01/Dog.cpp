#include "Dog.hpp"

Dog::Dog() : Animal() {
	type_ = "Dog";
	brain_ = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal(dog), type_(dog.type_), brain_(new Brain(*dog.brain_)) {}

Dog &Dog::operator=(const Dog &dog) {
    if (this != &dog) {
        Animal::operator=(dog);
        type_ = dog.type_;
        *brain_ = *dog.brain_;
    }
    return *this;
}

void Dog::makeSound() const {
	std::cout << "Bark bark" << std::endl;
}

std::string Dog::getType() const {
	return type_;
}

std::string Dog::getBrainIdeas(int index) const {
	if (brain_ != NULL && index >= 0 && index < 100) {
		return brain_->getIdeas(index);
	}
	return "Invalid index\n";
}

void Dog::setBrainIdeas(int index, std::string idea) {
	if (brain_ != NULL && index >= 0 && index < 100) {
		brain_->setIdeas(index, idea);
	}
}