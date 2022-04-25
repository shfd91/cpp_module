#include <iostream>

int main(void)
{
	std::string str_brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &str_brain;
	std::string &stringREF = str_brain;

	std::cout << "string addr : " << &str_brain << std::endl;
	std::cout << "string addr(ptr) : " << stringPTR << std::endl;
	std::cout << "string addr(ref) : " << &stringREF << std::endl;
	std::cout << "string(ptr) : " << *stringPTR << std::endl;
	std::cout << "string(ref) : " << stringREF << std::endl;
	return (0);
}