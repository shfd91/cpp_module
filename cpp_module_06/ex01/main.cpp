/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slee2 <slee2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 06:24:04 by slee2             #+#    #+#             */
/*   Updated: 2021/11/23 17:58:41 by slee2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main()
{
	Data	d1;
	Data	d2("abca", 100);
	uintptr_t	p1 = serialize(&d1);
	uintptr_t	p2 = serialize(&d2);

	std::cout << "d1 - " << d1.getName() << d1.getGrade() << std::endl;
	std::cout << "d2 - " << d2.getName() << d2.getGrade() << std::endl;
	std::cout << &d1 << std::endl;
	std::cout << std::hex << p1 << std::endl;

	std::cout << std::endl;
	
	Data	*d3 = deserialize(p1);
	Data	*d4 = deserialize(p2);

	std::cout << "d3 - " << d3->getName() << d3->getGrade()	<< std::endl;
	std::cout << "d4 - " << d4->getName() << d4->getGrade() << std::endl;
	std::cout << d3 << std::endl;
	
	d4->setGrade(30);
	std::cout << "change d4->grade and d2.grade is -> " << d2.getGrade() << std::endl;

	return 0;
}