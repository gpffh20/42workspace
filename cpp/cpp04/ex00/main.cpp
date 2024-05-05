#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal *meta = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();
	const WrongAnimal *wrong_cat = new WrongCat();

	std::cout << "\n";
	std::cout << dog->getType() << " " << std::endl;
	dog->makeSound();
	std::cout << "\n";
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();
	std::cout << "\n";
	std::cout << wrong_cat->getType() << " " << std::endl;
	wrong_cat->makeSound();
	std::cout << "\n";

	delete meta;
	delete dog;
	delete cat;
	delete wrong_cat;

	return 0;
}