#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain(void);
		Brain(Brain const &copy);
		Brain &operator=(const Brain &copy);
		~Brain(void);
		void setIdeas(std::string str, int index);
		std::string const &getIdeas(int index) const;
};

#endif