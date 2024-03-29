#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator iter = std::find(container.begin(), container.end(), value);
	if (iter == container.end())
		throw std::runtime_error("No value found.");
	return iter;
}

#endif