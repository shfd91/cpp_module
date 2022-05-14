/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slee2 <slee2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:30:53 by slee2             #+#    #+#             */
/*   Updated: 2021/11/24 21:08:27 by slee2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	std::cout << "---addNumber test---" << std::endl;

	try
	{
		Span					sp(0);
		sp.addNumber(0);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Span					sp(1);
		sp.addNumber(3);
		sp.addNumber(5);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "---short_long exception test---" << std::endl;
	
	try
	{
		Span					sp(0);
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Span					sp(0);
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "---max test---" << std::endl;
	
	Span						sp1 = Span(10000);

	for (int i = -5000; i <= 4999; i++)
		sp1.addNumber(i);
	std::cout << sp1.shortestSpan() << std::endl;
	std::cout << sp1.longestSpan() << std::endl;

	return 0;
}