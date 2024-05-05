#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	WrongCat();
	~WrongCat();
	WrongCat(const WrongCat &wrongCat);
	WrongCat &operator=(const WrongCat &wrongCat);

	virtual void makeSound() const;
	virtual std::string getType() const;
protected:
	std::string type_;
};

#endif
