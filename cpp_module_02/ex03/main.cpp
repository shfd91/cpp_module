#include "Fixed.hpp"

class	Point
{
	Fixed const _x;
	Fixed const _y;
	public:
		Point();
		Point(const Point &point);
		Point(const Fixed &x, const Fixed &y); // 두 개의 상수 부동 소수점을 매개변수로 사용하고 해당 값으로 x 및 y를 초기화하는 생성자.
		~Point();
		Point&	operator=(Point const &point);
		Fixed	get_x(void) const;
		Fixed	get_y(void) const;
};

bool	bsq(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
	return (0);
}