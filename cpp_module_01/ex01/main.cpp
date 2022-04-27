#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

Zombie* newZombie(std::string name)
{
	return new Zombie(name);
}

int main(void)
{
	Zombie *zombie = zombieHorde(5, "zombie");

	for (int i = 0; i < 5; i++)
		zombie[i].announce();
	delete[] zombie;
	return (0);
}