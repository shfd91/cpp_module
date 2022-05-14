/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slee2 <slee2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:57:24 by slee2             #+#    #+#             */
/*   Updated: 2021/11/24 19:30:18 by slee2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <iterator>

class Span {
	private:
		std::vector<int>	data;
	public:
		class DataFullException: public std::exception {
			public:
				const char* what() const throw();
		};
		class JustOneDataException: public std::exception {
			public:
				const char*	what() const throw();
		};
		Span();
		Span(unsigned int N);
		Span(const Span& s);
		~Span();
		void	addNumber(int n);
		int	shortestSpan();
		int	longestSpan();
		Span&	operator=(const Span& s);	
		std::vector<int>	getData() const;
};

#endif