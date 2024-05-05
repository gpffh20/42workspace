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

	virtual void makeSound() const;
	virtual std::string getType() const;
	std::string getBrainIdeas(int index) const;
	void setBrainIdeas(int index, std::string idea);
private:
	std::string type_;
	Brain *brain_;
};

#endif
