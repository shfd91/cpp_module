#include "easyfind.hpp"

int main()
{
	try {
		std::vector<int>	v(3);
		v[0] = 1;
		v[1] = 2;
		v[2] = 3;
		std::vector<int>::iterator i = easyfind(v, 3);
		std::cout << *i << std::endl;
	} catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::deque<int>		d(3);
		d[0] = 5;
		d[1] = 3;
		d[2] = 2;
		std::deque<int>::iterator i = easyfind(d, 5);
		std::cout << *i << std::endl;
	} catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::list<int>		l(4, 3);
		std::list<int>::iterator i = easyfind(l, 5);
		std::cout << *i << std::endl;
	} catch(std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}