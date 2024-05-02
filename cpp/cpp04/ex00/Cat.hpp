#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
public:
	Cat();
	~Cat();
	Cat(const Cat &cat);
	Cat &operator=(const Cat &cat);

	void makeSound() const;
	std::string getType() const;
private:
	std::string type_;
};

#endif
