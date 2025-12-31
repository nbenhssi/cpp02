#include "Fixed.hpp"

Fixed::Fixed():fixed_point(0)
{
    std::cout<< "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed &fixed)
{
    this->fixed_point = fixed.fixed_point;
    std::cout<< "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout<< "Destructor called" << std::endl;    
}

Fixed Fixed::operator=(Fixed &fixed)
{
    this->fixed_point = fixed.fixed_point;
    std::cout<< "Copy assignment operator called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout<< "getRawBits member function called" << std::endl;
    return this->fixed_point;
}

void Fixed::setRawBits(int const raw)
{
    this->fixed_point = raw;
}

//
Fixed::Fixed(const int point)
{
    this->fixed_point = point * this->fractional_bits;
}

Fixed::Fixed(int fixed_point)
{
    fixed_point = this->fixed_point / this->fractional_bits;
}

float Fixed::toFloat( void ) const
{

}

int Fixed::toInt( void ) const
{

}

//op