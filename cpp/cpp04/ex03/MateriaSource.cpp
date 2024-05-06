#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++) {
		this->materias_[i] = NULL;
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (this->materias_[i]) {
			delete this->materias_[i];
			this->materias_[i] = NULL;
		}
	}
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource) {
	*this = materiaSource;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource) {
	if (this != &materiaSource) {
		for (int i = 0; i < 4; i++) {
			if (this->materias_[i]) {
				delete this->materias_[i];
				this->materias_[i] = NULL;
			}
			if (materiaSource.materias_[i]) {
				this->materias_[i] = materiaSource.materias_[i]->clone();
			}
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *materia) {
    bool is_full = true;
    for (int i = 0; i < 4; i++) {
        if (!this->materias_[i]) {
            this->materias_[i] = materia;
            is_full = false;
            break;
        }
    }
    if (is_full) {
        delete materia;
    }
}

AMateria *MateriaSource::createMateria(const std::string &type) {
	for (int i = 0; i < 4; i++) {
		if (this->materias_[i] && this->materias_[i]->getType() == type) {
			return this->materias_[i]->clone();
		}
	}
	return NULL;
}
