#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	std::string		_name;
	unsigned int	_hp;
	unsigned int	_ep;
	unsigned int	_damage;
	public:
		ClapTrap();
		ClapTrap(ClapTrap const &claptrap);
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap& operator=(ClapTrap const &claptrap);
		void attack(std::string const &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		unsigned int getDamage() const;
};

#endif