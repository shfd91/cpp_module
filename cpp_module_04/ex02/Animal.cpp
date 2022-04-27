#include "Animal.hpp"

Animal::Animal(void) : type("Animal")
{
	std::cout << "[Animal] default constructor" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	*this = copy;
	std::cout << "[Animal] copy constructor" << std::endl;
}

Animal	&Animal::operator=(const Animal &copy)
{
	this->type = copy.type;
	std::cout << "[Animal] assignment operator" << std::endl;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "[Animal] destructor" << std::endl;
}

const std::string &Animal::getType() const
{
	return (this->type);
}