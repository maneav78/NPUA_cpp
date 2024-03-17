#include "point.h"
#include <math.h>


Point::Point()
{
    x = y = 0;
    //setXY(0,0);
}

Point::Point(double x, double y)
{
    this->x = x;
    (*this).y = y;
    //setXY(x, y);
}

Point::Point(const Point& ob)
{
    this->x = ob.x;
    this->y = ob.y;
}

Point::~Point()
{
    cout << "The Point was destroyed!" << endl;
}


double Point::getX() const
{
    return x;
}


double Point::getY() const
{
    return y;
}

void Point::setXY(double x, double y)
{
    this->x = x;
    this->y = y;
}

ostream& operator<<(ostream& os, const Point& point)
{
    os << "(" << point.getX() << "," << point.getY() << ")" << endl;
    return os;
}

istream& operator>>(istream& is, Point& point)
{
    cout << "Insert object coordinates: ";
    //double x, y;
    //is >> x >> y;
    //point.setXY(x, y);
    is >> point.x >> point.y;
    return is;
}

int Point::getQuater() const {
    if (x == 0 && y == 0) return 0;
    if (y > 0) {
        if (x > 0) return 1;
        else return 2;
    }
    else {
        if (x > 0) return 4;
        else return 3;
    }
}

bool Point::operator==(const Point& other) const
{
    return x == other.x && y == other.y;
}

bool Point::operator!=(const Point& other)
{
    return !(*this == other);
}

double Point::distance(const Point& other) const
{
    return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
}

double Point::distanceFromZero() const
{
    return sqrt(x * x + y * y);
}

Point& Point::xParallelMoveing(double step)
{
    x += step;
    return *this;
}

Point& Point::yParallelMoveing(double step)
{
    y += step;
    return *this;
}

Point& Point::operator=(const Point& other)
{

    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}