#include "Fixed.hpp"

Fixed::Fixed() : fixed_point(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    this->fixed_point = fixed.fixed_point;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;    
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
    {
        this->fixed_point = fixed.fixed_point;
    }
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixed_point;
}

void Fixed::setRawBits(int const raw)
{
    this->fixed_point = raw;
}
