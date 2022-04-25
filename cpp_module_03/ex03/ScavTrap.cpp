#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_name = "dafault";
	this->_hp = 100;
	this->_ep = 50;
	this->_damage = 20;
	std::cout << "ScavTrap <" << _name << "> default constructor is called!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &scavTrap) : ClapTrap(scavTrap)
{
	std::cout << "ScavTrap <" << _name << "> copy constructor is called!" << std::endl;
	*this = scavTrap;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hp = 100;
	this->_ep = 50;
	this->_damage = 20;
	std::cout << "ScavTrap <" << _name << "> string constructor is called!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap <" << _name << "> destructor is called!" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &scavtrap)
{
	ClapTrap::operator=(scavtrap);
	std::cout << "ScavTrap <" << _name << "> assignment operators is called!" << std::endl;
	return (*this);
}

void ScavTrap::attack(std::string const &target)
{
	std::cout << "ScavTrap <" << _name << "> attack <" << target << ">, causing <" << _damage << "> points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap <" << _name << "> Entered gatekeeper mode!" << std::endl;
}