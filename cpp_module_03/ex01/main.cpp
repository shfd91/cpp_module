#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap	A("A");
	ScavTrap	B("B");

	A.attack("B");
	B.takeDamage(A.getDamage());
	A.attack("B");
	B.takeDamage(A.getDamage());

	B.attack("A");
	A.takeDamage(B.getDamage());

	A.guardGate();

	return (0);
}

