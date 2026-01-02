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

bool Fixed::operator>(const Fixed &fixed) const
{
    return this->fixed_point > fixed.fixed_point;
}

bool Fixed::operator<(const Fixed &fixed) const
{
    return this->fixed_point < fixed.fixed_point;
}

bool Fixed::operator>=(const Fixed &fixed) const
{
    return this->fixed_point >= fixed.fixed_point;
}

bool Fixed::operator<=(const Fixed &fixed) const
{
    return this->fixed_point <= fixed.fixed_point;
}

bool Fixed::operator==(const Fixed &fixed) const
{
    return this->fixed_point == fixed.fixed_point;
}

bool Fixed::operator!=(const Fixed &fixed) const
{
    return this->fixed_point != fixed.fixed_point;
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
    Fixed result;
    result.setRawBits(this->fixed_point + fixed.fixed_point);
    return result;
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
    Fixed result;
    result.setRawBits(this->fixed_point - fixed.fixed_point);  // FIXED: was reversed
    return result;
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
    Fixed result;

    result.setRawBits((this->fixed_point * fixed.fixed_point) >> fractional_bits);
    return result;
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
    Fixed result;

    result.setRawBits((this->fixed_point << fractional_bits) / fixed.fixed_point);
    return result;
}

Fixed& Fixed::operator++(void)
{
    this->fixed_point++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    this->fixed_point++;
    return temp;
}

Fixed& Fixed::operator--(void)
{
    this->fixed_point--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->fixed_point--;
    return temp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}