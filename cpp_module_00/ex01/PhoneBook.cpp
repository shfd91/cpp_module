/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghole <sanghole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:03:56 by sanghole          #+#    #+#             */
/*   Updated: 2022/03/08 11:21:28 by sanghole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Contact // 연락처의 각 정보의 멤버 변수들을 가지고 있는 클래스
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	// public:
};

class PhoneBook // Contact 배열을 포함하고 있으며, 기능 구현의 멤버 함수를 포함하고 있는 클래스
{
	Contact	contacts[8];
	public:
		// PhoneBook(); // 자동 생성자? 간단하게 하는방법으로 하기
		void add();
		void search();
};

void PhoneBook::add()
{
	std::cout << "input first_name" << std::endl;
	std::cin >> first_name;
	std::cout << "input last_name" << std::endl;
	std::cin >> last_name;
	std::cout << "input nickname" << std::endl;
	std::cin >> nickname;
	std::cout << "input phone_number" << std::endl;
	std::cin >> phone_number;
	std::cout << "input darkest_secret" << std::endl;
	std::cin >> darkest_secret;
}

void PhoneBook::search()
{
	// 인덱스 추가
	std::cout << first_name;
	std::cout << " | ";
	std::cout << last_name;
	std::cout << " | ";
	std::cout << nickname << std::endl;
}

int main(void)
{
	std::string	cmd;
	PhoneBook pb;

	// std::getline(std::cin, cmd);
	for (;;)
	{
		std::cout << "Enter the command(ADD, SEARCH, EXIT)" << std::endl;
		std::cin >> cmd;
		if (std::cin.eof())
			return 0;
		if (cmd == "ADD")
			pb.add();
		else if (cmd == "SEARCH")
			pb.search();
		else if (cmd == "EXIT")
			break ;
	}
	return 0;
}