#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource &materiaSource);
	MateriaSource &operator=(const MateriaSource &materiaSource);

	void learnMateria(AMateria *materia);
	AMateria *createMateria(const std::string &type);
private:
	AMateria *materias_[4];
};

#endif
