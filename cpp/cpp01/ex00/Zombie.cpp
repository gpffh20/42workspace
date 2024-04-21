#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie() {
	std::cout << "Zombie(";
	std::cout << this->name << ") is destroyed." << std::endl;
}

void Zombie::set_name(std::string name) {
	this->name = name;
}
void Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
