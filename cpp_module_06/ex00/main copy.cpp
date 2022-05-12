/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slee2 <slee2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:30:53 by slee2             #+#    #+#             */
/*   Updated: 2021/11/23 16:13:14 by slee2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>

bool	check_num(char *str, bool *point_zero) {
	int i = 0;
	bool include_point = false;
	int len;

	len = strlen(str);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while(i < len) {
		if (str[i] == '.' && include_point == false) {
			int j = i + 1;
			while(j < len) {
				if (str[j] != '0')
					break;
				j++;
			}
			if (j == len)
				*point_zero = true;
			include_point = true;
		}
		else if (str[i] > '9' || str[i] < '0')
			return false;
		i++;
	}
	if (include_point == false)
		*point_zero = true;
	return true;
}

void	c_char(long double l, bool parse) {
	int val = (int)l;

	std::cout << "char: ";
	if (parse == false)
		std::cout << "impossible" << std::endl;
	else if (val < 33 || val > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" << (char)val << "\'" << std::endl;
}

void	c_int(long double l, bool parse) {
	int val = (int)l;

	std::cout << "int: ";
	if (parse == false)
		std::cout << "impossible" << std::endl;
	else
		std::cout << val << std::endl;
}

void	c_float(long double l, bool parse, bool point_zero, std::string signal) {
	float val = (float)l;
	std::string f_signal[] = {"-inff", "+inff", "nanf"};

	if (signal == "-inf")
		signal = f_signal[0];
	else if (signal == "+inf")
		signal = f_signal[1];
	else if (signal == "nan")
		signal = f_signal[2];

	std::cout << "float: ";
	if (parse == false && signal == "none")
		std::cout << "impossible" << std::endl;
	else if (parse == false)
		std::cout << signal << std::endl;
	else if (point_zero == true)
		std::cout << val << ".0f" << std::endl;
	else
		std::cout << val << "f" << std::endl;
}

void	c_double(long double l, bool parse, bool point_zero, std::string signal) {
	double val = (double)l;
	std::string f_signal[] = {"-inf", "+inf", "nan"};

	if (signal == "-inff")
		signal = f_signal[0];
	else if (signal == "+inff")
		signal = f_signal[1];
	else if (signal == "nanf")
		signal = f_signal[2];

	std::cout << "double: ";
	if (parse == false && signal == "none")
		std::cout << "impossible" << std::endl;
	else if (parse == false)
		std::cout << signal << std::endl;
	else if (point_zero == true)
		std::cout << val << ".0" << std::endl;
	else
		std::cout << val << std::endl;
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return 0;
		
	std::string str(argv[1]);

	bool parse = false;
	bool point_zero = false;
	
	std::string signal;
	std::string special[] = {"-inff", "-inf", "+inff", "+inf", "nanf", "nan"};
	int	i = std::find(special, special + 6, str) - special;
	if (i == 6)
		signal = "none";
	else
		signal = special[i];
		
	if (argv[1][strlen(argv[1]) - 1] == 'f') {
		argv[1][strlen(argv[1]) -1] = 0;
		str = str.substr(0, str.length() - 1);
	}

	parse = check_num(argv[1], &point_zero);

	long double l = 0.0;

	std::stringstream sslongDouble(str);
	sslongDouble >> l;
	
	c_char(l, parse);
	c_int(l, parse);
	c_float(l, parse, point_zero, signal);
	c_double(l, parse, point_zero, signal);

	return 0;
}