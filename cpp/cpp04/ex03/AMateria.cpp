#include "AMateria.hpp"

AMateria::AMateria(const std::string &type) : type_(type) {}

AMateria::~AMateria() {}

AMateria::AMateria(const AMateria &materia) {
	*this = materia;
}

AMateria &AMateria::operator=(const AMateria &materia) {
	if (this != &materia) {
		type_ = materia.type_;
	}
	return *this;
}

const std::string &AMateria::getType() const {
	return type_;
}

void AMateria::use(ICharacter &target) {
	(void)target;
}