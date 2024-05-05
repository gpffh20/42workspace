#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
public:
	WrongAnimal();
	virtual ~WrongAnimal();
//	~WrongAnimal();
	WrongAnimal(const WrongAnimal &wrongAnimal);
	WrongAnimal &operator=(const WrongAnimal &wrongAnimal);

	virtual void makeSound() const;
	virtual std::string getType() const;
protected:
	std::string type_;
};

#endif
