#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int fixed_point;
        static const int fractional_bits = 8;
    public:
        Fixed();
        Fixed(Fixed &fixed);
        Fixed operator=(Fixed &fixed);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        //
        Fixed(const int point);
        Fixed(int fixed_point);
        float toFloat( void ) const;
        int toInt( void ) const;
        //op
};