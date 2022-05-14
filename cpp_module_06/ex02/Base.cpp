#include "Base.hpp"
#include <iostream>

Base*	generate(void)
{
	int num;
	srand(time(0));
	num = rand() % 3;
	switch(num)
	{
		case 0:
			std::cout << "A class" << std::endl;
			return (new A());
		case 1:
			std::cout << "B class" << std::endl;
			return (new B());
		case 2:
			std::cout << "C class" << std::endl;
			return (new C());
	}
	return NULL;
}

void	identify(Base* p)
{
	if (p == NULL)
		std::cout << "NULL" << std::endl;
	else if (dynamic_cast<A*>(p) != 0)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != 0)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != 0)
		std::cout << "C" << std::endl;
	else
		std::cout << "Not Found" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;
		return ;
	}
	catch(std::exception &e){}
	try
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void)b;
		return ;
	}
	catch(std::exception &e){}
	try
	{
		C &c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void)c;
		return ;
	}
	catch(std::exception &e){}
}
