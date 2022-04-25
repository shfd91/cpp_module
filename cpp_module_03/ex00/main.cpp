#include "ClapTrap.hpp"

int main(void)
{
	// ClapTrap	a("a");
	ClapTrap	a;
	ClapTrap	b("b");
	ClapTrap	c("c");

	a.attack("b");
	b.takeDamage(a.getDamage());

	b.attack("a");
	a.takeDamage(b.getDamage());

	c.attack("b");
	b.takeDamage(c.getDamage());

	a.beRepaired(25);
	b.beRepaired(25);
	return (0);
}

