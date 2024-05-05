#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
public:
	Cat();
	~Cat();
	Cat(const Cat &cat);
	Cat &operator=(const Cat &cat);

	virtual void makeSound() const;
	virtual std::string getType() const;
private:
	std::string type_;
};

#endif
