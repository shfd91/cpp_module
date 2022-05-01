#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_name = "dafault";
	_hp = 100;
	_ep = 100;
	_damage = 30;
	std::cout << "FragTrap " << _name << " default constructor is called!" << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy)
{
	*this = copy;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hp = 100;
	_ep = 100;
	_damage = 30;
	std::cout << "FragTrap " << _name << " string constructor is called!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " destructor is called!" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const &copy)
{
	ClapTrap::operator=(copy);
	return (*this);
}

void FragTrap::attack(std::string const &target)
{
	if (immobilityStatus(*this))
		return ;
	this->_ep--;
	std::cout << "FragTrap " << _name << " attack " << target << ", causing " << _damage << " points of damage!" << " [Remaining EP : " << this->_ep << "]" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name << " Ask for a positive high-five!" << std::endl;
}