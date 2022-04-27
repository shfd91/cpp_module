#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : _name(ClapTrap::_name)
{
	ClapTrap::_name = _name + "_clap_name";
	this->_hp = 100;
	this->_ep = 50;
	this->_damage = 30;
	std::cout << "DiamondTrap <" << _name << "> default constructor is called!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	this->_hp = 100;
	this->_ep = 50;
	this->_damage = 30;
	std::cout << "DiamondTrap <" << _name << "> string constructor is called!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap <" << _name << "> destructor is called!" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &obj)
{
	std::cout << "DiamondTrap <" << _name << "> copy constructor is called!" << std::endl;
	*this = obj;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const &diamondTrap)
{
	ScavTrap::operator=(diamondTrap);
	_name = diamondTrap._name;
	std::cout << "DiamondTrap <" << _name << "> assignment operators is called!" << std::endl;
	return (*this);
}

void DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap my name is <" << _name << "> ";
	std::cout << "ClapTrap name is <" << ClapTrap::_name << ">" << std::endl;
}
