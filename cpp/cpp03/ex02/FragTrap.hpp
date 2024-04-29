#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
private:
	FragTrap();
public:
	FragTrap(std::string name);
	~FragTrap();
	FragTrap(const FragTrap &fragtrap);
	FragTrap &operator=(const FragTrap &fragtrap);

	void attack(std::string const &target);
	void highFivesGuys();
};

#endif
