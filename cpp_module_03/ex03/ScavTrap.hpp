#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(ScavTrap const &scavTrap);
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap& operator=(ScavTrap const &scavTrap);
		void	attack(std::string const &target);
		void	guardGate();
};

#endif