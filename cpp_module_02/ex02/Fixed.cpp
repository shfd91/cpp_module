#include "Fixed.hpp"

int const Fixed::_bits = 8;

Fixed::Fixed()
{
	_value = 0;
}

Fixed::Fixed(const Fixed &obj)
{
	*this = obj;
}

Fixed::Fixed(const int value)
{
	_value = value << _bits;
}

Fixed::Fixed(const float value)
{
	_value = (roundf(value * (1 << _bits)));
}

Fixed::~Fixed()
{

}

Fixed &Fixed::operator=(Fixed const &obj)
{
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
	Fixed f(this->toFloat());
	f._value += obj._value;
	return (f);
}

Fixed	Fixed::operator-(Fixed const &obj)
{
	Fixed f(this->toFloat());
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
	Fixed f(this->toFloat());
	f._value /= obj.toFloat();
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
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)_value / (1 << _bits));
}

int Fixed::toInt(void) const
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

std::ostream &operator<<(std::ostream &out, Fixed const &obj)
{
	out << obj.toFloat();
	return out;
}