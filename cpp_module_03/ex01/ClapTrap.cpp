#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hp(10), _ep(10), _damage(0)
{
	std::cout << "ClapTrap " << this->_name << " default constructor is called!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &claptrap)
{
	std::cout << "ClapTrap copy constructor is called!" << std::endl;
	*this = claptrap;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _damage(0)
{
	std::cout << "ClapTrap " << this->_name << " string constructor is called!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " destructor is called!" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &claptrap)
{
	this->_name = claptrap._name;
	this->_hp = claptrap._hp;
	this->_ep = claptrap._ep;
	this->_damage = claptrap._damage;
	std::cout << "ClapTrap " << this->_name << " assignment operators is called!" << std::endl;
	return (*this);
}

void ClapTrap::attack(std::string const &target)
{
	if (immobilityStatus(*this))
		return ;
	this->_ep--;
	std::cout << "ClapTrap " << this->_name << " attack " << target << ", causing " << this->_damage << " points of damage!" << " [Remaining EP : " << this->_ep << "]" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " is attacked and takes " << amount << " points of damage! ";
	this->_hp -= amount;
	if (this->_hp == 0 || this->_hp > 50000)
	{
		this->_hp = 0;
		std::cout << "[Remaining HP : " << this->_hp << "] " << this->_name << " destroyed!" << std::endl;
	}
	else
		std::cout << "[Remaining HP : " << this->_hp << "]" << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (immobilityStatus(*this))
		return ;
	if ((this->_hp + amount) > 5000)
	{
		std::cout << this->_name << " have too much HP" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " repaired " << amount << " points. ";
	this->_hp += amount;
	this->_ep--;
	std::cout << "[Remaining HP : " << this->_hp << ", Remaining EP : " << this->_ep << "]" << std::endl;

}

unsigned int ClapTrap::getDamage() const
{
	return (this->_damage);
}

int ClapTrap::immobilityStatus(ClapTrap &obj) const
{
	if (obj._hp <= 0)
	{
		std::cout << "ClapTrap " << this->_name << ", You are unable to move because you have no HP." << std::endl;
		return (1);
	}
	else if (obj._ep <= 0)
	{
		std::cout << "ClapTrap " << this->_name << ", You are unable to move because you have no EP." << std::endl;
		return (1);
	}
	return (0);
}

void ClapTrap::printStatus() const
{
	std::cout << "[" << this->_name << " status] hp : " << this->_hp << ", ep : " << this->_ep << ", damage : " << this->_damage << std::endl;
}
