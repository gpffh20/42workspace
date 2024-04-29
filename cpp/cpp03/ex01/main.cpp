#include "ScavTrap.hpp"

int main() {
	ClapTrap claptrap("Claptrap");
	ScavTrap scavtrap("Scavtrap");

	claptrap.attack("target");
	claptrap.takeDamage(5);
	claptrap.beRepaired(5);

	scavtrap.attack("target");
	scavtrap.guardGate();

	return (0);
}