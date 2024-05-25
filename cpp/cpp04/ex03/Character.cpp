#include "Character.hpp"

Character::Character(std::string const &name) : name_(name) {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		inventory_[i] = NULL;
	}
	for (int i = 0; i < 1000; i++) {
		floor_[i] = NULL;
	}
}

Character::~Character() {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (inventory_[i] != NULL) {
			delete inventory_[i];
		}
	}
	for (int i = 0; i < 1000; i++) {
		if (floor_[i] != NULL) {
			delete floor_[i];
		}
	}
}

Character::Character(const Character &character) {
	*this = character;
}

Character &Character::operator=(const Character &character) {
	if (this != &character) {
		name_ = character.name_;
		for (int i = 0; i < INVENTORY_SIZE; i++) {
			if (inventory_[i] != NULL) {
				delete inventory_[i];
			}
			inventory_[i] = character.inventory_[i];
		}
		for (int i = 0; i < 1000; i++) {
			if (floor_[i] != NULL) {
				delete floor_[i];
			}
			floor_[i] = character.floor_[i];
		}
	}
	return *this;
}

std::string const &Character::getName() const {
	return name_;
}

void Character::equip(AMateria *m) {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (inventory_[i] == NULL) {
			inventory_[i] = m;
			return;
		}
	}
	delete m;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= INVENTORY_SIZE || inventory_[idx] == NULL) {
		return;
	}
	floor_[idx] = inventory_[idx];
	inventory_[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx >= INVENTORY_SIZE || inventory_[idx] == NULL) {
		return;
	}
	inventory_[idx]->use(target);
}

void Character::getInventory(int idx) const {
	if (idx < 0 || idx >= INVENTORY_SIZE || inventory_[idx] == NULL) {
		return;
	}
	std::cout << inventory_[idx]->getType() << std::endl;
}
