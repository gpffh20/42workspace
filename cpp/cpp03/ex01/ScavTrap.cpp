#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->hit_points_ = 100;
	this->energy_points_ = 50;
	this->attack_damage_ = 20;
	std::cout << "ScavTrap " << name << " is born!" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name_ << " is destroyed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap) : ClapTrap(scavtrap) {
	*this = scavtrap;
	std::cout << "ScavTrap " << this->name_ << " is copied!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap) {
	if (this != &scavtrap) {
		ClapTrap::operator=(scavtrap);
		this->name_ = scavtrap.name_;
		this->hit_points_ = scavtrap.hit_points_;
		this->energy_points_ = scavtrap.energy_points_;
		this->attack_damage_ = scavtrap.attack_damage_;
	}
	std::cout << "ScavTrap " << this->name_ << " is assigned!" << std::endl;
	return (*this);
}

void ScavTrap::attack(std::string const &target) {
	if (this->energy_points_ < 1)
		std::cout << "ScavTrap " << this->name_ << " is out of energy!" << std::endl;
	else {
		this->energy_points_ -= 1;
		std::cout << "ScavTrap " << this->name_ << " attacks " << target << ", causing ";
		std::cout << this->attack_damage_ << " points of damage!" << std::endl;
	}
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->name_ << " is now in Gate keeper mode!" << std::endl;
}
