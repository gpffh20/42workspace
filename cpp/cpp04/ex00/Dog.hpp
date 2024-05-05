#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
	Dog();
	~Dog();
	Dog(const Dog &dog);
	Dog &operator=(const Dog &dog);

	virtual void makeSound() const;
	virtual std::string getType() const;
private:
	std::string type_;
};

#endif
