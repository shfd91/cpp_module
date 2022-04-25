#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_aMateria[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	for (int i = 0; i < 4; i++)
	{
		AMateria const *tmp = copy._aMateria[i];
		if (tmp != NULL)
			this->_aMateria[i] = tmp->clone();
		else
			this->_aMateria[i] = NULL;
	}

}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
	if (this != &copy)
	{
		this->~MateriaSource();
		for (int i = 0; i < 4; i++)
		{
			AMateria const *tmp = copy._aMateria[i];
			if (tmp != NULL)
				this->_aMateria[i] = tmp->clone();
			else
				this->_aMateria[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_aMateria[i] != NULL)
			delete this->_aMateria[i];
	}

}

void MateriaSource::learnMateria(AMateria *aMataeria)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_aMateria[i] == NULL)
		{
			this->_aMateria[i] = aMataeria;
			return ;
		}
	}

}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_aMateria[i] != NULL && this->_aMateria[i]->getType() == type)
			return (this->_aMateria[i]->clone());
	}
	return (NULL);
}
