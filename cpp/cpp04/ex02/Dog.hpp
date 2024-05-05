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

	virtual void makeSound() const;
	virtual std::string getType() const;
	std::string getBrainIdeas(int index) const;
	void setBrainIdeas(int index, std::string idea);
private:
	std::string type_;
	Brain *brain_;
};

#endif
