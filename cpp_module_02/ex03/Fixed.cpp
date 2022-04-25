#include "Fixed.hpp"

int const Fixed::_bits = 8;

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const Fixed &obj)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::Fixed(const int value) // fixed(8)로 변환하는 생성자
{
	// std::cout << "Int constructor called" << std::endl;
	_value = value << _bits; 
}

Fixed::Fixed(const float value) // 고정 소수점으로 변환 생성자
{
	// std::cout << "Float constructor called" << std::endl;
	_value = (roundf(value * (1 << _bits))); // * 256
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &obj)
{
	// std::cout << "Assignation operator called" << std::endl;
	_value = obj.getRawBits();
	return (*this);
}

bool	Fixed::operator>(Fixed const &obj)
{
	if (this->_value > obj._value)
		return (1);
	return (0);
}

bool	Fixed::operator<(Fixed const &obj)
{
	if (this->_value < obj._value)
		return (1);
	return (0);
}

bool	Fixed::operator>=(Fixed const &obj)
{
	if (this->_value >= obj._value)
		return (1);
	return (0);
}

bool	Fixed::operator<=(Fixed const &obj)
{
	if (this->_value <= obj._value)
		return (1);
	return (0);
}

bool	Fixed::operator==(Fixed const &obj)
{
	if (this->_value == obj._value)
		return (1);
	return (0);
}

bool	Fixed::operator!=(Fixed const &obj)
{
	if (this->_value != obj._value)
		return (1);
	return (0);
}

Fixed	Fixed::operator+(Fixed const &obj)
{
	Fixed f(*this);
	return (f);
	f._value += obj._value;
}

Fixed	Fixed::operator-(Fixed const &obj)
{
	Fixed f(*this);
	f._value -= obj._value;
	return (f);

}

Fixed	Fixed::operator*(Fixed const &obj)
{
	Fixed f(this->toFloat());
	f._value *= obj.toFloat();
	return (f);
}

Fixed	Fixed::operator/(Fixed const &obj)
{
	Fixed f(*this);
	f._value /= obj._value;
	return (f);
}

Fixed	Fixed::operator++(int)
{
	Fixed f(*this);

	this->_value++;
	return (f);
}

Fixed &	Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed f(*this);

	this->_value--;
	return (f);
}

Fixed &	Fixed::operator--(void)
{
	this->_value++;
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
	return ((float)_value / (1 << _bits)); // _value / 256
}

int Fixed::toInt(void) const // 고정 소수점을 정수 값으로 변환
{
	return (_value >> _bits);
}

Fixed & Fixed::min(Fixed &a, Fixed &b)
{
	if (a._value > b._value)
		return (b);
	return (a);
}

Fixed const & Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a._value > b._value)
		return (b);
	return (a);
}

Fixed & Fixed::max(Fixed &a, Fixed &b)
{
	if (a._value < b._value)
		return (b);
	return (a);
}

Fixed const & Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a._value < b._value)
		return (b);
	return (a);
}

// 고정 소수점 값의 부동 소수점 표현을 매개변수 출력 스트림에 삽입하는 « 연산자에 대한 오버로드
std::ostream &operator<<(std::ostream &out, Fixed const &obj)
{
	out << obj.toFloat();
	return out;
}