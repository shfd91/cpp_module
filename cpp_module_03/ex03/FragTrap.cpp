#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_name = "dafault";
	this->_hp = 100;
	this->_ep = 100;
	this->_damage = 30;
	std::cout << "FragTrap <" << _name << "> default constructor is called!" << std::endl;
}

FragTrap::FragTrap(FragTrap const &scavTrap) : ClapTrap(scavTrap)
{
	std::cout << "FragTrap <" << _name << "> copy constructor is called!" << std::endl;
	*this = scavTrap;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hp = 100;
	this->_ep = 100;
	this->_damage = 30;
	std::cout << "FragTrap <" << _name << "> string constructor is called!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap <" << _name << "> destructor is called!" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const &scavtrap)
{
	ClapTrap::operator=(scavtrap);
	std::cout << "FragTrap <" << _name << "> assignment operators is called!" << std::endl;
	return (*this);
}

void FragTrap::attack(std::string const &target)
{
	std::cout << "FragTrap <" << _name << "> attack <" << target << ">, causing <" << _damage << "> points of damage!" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap <" << _name << "> Ask for a positive high-five!" << std::endl;
}