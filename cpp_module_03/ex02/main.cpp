#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap	A("A");
	FragTrap	B("B");

	A.attack("B");
	B.takeDamage(A.getDamage());
	A.attack("B");
	B.takeDamage(A.getDamage());

	B.attack("A");
	A.takeDamage(B.getDamage());

	A.highFivesGuys();

	return (0);
}

