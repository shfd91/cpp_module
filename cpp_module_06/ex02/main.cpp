#include "Base.hpp"

int main()
{
	Base *b = generate();
	std::cout << "Pointer Type : ";
	identify(*b);
	std::cout << "Reference Type : ";
	identify(b);

	delete b;
	return 0;
}