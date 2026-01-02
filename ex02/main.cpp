#include "Fixed.hpp"

int main( void )
{

    Fixed a;
    Fixed const b(10);
    Fixed const c( 42.42f );
    Fixed const d(b);

    a = Fixed(1234.4321f);

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    Fixed x(5.5f);
    Fixed y(2.25f);

    float fx = x.toFloat();
    float fy = y.toFloat();

    std::cout << "\n[Fixed vs float arithmetic]\n";
    std::cout << "Fixed add: " << (x + y) << " | float add: " << fx + fy << std::endl;
    std::cout << "Fixed sub: " << (x - y) << " | float sub: " << fx - fy << std::endl;
    std::cout << "Fixed mul: " << (x * y) << " | float mul: " << fx * fy << std::endl;
    std::cout << "Fixed div: " << (x / y) << " | float div: " << fx / fy << std::endl;

    return 0;
}