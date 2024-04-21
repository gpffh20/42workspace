#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name_(name), weapon_(nullptr) {}

HumanB::~HumanB() {}

void HumanB::attack() {
	if (weapon_ != nullptr)
		std::cout << name_ << " attacks with their " << weapon_->getType() << std::endl;
	else
		std::cout << name_ << " attacks unarmed" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon) {
	weapon_ = &weapon;
}