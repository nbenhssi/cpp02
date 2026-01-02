#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	Point inside(2, 2);
	Point outside(10, 10);
	Point edge(0, 0);

	std::cout << "Inside (2,2): "
			  << (bsp(a, b, c, inside) ? "TRUE" : "FALSE")
			  << std::endl;

	std::cout << "Outside (10,10): "
			  << (bsp(a, b, c, outside) ? "TRUE" : "FALSE")
			  << std::endl;

	std::cout << "On vertex (0,0): "
			  << (bsp(a, b, c, edge) ? "TRUE" : "FALSE")
			  << std::endl;

	return 0;
}
