#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class Fixed
{
	int _value;
	static int const _bits;
	public:
		Fixed();
		Fixed(const Fixed &obj);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();

		Fixed &	operator=(Fixed const &obj);
		bool	operator>(Fixed const &obj);
		bool	operator<(Fixed const &obj);
		bool	operator>=(Fixed const &obj);
		bool	operator<=(Fixed const &obj);
		bool	operator==(Fixed const &obj);
		bool	operator!=(Fixed const &obj);
		Fixed	operator+(Fixed const &obj);
		Fixed	operator-(Fixed const &obj);
		Fixed	operator*(Fixed const &obj);
		Fixed	operator/(Fixed const &obj);
		Fixed	operator++(int);
		Fixed &	operator++(void);
		Fixed	operator--(int);
		Fixed &	operator--(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed &			min(Fixed &a, Fixed &b);
		static Fixed &			max(Fixed &a, Fixed &b);
		static Fixed const &	min(Fixed const &a, Fixed const &b);
		static Fixed const &	max(Fixed const &a, Fixed const &b);
};

std::ostream &operator<<(std::ostream &out, Fixed const &obj); // 고정 소수점 값의 부동 소수점 표현을 매개변수 출력 스트림에 삽입하는 « 연산자에 대한 오버로드

#endif