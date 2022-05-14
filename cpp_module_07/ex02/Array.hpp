#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
	private:
		T *_arr;
		std::size_t _size;
	public:
		Array() : _arr(NULL), _size(0) {}
		Array(unsigned int n) : _arr(NULL), _size(n)
		{
			if (n > 0)
				_arr = new T[n];
		}
		Array(const Array &copy) : _arr(NULL), _size(copy.size())
		{
			if (_size > 0)
				_arr = new T[_size];
			for (std::size_t i = 0; i < _size; i++)
				_arr[i] = copy[i];
		}
		Array &operator=(const Array &copy)
		{
			if (_size > 0)
			{
				delete[] _arr;
				_arr = NULL;
				_size = 0;
			}
			_size = copy.size();
			if (_size > 0)
				_arr = new T[_size];
			for (std::size_t i = 0; i < _size; i++)
				_arr[i] = copy[i];
			return *this;
		}
		~Array()
		{
			if (_size > 0)
			{
				delete[] _arr;
				_arr = NULL;
				_size = 0;
			}
		}

		std::size_t size() const
		{
			return (_size);
		}
		T& operator[](std::size_t n)
		{
			if (n >= _size)
				throw (OutOfRangeException());
			return (_arr[n]);
		}
		T& operator[](std::size_t n) const
		{
			if (n >= _size)
				throw (OutOfRangeException());
			return (_arr[n]);
		}
		class OutOfRangeException : public std::exception
		{
			public:
				const char* what(void) const throw()
				{
					return ("out of range");
				}
		};

};

#endif