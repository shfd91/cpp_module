#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	std::cout << std::endl;
	Animal *a[4];
	for(int i = 0; i < 4; i++)
	{
		if (i < 2)
			a[i] = new Cat();
		else
			a[i] = new Dog();
	}
	for(int i = 0; i < 4; i++)
		a[i]->makeSound();
	for(int i = 0; i < 4; i++)
		delete a[i];

	std::cout << std::endl;


	std::cout << "=========================" << std::endl;
	Cat basic;
	basic.getBrain()->setIdeas("aaa", 0);
	basic.getBrain()->setIdeas("bbb", 1);
	basic.getBrain()->setIdeas("ccc", 2);
	basic.getBrain()->setIdeas("ddd", 3);
	basic.getBrain()->setIdeas("eee", 4);
	basic.getBrain()->setIdeas("fff", 5);
	Cat copy = basic;
	Cat copy2;
	copy2 = basic;

	std::cout << "[basic.brain addr : " << basic.getBrain() << "]" << std::endl;
	std::cout << "========= basic ==========" << std::endl;
	for (int i = 0; i < 6; i++)
		std::cout << "[" << i << "] " << basic.getBrain()->getIdeas(i) << std::endl;
	std::cout << "==========================" << std::endl << std::endl;

	std::cout << "====== [deep copy(copy constructor)] =======" << std::endl;
	std::cout << "[copy.brain addr : " << copy.getBrain() << "]" << std::endl;
	std::cout << "========== copy ==========" << std::endl;
	for (int i = 0; i < 6; i++)
		std::cout << "[" << i << "] " << copy.getBrain()->getIdeas(i) << std::endl;
	std::cout << "==========================" << std::endl << std::endl;

	std::cout << "====== [deep copy(assignment operator)] =======" << std::endl;
	basic.getBrain()->setIdeas("zzz", 0);

	std::cout << copy2.getType() << std::endl;
	std::cout << "[copy.brain addr : " << copy2.getBrain() << "]" << std::endl;
	std::cout << "========== copy ==========" << std::endl;
	for (int i = 0; i < 6; i++)
		std::cout << "[" << i << "] " << copy2.getBrain()->getIdeas(i) << std::endl;
	std::cout << "==========================" << std::endl;
}