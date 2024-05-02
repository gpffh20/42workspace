#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    const int size = 10;
    AAnimal* animals[size];

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
