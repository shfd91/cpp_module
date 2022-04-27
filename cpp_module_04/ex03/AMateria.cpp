#include "AMateria.hpp"

AMateria::AMateria() : _type("default") {}

AMateria::AMateria(const AMateria &copy)
{
	this->_type = copy._type;
}
AMateria &AMateria::operator=(const AMateria &copy)
{
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return (*this);
}

AMateria::~AMateria() {}

AMateria::AMateria(std::string const & type) : _type(type) {}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria use : " << target.getName() << std::endl;;
}