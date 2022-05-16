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
		~Span();
		void addNumber(int n);
		int	shortestSpan();
		int	longestSpan();
		void addMaxNumber(int n);
		Span&	operator=(const Span& s);
		std::vector<int>	getVector() const;
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