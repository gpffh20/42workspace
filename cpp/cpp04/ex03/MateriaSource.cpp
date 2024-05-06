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

// void MateriaSource::learnMateria(AMateria *materia) {
// 	for (int i = 0; i < 4; i++) {
// 		if (!this->materias_[i]) {
// 			this->materias_[i] = materia;
// 			break;
// 		}
// 	}
// }

void MateriaSource::learnMateria(AMateria *materia) {
    bool isFull = true;  // 배열이 가득 찼는지 확인하기 위한 변수
    for (int i = 0; i < 4; i++) {
        if (!this->materias_[i]) {
            this->materias_[i] = materia;
            isFull = false;  // 빈 자리를 찾았으므로 배열이 가득 차지 않았음
            break;
        }
    }
    if (isFull) {
        delete materia;  // 배열이 가득 차 있으면 들어온 materia 객체를 삭제
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
