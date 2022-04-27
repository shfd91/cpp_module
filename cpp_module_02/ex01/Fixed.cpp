#include "Fixed.hpp"

int const Fixed::_bits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::Fixed(const int value) // fixed(8)로 변환하는 생성자
{
	std::cout << "Int constructor called" << std::endl;
	_value = value << _bits;
}

Fixed::Fixed(const float value) // 고정 소수점으로 변환 생성자
{
	std::cout << "Float constructor called" << std::endl;
	_value = (roundf(value * (1 << _bits)));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &obj)
{
	std::cout << "Assignation operator called" << std::endl;
	_value = obj.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawbits member function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat(void) const // 고정 소수점을 부동 소수점으로 변환
{
	return ((float)_value / (1 << _bits));
}

int Fixed::toInt(void) const // 고정 소수점을 정수 값으로 변환
{
	return (_value >> _bits);
}

// 고정 소수점 값의 부동 소수점 표현을 매개변수 출력 스트림에 삽입하는 « 연산자에 대한 오버로드
std::ostream &operator<<(std::ostream &out, Fixed const &obj)
{
	out << obj.toFloat();
	return out;
}