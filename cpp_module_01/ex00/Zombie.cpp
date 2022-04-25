#include "Zombie.hpp"

Zombie::Zombie() : _name("default zombie")
{

}

Zombie::Zombie(std::string name)
{
	this->_name = name;
}

Zombie::~Zombie()
{
	std::cout << "<" << _name << ">" << " is dead" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << "<" << _name << ">" << " BraiiiiiiinnnzzzZ..." << std::endl;
}
