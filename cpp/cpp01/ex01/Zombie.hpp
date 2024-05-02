#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
public:
	Zombie();
	~Zombie();

	void announce();
	void set_name(std::string name);
private:
	std::string name_;
};

Zombie* zombieHorde(int N, std::string name);

#endif
