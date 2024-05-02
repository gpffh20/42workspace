#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
public:
	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal(const WrongAnimal &wrongAnimal);
	WrongAnimal &operator=(const WrongAnimal &wrongAnimal);

	void makeSound() const;
	std::string getType() const;
protected:
	std::string type_;
};

#endif
