#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{
	Zombie zombie1("zombie1");
	zombie1.announce();

	Zombie *zombie2 = newZombie("zombie2");
	zombie2->announce();

	randomChump("zombie3");

	delete zombie2;
	system("leaks Zombie");
	return (0);
}