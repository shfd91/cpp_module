/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghole <sanghole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:03:56 by sanghole          #+#    #+#             */
/*   Updated: 2022/03/15 17:17:16 by sanghole         ###   ########.fr       */
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
			std::cout << strlen(argv[i]) << std::endl; // 지우기 git test
			// for (int j = 0; j < argv[i][j]; j++)
			for (int j = 0; j < (int)strlen(argv[i]); j++) // strlen 사용 가능?
			{
				if (argv[i][j] == '"')
					j++;
				if (argv[i][j] >= 97 && argv[i][j] <= 122)
					str.append(1, argv[i][j] - 32);
				else
					str.append(1, argv[i][j]);
			}
			str += ' ';
		}
		for (;;)
		{
			if (str.find("  ") != std::string::npos)
				str.replace(str.find("  "), 2, " ");
			else
				break ;
		}
		std::cout << str << std::endl;
	}
	return (0);
}