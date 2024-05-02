#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
public:
	Cat();
	~Cat();
	Cat(const Cat &cat);
	Cat &operator=(const Cat &cat);

	void makeSound() const;
	std::string getType() const;
private:
	std::string type_;
	Brain *brain_;
};

#endif
