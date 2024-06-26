# include "Cat.hpp"

Cat::Cat() : Animal() {
	type_ = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat){
	*this = cat;
}

Cat &Cat::operator=(const Cat &cat) {
	type_ = cat.type_;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow meow" << std::endl;
}

std::string Cat::getType() const {
	return type_;
}
