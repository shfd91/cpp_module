#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_name = "dafault";
	_hp = 100;
	_ep = 50;
	_damage = 20;
	guardMode = 0;
	std::cout << "ScavTrap " << _name << " default constructor is called!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &scavTrap) : ClapTrap(scavTrap)
{
	*this = scavTrap;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hp = 100;
	_ep = 50;
	_damage = 20;
	guardMode = 0;
	std::cout << "ScavTrap " << _name << " string constructor is called!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destructor is called!" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &scavtrap)
{
	this->guardMode = scavtrap.guardMode;
	return (*this);
}

void ScavTrap::attack(std::string const &target)
{
	if (immobilityStatus(*this))
		return ;
	this->_ep--;
	std::cout << "ScavTrap " << _name << " attack " << target << ", causing " << _damage << " points of damage!" << " [Remaining EP : " << this->_ep << "]" << std::endl;
}

void ScavTrap::guardGate()
{
	if (immobilityStatus(*this))
		return ;
	guardMode = 1;
	std::cout << "ScavTrap " << _name << " now enter gatekeeper mode!" << std::endl;
}

void ScavTrap::printStatus() const
{
	ClapTrap::printStatus();
	if (this->guardMode == 1)
	{
		std::cout << "(GuardMode On)" << std::endl;;
	}
	else
		std::cout << "(GuardMode off)" << std::endl;;

}