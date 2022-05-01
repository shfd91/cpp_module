#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		int guardMode;
	public:
		ScavTrap();
		ScavTrap(ScavTrap const &scavTrap);
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap& operator=(ScavTrap const &scavTrap);
		void	attack(std::string const &target);
		void	guardGate();
		void	printStatus() const;
};

#endif