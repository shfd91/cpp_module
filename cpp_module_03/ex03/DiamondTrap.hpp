#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	std::string	_name;
	public:
		DiamondTrap();
		DiamondTrap(DiamondTrap const &diamondTrap);
		DiamondTrap(std::string name);
		~DiamondTrap();
		DiamondTrap& operator=(DiamondTrap const &diamondTrap);
		void	attack(std::string const &target);
		void	whoAmI();
};

#endif