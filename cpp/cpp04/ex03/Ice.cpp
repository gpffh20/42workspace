#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

Ice::Ice(const Ice &ice) : AMateria(ice) {
	*this = ice;
}

Ice &Ice::operator=(const Ice &ice) {
	if (this != &ice) {
		AMateria::operator=(ice);
	}
	return *this;
}

AMateria *Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}