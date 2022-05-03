/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slee2 <slee2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 02:33:31 by slee2             #+#    #+#             */
/*   Updated: 2021/11/23 02:51:56 by slee2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(): name("default"), grade(0) {
	std::cout << "Data class make : " << this->name << this->grade << std::endl;
}

Data::Data(std::string _name, int _grade): name(_name), grade(_grade) {
	std::cout << "Data class make : " << this->name << this->grade << std::endl;
}

Data::~Data() {
	std::cout << "remove Data" << std::endl;
}

Data::Data(Data const& a) {
	*this = a;
}

Data& Data::operator=(Data const &c) {
	this->name = c.getName();
	this->grade = c.getGrade();
	return *this;
}

std::string Data::getName() const {
	return this->name;
}

int Data::getGrade() const {
	return this->grade;
}

uintptr_t	serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}