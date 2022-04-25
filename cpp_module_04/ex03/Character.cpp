#include "Character.hpp"

Character::Character() : _name("no name")
{
	for (int i = 0; i < 4; i++)
		this->_aMateria[i] = NULL;
}
Character::Character(const Character &copy)
{
	this->_name = copy.getName();
	for (int i = 0; i < 4; i++)
	{
		AMateria const *tmp = copy._aMateria[i];
		if (tmp != NULL)
			this->_aMateria[i] = tmp->clone();
		else
			this->_aMateria[i] = NULL;
	}
}

Character &Character::operator=(const Character &copy)
{
	if (this != &copy)
	{
		this->~Character();
		this->_name = copy.getName();
		for (int i = 0; i < 4; i++)
		{
			AMateria const *tmp = copy._aMateria[i];
			if (tmp != NULL)
				this->_aMateria[i] = tmp->clone();
			else
				this->_aMateria[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_aMateria[i] != NULL)
			delete this->_aMateria[i];
	}
}

Character::Character(const std::string &name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_aMateria[i] = NULL;
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_aMateria[i] == NULL)
		{
			this->_aMateria[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	this->_aMateria[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (this->_aMateria[idx] != NULL)
		this->_aMateria[idx]->use(target);
}
