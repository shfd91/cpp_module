#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "[Cat] default constructor" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat &copy)
{
	std::cout << "[Cat] copy constructor" << std::endl;
	this->brain = new Brain(*copy.brain);
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << "[Cat] assignment operator" << std::endl;
	if (this != &copy)
	{
		this->type = copy.type;
		delete this->brain;
		this->brain = NULL;
		this->brain = new Brain(*copy.brain);
	}
	return (*this);
}

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << "[Cat] destructor" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "[Cat] meou meou" << std:: endl;
}

Brain *Cat::getBrain() const
{
	return this->brain;
}