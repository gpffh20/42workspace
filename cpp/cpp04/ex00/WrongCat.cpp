#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type_ = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat) {
	*this = wrongCat;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongCat) {
	type_ = wrongCat.type_;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "Wrong Animal Sound" << std::endl;
}

std::string WrongCat::getType() const {
	return type_;
}