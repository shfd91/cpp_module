#include "iter.hpp"

int main()
{
	char arr_c[4] = {'a', 'b', 'c', 'd'};
	iter(arr_c, (sizeof(arr_c) / sizeof(*arr_c)), printT);
	std::cout << std::endl << std::endl;

	int arr_i[10];
	for (int i = 0; i < 10; i++)
	{
		arr_i[i] = i;
	}
	iter(arr_i, (sizeof(arr_i) / sizeof(*arr_i)), printT);
	std::cout << std::endl << std::endl;

	std::string str[3] = {"abc", "def" , "hij"};
	iter(str, (sizeof(str) / sizeof(*str)), printT);
	std::cout << std::endl;

	return 0;
}