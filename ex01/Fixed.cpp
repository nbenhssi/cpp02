#include "Fixed.hpp"

Fixed::Fixed() : fixed_point(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int point)
{
    std::cout << "Int constructor called" << std::endl;
    fixed_point = point << fractional_bits;
}

Fixed::Fixed(const float point)
{
    std::cout << "Float constructor called" << std::endl;
    fixed_point = roundf(point * (1 << fractional_bits));
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    fixed_point = fixed.fixed_point;
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        fixed_point = fixed.fixed_point;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return fixed_point;
}

void Fixed::setRawBits(int const raw)
{
    fixed_point = raw;
}

float Fixed::toFloat(void) const
{
    return (float)fixed_point / (1 << fractional_bits);
}

int Fixed::toInt(void) const
{
    return fixed_point >> fractional_bits;
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
