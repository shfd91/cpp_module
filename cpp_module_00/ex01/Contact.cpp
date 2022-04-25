/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghole <sanghole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:03:56 by sanghole          #+#    #+#             */
/*   Updated: 2022/04/25 14:14:37 by sanghole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"


void	Contact::correctString(std::string& str)
{
	str = str.substr(0, 9);
	str.append(".");
}

void	Contact::limitString()
{
	if (first_name.length() > 9)
		correctString(first_name);
	if (last_name.length() > 9)
		correctString(last_name);
	if (nickname.length() > 9)
		correctString(nickname);
}

void	Contact::addContact()
{
	std::cout << "input firs_name" << std::endl;
	std::cin >> first_name;
	std::cout << "input last_name" << std::endl;
	std::cin >> last_name;
	std::cout << "input nickname" << std::endl;
	std::cin >> nickname;
	std::cout << "input phone_number" << std::endl;
	std::cin >> phone_number;
	std::cout << "input darkest_secret" << std::endl;
	std::cin >> darkest_secret;
	limitString();
}

void Contact::printContact(int index)
{
	std::cout << std::setw(10) << index + 1 << " | ";
	std::cout << std::setw(10) << first_name << " | ";
	std::cout << std::setw(10) << last_name << " | ";
	std::cout << std::setw(10) << nickname << std::endl;
}