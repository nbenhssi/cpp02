#include "Point.hpp"


Point::Point() : x(0), y(0) {}

Point::Point(float const a, float const b) : x(a), y(b) {}

Point::Point(Point const &point) : x(point.x), y(point.y) {}

Point& Point::operator=(Point const &point)
{
    (void)point;
    return *this;
}

Fixed Point::getX() const
{
    return this->x;
}

Fixed Point::getY() const
{
    return this->y;
}

Point::~Point(){}

static Fixed area(Point const a, Point const b, Point const c)
{
    Fixed area = ((a.getX() * (b.getY() - c.getY())) +
                  (b.getX() * (c.getY() - a.getY())) +
                  (c.getX() * (a.getY() - b.getY()))) / Fixed(2);
    
    return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{

    Fixed ABC = area(a, b, c);
    Fixed PAB = area(point, a, b);
    Fixed PBC = area(point, b, c);
    Fixed PCA = area(point, c, a);

    if (PAB == Fixed(0) || PBC == Fixed(0) || PCA == Fixed(0))
        return false;
   
    return (ABC == (PAB + PBC + PCA));
}