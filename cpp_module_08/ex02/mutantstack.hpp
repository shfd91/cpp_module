#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class MutantStack: public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

		MutantStack() {};
		MutantStack(const MutantStack<T> &m)
		{
			*this = m;
		}
		MutantStack<T>&	operator=(const MutantStack<T>& m)
		{
			if (this != m)
				this->c = m.c;
			return *this;
		}
		~MutantStack() {}
		iterator	begin()
		{
			return this->c.begin();
		}

		iterator	end()
		{
			return this->c.end();
		}

		reverse_iterator	rbegin()
		{
			return this->c.rbegin();
		}

		reverse_iterator	rend()
		{
			return this->c.rend();
		}
};

#endif