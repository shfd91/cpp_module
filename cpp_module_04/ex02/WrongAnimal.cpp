#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
	std::cout << "[WrongAnimal] default constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	*this = copy;
	std::cout << "[WrongAnimal] copy constructor" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &copy)
{
	this->type = copy.type;
	std::cout << "[WrongAnimal] assignment operator" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "[WrongAnimal] destructor" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "[WrongAnimal] makeSound" << std:: endl;
}

const std::string &WrongAnimal::getType() const
{
	return (this->type);
}