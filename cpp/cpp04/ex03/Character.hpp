#ifndef INC_42WORKSPACE_CHARACTER_HPP
#define INC_42WORKSPACE_CHARACTER_HPP

#define INVENTORY_SIZE 4

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
public:
	Character(std::string const &name);
	~Character();
	Character(const Character &character);
	Character &operator=(const Character &character);

	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
	void getInventory(int idx) const;
private:
	int	floor_idx_;
	std::string name_;
	AMateria *inventory_[INVENTORY_SIZE];
	AMateria *floor_[1000];

	Character();
};

#endif
