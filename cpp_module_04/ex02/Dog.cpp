#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "[Dog] default constructor" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog &copy)
{
	std::cout << "[Dog] copy constructor" << std::endl;
	this->brain = new Brain(*copy.brain);
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << "[Dog] assignment operator" << std::endl;
	if (this != &copy)
	{
		this->type = copy.type;
		delete this->brain;
		this->brain = NULL;
		this->brain = new Brain(*copy.brain);
	}
	return (*this);
}

Dog::~Dog(void)
{
	delete this->brain;
	std::cout << "[Dog] destructor" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "[Dog] Woof woof" << std:: endl;
}

Brain *Dog::getBrain() const
{
	return this->brain;
}