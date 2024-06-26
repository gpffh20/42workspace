#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap(const ScavTrap &scavtrap);
	ScavTrap &operator=(const ScavTrap &scavtrap);

	virtual void attack(std::string const &target);
	void guardGate();
private:
	ScavTrap();
};

#endif
