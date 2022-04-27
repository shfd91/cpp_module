#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat b("b", 30);
	std::cout << b << std::endl;
	try
	{
		Form formA("formA", 151, 150);
		std::cout << formA << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Form formB("formB", 10, 10);
		std::cout << formB << std::endl;
		b.signForm(formB);
		b.increase(20);
		b.signForm(formB);
		std::cout << formB << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}