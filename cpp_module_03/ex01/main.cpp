#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap	A("A");
	ScavTrap	B("B");

	A.printStatus();
	std::cout << std::endl;
	A.attack("B");
	B.takeDamage(A.getDamage());
	A.attack("B");
	B.takeDamage(A.getDamage());
	std::cout << std::endl;

	B.attack("A");
	A.takeDamage(B.getDamage());
	B.attack("A");
	A.takeDamage(B.getDamage());
	B.attack("A");
	A.takeDamage(B.getDamage());
	ScavTrap	C(A);
	B.attack("A");
	A.takeDamage(B.getDamage());
	B.attack("A");
	A.takeDamage(B.getDamage());
	B.attack("A");
	A.takeDamage(B.getDamage());

	A.guardGate();
	B.guardGate();

	A.printStatus();
	B.printStatus();
	C.printStatus();

	return (0);
}

