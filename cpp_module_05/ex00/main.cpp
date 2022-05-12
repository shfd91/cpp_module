#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat a("a", -1);
		std::cout << a << std::endl;
		a.decrease(9);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat a("a", 1);
		std::cout << a << std::endl;
		a.decrease(9);
		a.decrease(10);
		a.increase(19);
		a.increase(1);
		std::cout << a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat a("a", 1);
		std::cout << a << std::endl;
		a.decrease(49);
		a.decrease(50);
		a.decrease(50);
		a.decrease(1);
		std::cout << a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}