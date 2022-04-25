#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << "[Dog] default constructor" << std::endl;
}

Dog::Dog(const Dog &copy)
{
	*this = copy;
	std::cout << "[Dog] copy constructor" << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
	this->type = copy.type;
	std::cout << "[Dog] assignment operator" << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "[Dog] destructor" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "[Dog] Woof woof" << std:: endl;
}
