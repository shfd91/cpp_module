#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hp(10), _ep(10), _damage(0)
{
	std::cout << "ClapTrap <" << _name << "> default constructor is called!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &claptrap)
{
	std::cout << "ClapTrap <" << _name << "> copy constructor is called!" << std::endl;
	*this = claptrap;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _damage(0)
{
	std::cout << "ClapTrap <" << _name << "> string constructor is called!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap <" << _name << "> destructor is called!" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &claptrap)
{
	_name = claptrap._name;
	_hp = claptrap._hp;
	_ep = claptrap._ep;
	_damage = claptrap._damage;
	std::cout << "ClapTrap <" << _name << "> assignment operators is called!" << std::endl;
	return (*this);
}

void ClapTrap::attack(std::string const &target)
{
	std::cout << "ClapTrap <" << _name << "> attack <" << target << ">, causing <" << _damage << "> points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap <" << _name << "> is attacked and takes <" << amount << "> points of damage! ";
	this->_hp -= amount;
	if (this->_hp == 0 || this->_hp > 5000)
	{
		this->_hp = 0;
		std::cout << "<HP> : " << _hp << std::endl;
		std::cout << "<" << _name << "> " << "destroyed!" << std::endl;
	}
	else
		std::cout << "<HP> : " << _hp << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap <" << _name << "> repaired <" << amount << "> points. ";
	this->_hp += amount;
	std::cout << "<HP> : " << _hp << std::endl;
}

unsigned int ClapTrap::getDamage() const
{
	return (this->_damage);
}