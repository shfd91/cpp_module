/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slee2 <slee2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:30:53 by slee2             #+#    #+#             */
/*   Updated: 2021/11/24 21:07:50 by slee2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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