#include "Zombie.hpp"

Zombie::Zombie()
{

}

Zombie::Zombie(std::string name) : name(name)
{

}

Zombie::~Zombie()
{
	std::cout << name << " is dead" << std::endl;
}

void Zombie::setZombie(std::string name)
{
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

