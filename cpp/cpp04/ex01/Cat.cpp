# include "Cat.hpp"

Cat::Cat() : Animal() {
	type_ = "Cat";
	brain_ = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
	delete brain_;
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat), type_(cat.type_), brain_(new Brain(*cat.brain_)) {}

Cat &Cat::operator=(const Cat &cat) {
    if (this != &cat) {
        type_ = cat.type_;
        *brain_ = *cat.brain_;
    }
    return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow meow" << std::endl;
}

std::string Cat::getType() const {
	return type_;
}

std::string Cat::getBrainIdeas(int index) const {
	if (brain_ != NULL && index >= 0 && index < 100) {
		return brain_->getIdeas(0);
	}
	return "Invalid index\n";
}

void Cat::setBrainIdeas(int index, std::string idea) {
	if (brain_ != NULL && index >= 0 && index < 100) {
		brain_->setIdeas(index, idea);
	}
}
