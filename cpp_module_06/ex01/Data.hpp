/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slee2 <slee2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 02:31:36 by slee2             #+#    #+#             */
/*   Updated: 2021/11/23 02:54:21 by slee2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

class Data {
	private:
		std::string name;
		int	grade;
	public:
		Data();
		Data(std::string _name, int _grade);
		Data(Data const& a);
		Data& operator=(Data const &c);
		~Data();
		std::string getName() const;
		int getGrade() const;
		void setName(std::string _n) {this->name = _n;}
		void setGrade(int a) {this->grade = a;}
};

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);

#endif