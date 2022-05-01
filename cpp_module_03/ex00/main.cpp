#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	a("A");
	ClapTrap	b("B");

	a.attack("B");
	b.takeDamage(a.getDamage());

	b.attack("A");
	a.takeDamage(b.getDamage());

	b.attack("A");
	a.takeDamage(b.getDamage());

	b.attack("A");
	a.takeDamage(b.getDamage());

	a.beRepaired(10);
	b.beRepaired(20);
	a.printStatus();
	ClapTrap	c(a);
	c.printStatus();

	return (0);
}

