#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Fixed Point::getX() const
{
    return this->x;
}
Fixed Point::getY() const
{
    return this->y;
}


Point::Point(int const i, int const j) : x(i), y(j) {}

Point::Point(Point const &point): x(point.x), y(point.y) {}

Fixed area(Point const a, Point const b, Point const c)
{
    return ( (a.getX() * (b.getY() - c.getY())) +
             (b.getX() * (c.getY() - a.getY())) +
             (c.getX() * (a.getY() - b.getY())) ) / Fixed(2);
}

bool Point::bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed area1 = area(point, a, b);
    Fixed area2 = area(point, b, c);
    Fixed area3 = area(point, c, a);

    if (area1 > 0 && area2 > 0 && area3 > 0)
        return true;
    return false;
}


Point::~Point(){}