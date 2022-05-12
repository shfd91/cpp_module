#include "Convert.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid input" << std::endl;
		return (1);
	}
	Convert convert(argv[1]);
	if (convert.typeCheck())
		return (1);
	convert.exeConvert();
	return 0;
	}