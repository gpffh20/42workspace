#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {
public:
	AAnimal();
	virtual ~AAnimal();
	AAnimal(const AAnimal &animal);
	AAnimal &operator=(const AAnimal &animal);

	virtual void makeSound() const = 0;
	virtual std::string getType() const;
protected:
	std::string type_;
};

#endif