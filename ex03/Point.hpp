#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point
{
    private:
        const Fixed x;
        const Fixed y;
    public:
        Point();
        Point(int const i, int const y);
        Point(Point &point);
        Point& operator=(Point &point) = delete;
        bool bsp( Point const a, Point const b, Point const c, Point const point);
        ~Point();
        Fixed getX() const;
        Fixed getY() const;
};

#endif