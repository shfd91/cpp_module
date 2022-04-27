#ifndef FIXED_HPP
# define FIXED_HPP
#include <string>
#include <iostream>

class Fixed
{
	int _value;
	static int const _bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &obj);
		~Fixed();
		Fixed &operator=(Fixed const &obj);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif