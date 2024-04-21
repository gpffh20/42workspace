#include "Zombie.hpp"

int main() {
	Zombie zombie;
	zombie.set_name("Zombie");
	zombie.announce();

	Zombie* horde = zombieHorde(5, "Horde");
	delete[] horde;
	system("sleep 100000");
	return 0;
}