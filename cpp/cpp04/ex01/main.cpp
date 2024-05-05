#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    const int size = 10;
    Animal* animals[size];
    std::cout << '\n';
    Cat c1;
    c1.setBrainIdeas(0, "test");
	Cat c2(c1);
    std::cout << '\n';
	std::cout << c1.getBrainIdeas(0) << '\n';
    std::cout << c2.getBrainIdeas(0);
    std::cout << '\n';

    for (int i = 0; i < size / 2; i++) {
        animals[i] = new Dog();
    }

    for (int i = size / 2; i < size; i++) {
        animals[i] = new Cat();
    }

    for (int i = 0; i < size; i++) {
        delete animals[i];
    }

    return 0;
}