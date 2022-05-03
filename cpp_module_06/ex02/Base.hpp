/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slee2 <slee2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:45:48 by slee2             #+#    #+#             */
/*   Updated: 2021/11/23 15:06:39 by slee2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <exception>

class Base {
	public:
		virtual ~Base() {};
};

class A: public Base {};

class B: public Base {};

class C: public Base {};


Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif