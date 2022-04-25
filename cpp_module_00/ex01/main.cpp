/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghole <sanghole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:27:19 by sanghole          #+#    #+#             */
/*   Updated: 2022/04/25 05:29:29 by sanghole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	std::string	cmd;
	PhoneBook pb;

	for (;;)
	{
		std::cout << "Enter the command(ADD, SEARCH, EXIT)" << std::endl;
		std::cin >> cmd;
		if (cmd == "ADD")
			pb.add();
		else if (cmd == "SEARCH")
			pb.search();
		else if (cmd == "EXIT")
			break ;
	}
	return 0;
}