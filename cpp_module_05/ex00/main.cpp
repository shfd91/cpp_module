#include "Bureaucrat.hpp"

int main()
{
<<<<<<< HEAD
	// Bureaucrat a("a", 1);

	try
	{
		Bureaucrat b("b", -1);
		std::cout << b << std::endl;
=======
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
>>>>>>> 8431d552e2d66f816f91b79001d9fc652f2ffe12
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
<<<<<<< HEAD
	// std::cout << std::endl;
	// try
	// {
	// 	a.decrease(49);
	// 	a.decrease(50);
	// 	a.decrease(50);
	// 	a.decrease(1);
	// 	std::cout << a << std::endl;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
=======
>>>>>>> 8431d552e2d66f816f91b79001d9fc652f2ffe12
	return (0);
}