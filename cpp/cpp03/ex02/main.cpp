#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	ClapTrap claptrap("Claptrap");
	ScavTrap scavtrap("Scavtrap");
	FragTrap fragtrap("Fragtrap");

	claptrap.attack("target");
	claptrap.takeDamage(5);
	claptrap.beRepaired(5);

	scavtrap.attack("target");
	scavtrap.guardGate();

	fragtrap.attack("target");
	fragtrap.highFivesGuys();

	return (0);
}