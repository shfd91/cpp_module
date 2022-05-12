#include "Base.hpp"

#include <typeinfo> // 지울 것
int main()
{
	Base *b = generate();
	std::cout << "Pointer Type : ";
	identify(*b);
	std::cout << "Reference Type : ";
	identify(b);

	delete b;

	std::cout << std::endl;
	// 실패 케이스 (부모 포인터가 부모 객체를 가리키고 있음)
	Base *base = new Base();
	base = dynamic_cast<A*>(base);
	if (base == nullptr)
		std::cout << "NULL ptr\n";
	else
		std::cout << "형변환 성공\n";
	std::cout << "typeid : " << typeid(base).name() << std::endl;
	delete base;

	std::cout << std::endl;
	// 성콩 케이스 (부모 포인터가 자식 객체를 가리키고 있음)
	base = new A();
	base = dynamic_cast<A*>(base);
	if (base == nullptr)
		std::cout << "NULL ptr\n";
	else
		std::cout << "형변환 성공\n";
	std::cout << "typeid : " <<typeid(base).name() << std::endl;
	delete base;


	return 0;
}

/*
- void identify(Base* p)는 cast return이 NULL인지 확인해야 합니다.
- void identify(Base& p)는 캐스트가 실패했는지 확인하기 위해 try 및 catch 블록을 사용해야 합니다.
 */