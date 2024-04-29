#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	this->hit_points_ = 10;
	this->energy_points_ = 10;
	this->attack_damage_ = 0;
	std::cout << "ClapTrap is created!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name_(name) {
	this->hit_points_ = 10;
	this->energy_points_ = 10;
	this->attack_damage_ = 0;
	std::cout << "ClapTrap " << this->name_ << " is created!" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->name_ << " is destroyed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap) {
	*this = claptrap;
	std::cout << "ClapTrap " << this->name_ << " is copied!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap) {
	this->name_ = claptrap.name_;
	this->hit_points_ = claptrap.hit_points_;
	this->energy_points_ = claptrap.energy_points_;
	this->attack_damage_ = claptrap.attack_damage_;
	std::cout << "ClapTrap " << this->name_ << " is assigned!" << std::endl;
	return (*this);
}

void ClapTrap::attack(std::string const &target) {
	if (this->energy_points_ < 1)
		std::cout << "ClapTrap " << this->name_ << " is out of energy!" << std::endl;
	else {
		this->energy_points_ -= 1;
		std::cout << "ClapTrap " << this->name_ << " attacks " << target << ", causing ";
		std::cout << this->attack_damage_ << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hit_points_ < 1)
		std::cout << "ClapTrap " << this->name_ << " is already dead!" << std::endl;
	else {
		this->hit_points_ -= amount;
		if (this->hit_points_ < 0)
			this->hit_points_ = 0;
		std::cout << "ClapTrap " << this->name_ << " takes " << amount << " points of damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energy_points_ < 1)
		std::cout << "ClapTrap " << this->name_ << " is out of energy!" << std::endl;
	else {
		this->hit_points_ += amount;
		this->energy_points_ -= 1;
		std::cout << "ClapTrap " << this->name_ << " is repaired for " << amount << " points!" << std::endl;
	}
}