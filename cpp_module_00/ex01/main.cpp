/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghole <sanghole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:27:19 by sanghole          #+#    #+#             */
/*   Updated: 2022/04/25 16:34:46 by sanghole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	std::string	cmd;
	PhoneBook pb;

	// std::cin >> cmd;
	// std::cout << cmd << std::endl;

	for (;;)
	{
		std::cout << "Enter the command(ADD, SEARCH, EXIT)" << std::endl;
		std::cin >> cmd;
		std::cin.clear();
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

// 여러 문자가 입력되었을 때 처리.
// getline으로 하는게 편하지만
// 대신 strring으로만 들어오기 때문에 int로 변환하는 과정으로 거쳐줘야함

// 저장할 때 잘라서 저장하면 안된다.

// SEARCH는 모든 항목을 나타내야 한다.