#include "Karen.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "error" << std::endl;
		return (1);
	}
	Karen karen;
	karen.complain(argv[1]);
	return (0);
}