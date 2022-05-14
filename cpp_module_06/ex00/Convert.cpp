#include "Convert.hpp"

Convert::Convert()
{

}

Convert::Convert(std::string str) : _input(str), _ptr(NULL), _attachZero(true), _sign(0)
{

}

Convert::Convert(Convert &copy)
{
	*this = copy;
}

Convert &Convert::operator=(Convert &copy)
{
	this->_input = copy._input;
	this->_value = copy._value;
	this->_ptr = copy._ptr;
	this->_attachZero = copy._attachZero;
	this->_sign = copy._sign;
	return (*this);
}

Convert::~Convert()
{

}

void Convert::toChar(double value)
{
	char max = std::numeric_limits<char>::max();
	char min = std::numeric_limits<char>::min();
	std::stringstream sstrm;
	sstrm << "char: ";
	if (isnan(value) || isinf(value) || (value > max || value < min))
		sstrm << "imposible";
	else if (value < 32 || value > 126)
		sstrm << "Non displayable";
	else
		sstrm << "\'" << static_cast<char>(value) << "\'";
	std::cout << sstrm.str() << std::endl;

}

void Convert::toInt(double value)
{
	int max = std::numeric_limits<int>::max();
	int min = std::numeric_limits<int>::min();
	std::stringstream sstrm;
	sstrm << "int: ";
	if ((isnan(value) || isinf(value)) || value > max || value < min)
		sstrm << "imposible";
	else
		sstrm << static_cast<int>(value);
	std::cout << sstrm.str() << std::endl;
}

void Convert::toFloat(double value, bool attachZero, int sign)
{
	float max = std::numeric_limits<float>::max();
	std::stringstream sstrm;
	sstrm << "float: ";
	if (isnan(value))
		sstrm << "nanf";
	else if (isinf(value))
	{
		if (sign == -1)
			sstrm << "-";
		else if (sign == 1)
			sstrm << "+";
		sstrm << "inff";
	}
	else if (value > max || value < -max)
		sstrm << "imposible";
	else if (attachZero == true)
		sstrm << static_cast<float>(value) << ".0f";
	else
		sstrm << static_cast<float>(value) << "f";
	std::cout << sstrm.str() << std::endl;
}

void Convert::toDouble(double value, bool attachZero, int sign)
{
	double max = std::numeric_limits<double>::max();
	std::stringstream sstrm;
	sstrm << "double: ";
	if (isnan(value))
		sstrm << "nan";
	else if (isinf(value))
	{
		if (sign == -1)
			sstrm << "-";
		else if (sign == 1)
			sstrm << "+";
		sstrm << "inf";
	}
	else if (value > max || value < -max)
		sstrm << "imposible";
	else if (attachZero == true)
		sstrm << static_cast<double>(value) << ".0";
	else
		sstrm << static_cast<double>(value);
	std::cout << sstrm.str() << std::endl;
}

void Convert::exeConvert()
{
	toChar(_value);
	toInt(_value);
	toFloat(_value, _attachZero, _sign);
	toDouble(_value, _attachZero, _sign);
}

int Convert::typeCheck()
{
	int length = _input.length();
	if ((length == 1) && ((_input[0] > 31 && _input[0] < 48) || (_input[0] > 57 && _input[0] < 127)))
	{
		_value = static_cast<char>(_input[0]);
		return (0);
	}
	if (_input[0] == '-')
		_sign = -1;
	else if (_input[0] == '+')
		_sign = 1;
	int dot_index = _input.find('.');
	if (dot_index != -1)
	{
		for (int i = dot_index + 1; i < length; i++)
		{
			if ((_input[i] != '0' && _input[i] != '\0') && (_input[i] != 'f'))
				_attachZero = false;
		}
	}
	_value = std::strtod(_input.c_str(), &_ptr);
	if ((length > 1 && _value == 0) && (_ptr[0] && _ptr[0] != 'f'))
	{
		std::cout << "Invalid input\n";
		return (1);
	}
	return (0);
}