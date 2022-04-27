#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << "[Cat] default constructor" << std::endl;
}

Cat::Cat(const Cat &copy)
{
	*this = copy;
	std::cout << "[Cat] copy constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
	this->type = copy.type;
	std::cout << "[Cat] assignment operator" << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "[Cat] destructor" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "[Cat] meou meou" << std:: endl;
}