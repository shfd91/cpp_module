#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

class Convert
{
	private:
		std::string _input;
		double _value;
		char *_ptr;
		bool _attachZero;
		int _sign;
	public:
		Convert();
		Convert(std::string str);
		Convert(Convert &copy);
		Convert &operator=(Convert &copy);
		~Convert();

		void toChar(double value);
		void toInt(double value);
		void toFloat(double value, bool attachZero, int sign);
		void toDouble(double value, bool attachZero, int sign);
		void exeConvert();
		int typeCheck();

};

#endif