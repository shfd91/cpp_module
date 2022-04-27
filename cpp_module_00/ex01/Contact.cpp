/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghole <sanghole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:03:56 by sanghole          #+#    #+#             */
/*   Updated: 2022/04/27 05:13:38 by sanghole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::limitString(std::string &str, std::string &tmp)
{
	if (str.length() > 9)
	{
		tmp = str.substr(0, 9);
		tmp.append(".");
	}
}

void	Contact::setContact(std::string &first, std::string &last, std::string &nick, std::string &num, std::string &sec)
{
	first_name = first;
	last_name = last;
	nickname = nick;
	phone_number = num;
	darkest_secret = sec;
}


int		Contact::printNothing()
{
	std::cout << "Nothing has been entered." << std::endl;
	return 1;
}


int		Contact::addContact()
{
	std::string tmp_first_name;
	std::string tmp_last_name;
	std::string tmp_nickname;
	std::string tmp_phone_number;
	std::string tmp_darkest_secret;

	std::cout << "input firs_name" << std::endl;
	std::getline(std::cin, tmp_first_name);
	if (std::cin.eof() || tmp_first_name.empty())
		return (printNothing());

	std::cout << "input last_name" << std::endl;
	std::getline(std::cin, tmp_last_name);
	if (std::cin.eof() || tmp_last_name.empty())
		return (printNothing());

	std::cout << "input nickname" << std::endl;
	std::getline(std::cin, tmp_nickname);
	if (std::cin.eof() || tmp_nickname.empty())
		return (printNothing());

	std::cout << "input phone_number" << std::endl;
	std::getline(std::cin, tmp_phone_number);
	if (std::cin.eof() || tmp_phone_number.empty())
		return (printNothing());

	std::cout << "input darkest_secret" << std::endl;
	std::getline(std::cin, tmp_darkest_secret);
	if (std::cin.eof() || tmp_darkest_secret.empty())
		return (printNothing());

	setContact(tmp_first_name, tmp_last_name, tmp_nickname, tmp_phone_number, tmp_darkest_secret);
	return 0;
}

void Contact::printContact(int index)
{
	std::string tmp;

	std::cout << std::setw(10) << index + 1 << " | ";
	if (first_name.length() > 9)
		limitString(first_name, tmp);
	else
		tmp = first_name;
	std::cout << std::setw(10) << tmp << " | ";
	if (last_name.length() > 9)
		limitString(last_name, tmp);
	else
		tmp = last_name;
	std::cout << std::setw(10) << tmp << " | ";
	if (nickname.length() > 9)
		limitString(nickname, tmp);
	else
		tmp = nickname;
	std::cout << std::setw(10) << tmp << std::endl;
}

void Contact::printAll()
{
	std::cout << "first_name : " << first_name << std::endl;
	std::cout << "last_name : " << last_name << std::endl;
	std::cout << "nick_name : " << nickname << std::endl;
	std::cout << "phone_number : " << phone_number << std::endl;
	std::cout << "darkest_secret : " << darkest_secret << std::endl;
}
