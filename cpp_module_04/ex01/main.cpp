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


	std::cout << "========== CAT ===========" << std::endl;
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

	std::cout << "========= basic ==========" << std::endl;
	std::cout << "[basic.brain addr : " << basic.getBrain() << "]" << std::endl;
	for (int i = 0; i < 6; i++)
		std::cout << "[" << i << "] " << basic.getBrain()->getIdeas(i) << std::endl;
	std::cout << "==========================" << std::endl << std::endl;

	std::cout << "====== [deep copy] =======" << std::endl;
	std::cout << "===== (constructor) ======" << std::endl;
	std::cout << "[copy.brain addr : " << copy.getBrain() << "]" << std::endl;
	for (int i = 0; i < 6; i++)
		std::cout << "[" << i << "] " << copy.getBrain()->getIdeas(i) << std::endl;
	std::cout << "==========================" << std::endl << std::endl;
	std::cout << "====== [deep copy] =======" << std::endl;
	std::cout << "== (assignment operator) ==" << std::endl;
	std::cout << "[copy.brain addr : " << copy2.getBrain() << "]" << std::endl;
	for (int i = 0; i < 6; i++)
		std::cout << "[" << i << "] " << copy2.getBrain()->getIdeas(i) << std::endl;
	std::cout << "==========================" << std::endl << std::endl;
	std::cout << std::endl;
	std::cout << "========== DOG ===========" << std::endl;
	Dog basic2;
	basic2.getBrain()->setIdeas("aaa", 0);
	basic2.getBrain()->setIdeas("bbb", 1);
	basic2.getBrain()->setIdeas("ccc", 2);
	basic2.getBrain()->setIdeas("ddd", 3);
	basic2.getBrain()->setIdeas("eee", 4);
	basic2.getBrain()->setIdeas("fff", 5);
	Dog copy3 = basic2;
	Dog copy4;
	copy4 = basic2;

	std::cout << "========= basic ==========" << std::endl;
	std::cout << "[basic.brain addr : " << basic2.getBrain() << "]" << std::endl;
	for (int i = 0; i < 6; i++)
		std::cout << "[" << i << "] " << basic2.getBrain()->getIdeas(i) << std::endl;
	std::cout << "==========================" << std::endl << std::endl;

	std::cout << "====== [deep copy] =======" << std::endl;
	std::cout << "===== (constructor) ======" << std::endl;
	std::cout << "[copy.brain addr : " << copy3.getBrain() << "]" << std::endl;
	for (int i = 0; i < 6; i++)
		std::cout << "[" << i << "] " << copy3.getBrain()->getIdeas(i) << std::endl;
	std::cout << "==========================" << std::endl << std::endl;
	std::cout << "====== [deep copy] =======" << std::endl;
	std::cout << "== (assignment operator) ==" << std::endl;
	std::cout << "[copy.brain addr : " << copy4.getBrain() << "]" << std::endl;
	for (int i = 0; i < 6; i++)
		std::cout << "[" << i << "] " << copy4.getBrain()->getIdeas(i) << std::endl;
	std::cout << "==========================" << std::endl << std::endl;
	std::cout << std::endl;


	// system("leaks a.out");
}