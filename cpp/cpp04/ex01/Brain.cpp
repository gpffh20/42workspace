#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain &brain) {
	*this = brain;
}

Brain &Brain::operator=(const Brain &brain) {
	if (this != &brain) {
		for (int i = 0; i < 100; i++) {
			ideas_[i] = brain.ideas_[i];
		}
	}
	return *this;
}

std::string Brain::getIdeas(int index) const {
	return ideas_[index];
}

void Brain::setIdeas(int index, std::string idea) {
	ideas_[index] = idea;
}