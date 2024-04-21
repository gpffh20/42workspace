#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie() {}

void Zombie::set_name(std::string name) {
	this->name = name;
}
void Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
