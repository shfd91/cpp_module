#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <climits>

class Convert
{
	private:
		std::string _input;
		double _value;
		char *_ptr;
		bool _attachZero;
		bool _minus;
	public:
		Convert();
		Convert(std::string str);
		Convert(Convert &copy);
		Convert &operator=(Convert &copy);
		~Convert();

		void toChar(double value);
		void toInt(double value);
		void toFloat(double value, bool attachZero, bool minus);
		void toDouble(double value, bool attachZero, bool minus);
		void exeConvert();
		int typeCheck();

};

#endif