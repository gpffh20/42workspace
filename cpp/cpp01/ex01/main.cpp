#include "Zombie.hpp"

int main() {
	Zombie zombie;
	zombie.set_name("Zombie");
	zombie.announce();

	Zombie* horde = zombieHorde(5, "Horde");
	delete[] horde;
	return 0;
}