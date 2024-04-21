#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie() {
	std::cout << this->name_ << " is dead." << std::endl;
}

void Zombie::set_name(std::string name) {
	this->name_ = name;
}
void Zombie::announce() {
	std::cout << this->name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
