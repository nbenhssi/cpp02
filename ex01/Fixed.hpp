#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int fixed_point;
        static const int fractional_bits;
    public:
        Fixed();
        Fixed(const int point);
        Fixed(const float point);
        Fixed(const Fixed &fixed);
        Fixed& operator=(const Fixed &fixed);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
    };
std::ostream& operator<<(std::ostream &out, const Fixed &fixed);


#endif