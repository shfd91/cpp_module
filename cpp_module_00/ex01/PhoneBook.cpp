/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghole <sanghole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:03:56 by sanghole          #+#    #+#             */
/*   Updated: 2022/04/25 14:45:09 by sanghole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0), num(0)
{

}

void PhoneBook::add()
{
	if (num < 8)
		num++;
	if (index < 8)
		index++;
	else
		index = 1;
	contacts[index - 1].addContact();
}

void PhoneBook::search()
{
	int	input_index;

	input_index = 0;
	if (num == 0)
	{
		std::cout << "There is no phone book listing" << std::endl;
		return ;
	}
	for (int i = 0; i < num; i++)
	{
		contacts[i].printContact(i);
	}
	std::cout << "Enter index" << std::endl;
	std::cin >> input_index;
	if (std::cin.fail())
	{
		std::cout << "enter a number" << std::endl;
		std::cin.clear();
		std::cin.ignore(100, '\n');
	}
	else if (input_index > 0 && input_index < num + 1)
		contacts[input_index - 1].printContact(input_index - 1);
	else
		std::cout << "Please enter another number." << std::endl;
}
