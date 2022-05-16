#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <iterator>

class Span {
	private:
		std::vector<int> _vec;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& s);
		Span& operator=(const Span& s);
		~Span();
		void addNumber(int n);
		int	shortestSpan();
		int	longestSpan();
		void addMaxNumber(int n);
		std::vector<int> getVector() const;
		template <typename T>
		void addRange(T begin, T end)
		{
			while (begin != end)
				_vec.push_back(*begin++);
		}
		class DataFullException: public std::exception {
			public:
				const char* what() const throw();
		};
		class OneDataException: public std::exception {
			public:
				const char*	what() const throw();
		};
};

#endif