#include "FragTrap.hpp"

//FragTrap::FragTrap() : ClapTrap() {
//	std::cout << "FragTrap default constructor" << std::endl;
//}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->hit_points_ = 100;
	this->energy_points_ = 100;
	this->attack_damage_ = 30;
	std::cout << "FragTrap " << name << " is born!" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->name_ << " is destroyed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragtrap) : ClapTrap(fragtrap) {
	*this = fragtrap;
	std::cout << "FragTrap " << this->name_ << " is copied!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragtrap) {
	if (this != &fragtrap) {
		ClapTrap::operator=(fragtrap);
		this->name_ = fragtrap.name_;
		this->hit_points_ = fragtrap.hit_points_;
		this->energy_points_ = fragtrap.energy_points_;
		this->attack_damage_ = fragtrap.attack_damage_;
	}
	std::cout << "FragTrap " << this->name_ << " is assigned!" << std::endl;
	return (*this);
}

void FragTrap::attack(std::string const &target) {
	if (this->energy_points_ < 1)
		std::cout << "FragTrap " << this->name_ << " is out of energy!" << std::endl;
	else {
		this->energy_points_ -= 1;
		std::cout << "FragTrap " << this->name_ << " attacks " << target << ", causing ";
		std::cout << this->attack_damage_ << " points of damage!" << std::endl;
	}
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->name_ << " requests a high five!" << std::endl;
}