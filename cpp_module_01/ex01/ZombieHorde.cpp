#include "Zombie.hpp"
#include <iostream>
#include <sstream>

Zombie* zombieHorde(int N, std::string name)
{
	std::string str;
	std::stringstream sstream;

	Zombie *zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		sstream << i;
		zombies[i].setZombie(name + sstream.str());
		sstream.str("");
	}

	return (zombies);
}