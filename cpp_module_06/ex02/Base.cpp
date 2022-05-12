#include "Base.hpp"
#include <iostream>

Base*	generate(void) {
	int num;
	srand(time(0));
	num = rand() % 3;
	switch(num)
	{
		case 0:
			std::cout << "return A class" << std::endl;
			return (new A());
		case 1:
			std::cout << "return B class" << std::endl;
			return (new B());
		case 2:
			std::cout << "return C class" << std::endl;
			return (new C());
	}
	return NULL;
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p) != nullptr)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != nullptr)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != nullptr)
		std::cout << "C" << std::endl;
}

// 이 함수 내에서 포인터 사용 금지
void	identify(Base& p) {
	if (dynamic_cast<A*>(&p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(&p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(&p))
		std::cout << "C" << std::endl;

}

// void	identify(Base& p) {
// 	try
//	{
// 		A &a = dynamic_cast<A&>(p);
// 		(void)a;
// 		std::cout << "A" << std::endl;
// 		return ;
// 	} catch(std::exception& e)
//	{
// 	}
// 	try {
// 		B &b = dynamic_cast<B&>(p);
// 		(void)b;
// 		std::cout << "B" << std::endl;
// 		return ;
// 	} catch(std::exception&) {
// 	}
// 	try {
// 		C &c = dynamic_cast<C&>(p);
// 		(void)c;
// 		std::cout << "C" << std::endl;
// 		return ;
// 	} catch(std::exception&) {
// 	}
// }

