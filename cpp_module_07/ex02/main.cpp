#include <iostream>
#include "Array.hpp"

int main()
{

	try
	{
		Array<int> numbers(10);
		for (int i = 0; i < 10; i++)
			std::cout << numbers[i] << " ";
		std::cout << std::endl;

		for (int i = 0; i < 10; i++)
			numbers[i] = i;

		for (int i = 0; i < 10; i++)
			std::cout << numbers[i] << " ";
		std::cout << std::endl;
		std::cout << "numbers size : " << numbers.size() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "[Exception]" << std::endl;
		Array<char> c_numbers(10);
		c_numbers[0] = 'a';
		c_numbers[-1] = 'b';
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Array<char> c_numbers;
		c_numbers[1];
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "[Copy]" << std::endl;
		Array<double> d_numbers(5);
		d_numbers[0] = 1.1;
		d_numbers[1] = 2.2;
		d_numbers[2] = 3.3;
		d_numbers[3] = 4.4;
		d_numbers[4] = 5.5;
		Array<double> d_numbers_copy1(d_numbers);
		Array<double> d_numbers_copy2;
		std::cout << "[before] d_numbers_copy2 size : " << d_numbers_copy2.size() << std::endl;
		d_numbers_copy2 = d_numbers_copy1;
		std::cout << "[after] d_numbers_copy2 size : " << d_numbers_copy2.size() << std::endl;

		std::cout << "\nd_numbers_copy2 : ";
		for (int i = 0; i < 5; i++)
			std::cout << d_numbers_copy2[i] << " ";
		std::cout << std::endl;

		d_numbers[1] *= 2;
		std::cout << "\nd_numbers : ";
		for (int i = 0; i < 5; i++)
			std:: cout << d_numbers[i] << " ";

		d_numbers_copy2[4] *=2;
		std::cout << "\nd_numbers_copy2 : ";
		for (int i = 0; i < 5; i++)
			std:: cout << d_numbers_copy2[i] << " ";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}