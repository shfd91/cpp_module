#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(FragTrap const &scavTrap);
		FragTrap(std::string name);
		~FragTrap();
		FragTrap& operator=(FragTrap const &scavTrap);
		void	attack(std::string const &target);
		void	highFivesGuys();
};

#endif