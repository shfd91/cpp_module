/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghole <sanghole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:27:19 by sanghole          #+#    #+#             */
/*   Updated: 2022/04/27 05:05:06 by sanghole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	std::string	cmd;
	PhoneBook pb;

	while (!std::cin.eof())
	{
		std::cout << "Enter the command(ADD, SEARCH, EXIT)" << std::endl;
		std::getline(std::cin, cmd);
		if (std::cin.eof()) break;
		else if (cmd == "ADD")
			pb.add();
		else if (cmd == "SEARCH")
			pb.search();
		else if (cmd == "EXIT")
			break ;
		else
			std::cout << "Invalid Command" << std::endl;
	}
	return 0;
}