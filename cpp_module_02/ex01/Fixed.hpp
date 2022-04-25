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
		Fixed(const int value); // int형을 받아 변환하는 생성자
		Fixed(const float value); // 실수(부동 소수점)을 받아 고정 소수점으로 변환 생성자
		~Fixed(); // 소멸자
		Fixed &operator=(Fixed const &obj);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const; // 고정 소수점을 실수로 변환
		int toInt(void) const; // 고정 소수점을 정수로 변환
};

std::ostream &operator<<(std::ostream &out, Fixed const &obj); // 고정 소수점 값의 부동 소수점 표현을 매개변수 출력 스트림에 삽입하는 « 연산자에 대한 오버로드

#endif