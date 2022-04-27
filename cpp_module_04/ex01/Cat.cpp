#include "Cat.hpp"

Cat::Cat(void)
{
	this->brain = new Brain();
	this->type = "Cat";
	std::cout << "[Cat] default constructor" << std::endl;
}

Cat::Cat(const Cat &copy)
{
	this->brain = new Brain(*copy.getBrain());
	std::cout << "[Cat] copy constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
	// this->brain = copy.brain;
	// this->type = copy.type;

	if (this != &copy)
	{
		this->~Cat();
		this->brain = new Brain(*copy.getBrain());
		this->Animal::operator=(copy);
	}

	std::cout << "[Cat] assignment operator" << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "[Cat] destructor" << std::endl;
	delete this->brain;
}

void Cat::makeSound() const
{
	std::cout << "[Cat] meou meou" << std:: endl;
}

Brain *Cat::getBrain() const
{
	return this->brain;
}