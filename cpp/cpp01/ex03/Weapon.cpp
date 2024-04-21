#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type_(type) {}

Weapon::~Weapon() {}

const std::string& Weapon::getType() const {
	return type_;
}

void Weapon::setType(std::string type) {
	type_ = type;
}