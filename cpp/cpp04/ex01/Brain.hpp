#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
public:
	Brain();
	~Brain();
	Brain(const Brain &brain);
	Brain &operator=(const Brain &brain);

	std::string getIdeas(int index) const;
	void setIdeas(int index, std::string idea);
private:
	std::string ideas_[100];
};

#endif
