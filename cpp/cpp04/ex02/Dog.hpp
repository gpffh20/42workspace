#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
public:
	Dog();
	~Dog();
	Dog(const Dog &dog);
	Dog &operator=(const Dog &dog);

	void makeSound() const;
	std::string getType() const;
private:
	std::string type_;
	Brain *brain_;
};

#endif
