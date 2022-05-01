#include "Fixed.hpp"

int main(void)
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;
	std::cout << std::endl;

	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	std::cout << "a > b : " << (a > b) << std::endl;
	std::cout << "a < b : " << (a < b) << std::endl;
	std::cout << "a >= b : " << (a >= b) << std::endl;
	std::cout << "a <= b : " << (a <= b) << std::endl;
	std::cout << "a == b : " << (a == b) << std::endl;
	std::cout << "a != b : " << (a != b) << std::endl;
	std::cout << std::endl;

	std::cout << "Fixed(5.05f) : " << Fixed(5.05f) << std::endl;
	std::cout << "Fixed(10) : " << Fixed(10) << std::endl;
	std::cout << "Fixed(5.05f) + Fixed(10) : " << Fixed(5.05f) + Fixed(10) << std::endl;
	std::cout << "Fixed(5.05f) - Fixed(10) : " << Fixed(5.05f) - Fixed(10) << std::endl;
	std::cout << "Fixed(5.05f) * Fixed(10) : " << Fixed(5.05f) * Fixed(10) << std::endl;
	std::cout << "Fixed(5.05f) / Fixed(10) : " << Fixed(5.05f) / Fixed(10) << std::endl;

	return 0;
}