#include "Brain.hpp"

Brain::Brain(void)
{
	for (int i = 0; i < 100; i++)
		this->setIdeas("default", 100);
	std::cout << "[Brain] default constructor" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.getIdeas(i);
	std::cout << "[Brain] copy constructor" << std::endl;
}

Brain &Brain::operator=(const Brain &copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = copy.getIdeas(i);
	}
	std::cout << "[Brain] assignment operator" << std::endl;
	return *this;
}

Brain::~Brain(void)
{
	std::cout << "[Brain] destructor" << std::endl;
}

void Brain::setIdeas(std::string str, int index)
{
	this->ideas[index] = str;
}

std::string const &Brain::getIdeas(int index) const
{
	return this->ideas[index];
}