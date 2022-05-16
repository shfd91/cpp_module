#include "easyfind.hpp"

int main()
{
	try
	{
		std::vector<int> vec;
		for (int i = 0; i < 5; i++)
			vec.push_back(i * 10);
		std::vector<int>::iterator itr = easyfind(vec, 30);
		std::cout << *itr << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::list<int> lst;
		for (int i = 0; i < 5; i++)
			lst.push_back(i * 100);
		std::list<int>::iterator itr = easyfind(lst, 200);
		std::cout << *itr << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::deque<int> deq;
		for (int i = 0; i < 5; i++)
			deq.push_back(i * 30);
		std::deque<int>::iterator itr = easyfind(deq, 120);
		std::cout << *itr << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::vector<int> vec;
		for (int i = 0; i < 5; i++)
			vec.push_back(i * 10);
		std::vector<int>::iterator itr = easyfind(vec, 5);
		std::cout << *itr << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}