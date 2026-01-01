#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int fixed_point;
        static const int fractional_bits = 8;
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
        bool operator>(Fixed fixed);
        bool operator<(Fixed fixed);
        bool operator>=(Fixed fixed);
        bool operator<=(Fixed fixed);
        bool operator==(Fixed fixed);
        bool operator!=(Fixed fixed);

        Fixed operator+(Fixed fixed);
        Fixed operator-(Fixed fixed);
        Fixed operator*(Fixed fixed);
        Fixed operator/(Fixed fixed);

        Fixed& operator++(void);
        Fixed operator++(int);
        Fixed& operator--(void);
        Fixed operator--(int);
        

        static Fixed& min(Fixed &a, Fixed &b);
        static const Fixed& min(const Fixed &a, const Fixed &b);
        static Fixed& max(Fixed &a, Fixed &b);
        static const Fixed& max(const Fixed &a, const Fixed &b);
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif
    