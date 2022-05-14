#include "Bureaucrat.hpp"

int main()
{
	// Bureaucrat a("a", 1);

	try
	{
		Bureaucrat b("b", -1);
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
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
	return (0);
}