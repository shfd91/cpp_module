#include "Data.hpp"
#include <sstream>

int main()
{
	/* Data *a = new Data;
	a->data = "abc";
	std::cout << "[Data] String : " << a->data << ", Addr : " << a << std::endl;

	std::stringstream ss;
	uintptr_t uintptr = serialize(a);
	ss << "0x" << std::hex << uintptr;
	std::cout << "[Data -> uintptr_t] Addr : " << ss.str() << std::endl;

	a = deserialize(uintptr);
	std::cout << "[uintptr_t -> Data] String : " << a->data << ", Addr : " << a << std::endl;

	a->data = "def";
	std::cout << "[Data] String : " << a->data << ", Addr : " << a << std::endl;

	delete a;
	return 0; */

	Data *a = new Data;
	a->data = "abc";
	uintptr_t uint = 10;
	std::cout << uint << std::end;
}