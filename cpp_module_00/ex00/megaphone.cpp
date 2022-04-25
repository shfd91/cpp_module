/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghole <sanghole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:03:56 by sanghole          #+#    #+#             */
/*   Updated: 2022/04/25 05:07:06 by sanghole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	std::string	str;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			std::string tmp(argv[i]);
			for (int j = 0; j < (int)tmp.length(); j++)
			{
				if (tmp[j] >= 97 && tmp[j] <= 122)
					str.append(1, tmp[j] - 32);
				else
					str.append(1, tmp[j]);
			}
		}
		std::cout << str << std::endl;
	}
	return (0);
}