#include "Data.hpp"
#include <sstream>

int main()
{
	Data *a = new Data;
	a->data = "abcdefg";
	std::cout << "[Data]\n[Addr : " << a << "], [String : " << a->data << "]\n" << std::endl;

	std::stringstream ss;
	uintptr_t uintptr = serialize(a);
	ss << "0x" << std::hex << uintptr;
	std::cout << "[Data -> uintptr_t]\n[Addr : " << ss.str() << "]\n" << std::endl;

	a = deserialize(uintptr);
	std::cout << "[uintptr_t -> Data]\n[Addr : " << a << "], [String : " << a->data  << "]" << std::endl;

	delete a;
	return 0;
}