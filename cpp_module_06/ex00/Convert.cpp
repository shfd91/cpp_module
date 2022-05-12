#include "Convert.hpp"

Convert::Convert()
{

}

Convert::Convert(std::string str) : _input(str), _ptr(NULL), _attachZero(true), _minus(false)
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
	this->_minus = copy._minus;
	return (*this);
}

Convert::~Convert()
{

}

void Convert::toChar(double value)
{
	std::stringstream sstrm;
	sstrm << "char: ";
	if (isnan(value) || isinf(value))
		sstrm << "imposible";
	else if (value < 32 || value > 126)
		sstrm << "Non displayable";
	else
		sstrm << "\'" << static_cast<char>(value) << "\'";
	std::cout << sstrm.str() << std::endl;

}

void Convert::toInt(double value)
{
	std::stringstream sstrm;
	sstrm << "int: ";
	if ((isnan(value) || isinf(value)) || value > INT_MAX || value < INT_MIN)
		sstrm << "imposible";
	else
		sstrm << static_cast<int>(value);
	std::cout << sstrm.str() << std::endl;
}

void Convert::toFloat(double value, bool attachZero, bool minus)
{
	std::stringstream sstrm;
	sstrm << "float: ";
	if (isnan(value))
		sstrm << "nanf";
	else if (isinf(value))
	{
		if (minus == true)
			sstrm << "-";
		sstrm << "inff";
	}
	else if (attachZero == true)
		sstrm << static_cast<float>(value) << ".0f";
	else
		sstrm << static_cast<float>(value) << "f";
	std::cout << sstrm.str() << std::endl;
}

void Convert::toDouble(double value, bool attachZero, bool minus)
{
	std::stringstream sstrm;
	sstrm << "double: ";
	if (isnan(value))
		sstrm << "nan";
	else if (isinf(value))
	{
		if (minus == true)
			sstrm << "-";
		sstrm << "inf";
	}
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
	toFloat(_value, _attachZero, _minus);
	toDouble(_value, _attachZero, _minus);
}

int Convert::typeCheck()
{
	int length = _input.length();
	if (_input[0] == '-')
		_minus = true;
	if ((length == 1) && ((_input[0] > 31 && _input[0] < 48) || (_input[0] > 57 && _input[0] < 127)))
	{
		_value = static_cast<int>(_input[0]);
		return (0);
	}
	_value = std::strtod(_input.c_str(), &_ptr);
	int temp = _input.find('.');
	if (temp != -1)
	{
		for (int i = temp + 1; i < _input[i]; i++)
		{
			if ((_input[i] != '0' && _input[i] != '\0') && (_input[i] != 'f'))
					_attachZero = false;
		}
	}
	if ((_input[0] == '0' && (_input[1] == '\0')) || (_ptr[0] == 'f' && _ptr[1] == '\0'))
		;
	else if ((length > 1 && _value == 0) && (_ptr[0] != 'f' && _ptr[0]))
	{
		std::cout << "Invalid input\n";
		return (1);
	}
	return (0);
}