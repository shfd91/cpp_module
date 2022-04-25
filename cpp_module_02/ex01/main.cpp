#include "Fixed.hpp"

int main(void)
{
	Fixed 	a; // 기본 생성자
	Fixed	const b(10); // 정수형 생성자
	Fixed	const c(42.42f); // 실수형 생성자
	Fixed 	const d(b); // 복사 생성자

	a = Fixed(1234.4321f); // 깊은 복사

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}