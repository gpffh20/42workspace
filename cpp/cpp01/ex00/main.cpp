#include "Zombie.hpp"

int main() {
	Zombie zombie;
	zombie.set_name("Zombie");
	zombie.announce();

	Zombie *zombie2 = newZombie("Zombie2");
	zombie2->announce();
	delete zombie2;

	randomChump("Zombie3");
	return 0;
}