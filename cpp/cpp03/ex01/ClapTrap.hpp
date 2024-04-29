#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
private:
	ClapTrap();
protected:
	std::string name_;
	int hit_points_;
	int energy_points_;
	int attack_damage_;
public:
	ClapTrap(std::string name);
	virtual ~ClapTrap();
	ClapTrap(const ClapTrap &claptrap);
	ClapTrap &operator=(const ClapTrap &claptrap);

	virtual void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
