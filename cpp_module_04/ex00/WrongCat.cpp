#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
	std::cout << "[WrongCat] default constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	*this = copy;
	std::cout << "[WrongCat] copy constructor" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	this->type = copy.type;
	std::cout << "[WrongCat] assignment operator" << std::endl;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "[WrongCat] destructor" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "[WrongCat] meou meou" << std:: endl;
}