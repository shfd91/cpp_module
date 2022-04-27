#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap A("A");
	DiamondTrap B("B");
	std::cout << std::endl;
	A.whoAmI();
	B.whoAmI();
	std::cout << std::endl;
	A.attack("B");
	B.takeDamage(A.getDamage());
	A.attack("B");
	B.takeDamage(A.getDamage());
	A.attack("B");
	B.takeDamage(A.getDamage());
	A.attack("B");
	B.takeDamage(A.getDamage());
	std::cout << std::endl;

	return (0);
}

