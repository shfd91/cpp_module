#include "Weapon.hpp"

Weapon::Weapon(std::string str)
{
	_type = str;
}

void Weapon::setType(std::string str)
{
	_type = str;
}

const std::string &Weapon::getType()
{
	return (_type);
}
