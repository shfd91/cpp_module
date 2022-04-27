/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghole <sanghole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:03:56 by sanghole          #+#    #+#             */
/*   Updated: 2022/04/27 05:13:42 by sanghole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0), num(0)
{

}

void PhoneBook::add()
{
	if ((contacts[index].addContact()) == 0)
	{
		if (num < 8)
			num++;
		if (index < 7)
			index++;
		else
			index = 0;
	}
	else
		return ;
}

void PhoneBook::search()
{
	int	input_index;
	std::string tmp;

	if (num == 0)
	{
		std::cout << "There is no phone book listing" << std::endl;
		return;
	}
	for (int i = 0; i < num; i++)
		contacts[i].printContact(i);
	std::cout << "Enter index" << std::endl;
	std::getline(std::cin, tmp);
	if (std::cin.eof())
		return;
	else if (tmp.operator[](1))
	{
		std::cout << "Please enter another number." << std::endl;
		return;
	}
	input_index = tmp.operator[](0) - 48;
	if (num > 0 && input_index < num + 1)
		contacts[input_index - 1].printAll();
	else
		std::cout << "Please enter another number." << std::endl;
}
