#include "Cat.hpp"
#include "Dog.hpp"

int main() {
//	AAnimal a1;
    std::cout << '\n';
    Cat c1;
    c1.setBrainIdeas(0, "test");
	Cat c2(c1);
    std::cout << '\n';
	std::cout << c1.getBrainIdeas(0) << std::endl;
    std::cout << c2.getBrainIdeas(0) << std::endl;
    c2.setBrainIdeas(0, "test2");
    std::cout << c2.getBrainIdeas(0) << std::endl;
    std::cout << '\n';

	c1.makeSound();
    std::cout << '\n';

    return 0;
}