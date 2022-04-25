#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog &copy);
		Dog &operator=(const Dog &copy);
		~Dog(void);
		void makeSound() const;
};

#endif