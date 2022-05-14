#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

typedef struct s_Data
{
	std::string data;
} Data;

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);

#endif