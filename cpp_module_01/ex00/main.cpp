#include "Zombie.hpp"

int main(void)
{
	Zombie zombie;
	zombie.announce();

	Zombie zombie1("zombie1");
	zombie1.announce();

	Zombie *newZombie(std::string name);
	Zombie *zombie2 = newZombie("zombie2");
	zombie2->announce();

	void randomChump(std::string name);
	randomChump("zombie3");

	delete zombie2;
	system("leaks Zombie");
	return (0);
}