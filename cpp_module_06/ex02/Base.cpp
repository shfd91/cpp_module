/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slee2 <slee2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:56:41 by slee2             #+#    #+#             */
/*   Updated: 2021/11/23 15:27:56 by slee2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base*	generate(void) {
	int num;
	srand(time(0));
	num = rand() % 3;
	switch(num) {
		case 0:
			std::cout << "return A class" << std::endl;
			return (new A());
		case 1:
			std::cout << "return B class" << std::endl;
			return (new B());
		case 2:
			std::cout << "return C class" << std::endl;
			return (new C());
	}
	return NULL;
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base& p) {
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return ;
	} catch(std::exception&) {
	}
	try {
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return ;
	} catch(std::exception&) {
	}
	try {
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return ;
	} catch(std::exception&) {
	}
}

