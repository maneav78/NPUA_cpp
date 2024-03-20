#include "circle.h"
#include "math.h"
#include <string>

Circle::Circle(double x = 0, double y = 0, double r = 1)
{
    setParametrs(x, y, r);
}

Circle::Circle(Circle& obj)
{
    setParametrs(obj.p.x, obj.p.y, obj.r);
}

Circle::~Circle()
{
    cout << "The Circle was destroyed!" << endl;
}

double Circle::getR() const
{
    return r;
}

void Circle::getCenter() const
{
    cout << "Center coordinates: (" << p.x << "," << p.y << ")" << endl;
}

void Circle::setParametrs(double x, double y, double r)
{
    if (r < 0) { cout << "R must be grather than 0"; return; }
    this->p.x = x;
    this->p.y = y;
    this->r = r;
}

ostream& operator<<(ostream& os, const Circle& c)
{
    os << "Circle with center coordinates: (" << c.p.x << "," << c.p.y << ") and with radius: " << c.r << endl;
    return os;
}

istream& operator>>(istream& is, Circle& c)
{
    double x, y, r;
    cout << "Give x, y and r: ";
    is >> x >> y >> r;
    c.setParametrs(x, y, r);
    return is;
}

bool Circle::operator==(const Circle& other)
{
    if (p.x == other.p.x && p.y == other.p.y && r == other.r) return true;
    return false;
}

bool Circle::operator!=(const Circle& c)
{
    return !(*this == c);
}

bool Circle::operator>(const Circle& c)
{
    if (this->r > c.r) return true;
    return false;
}

bool Circle::operator<(const Circle& c)
{
    return !(*this > c);
}

bool Circle::isPointOn(double x, double y)
{
    if (sqrt((x - p.x) * (x - p.x) - (y - p.y) * (y - p.y)) == r) return true;
    return false;   
}

int Circle::countOfHatums(const Circle& c) 
{
    if (*this == c) return -1;
    if (r + c.r == this->distanceOfCenters(c)) return 1;
    if (r + c.r < this->distanceOfCenters(c)) return 2;
    else return 0;
}

void Circle::tangentEquation(Point p)
{
    
    double distance = sqrt((p.x - this->p.x) * (p.x - this->p.x) + (p.y - this->p.y) * (p.y - this->p.y));

    if (distance > r) {
        cout << "Point is not on the circle, no tangent exists." << endl;
        return;
    }
    double k_part1 = -(this->p.x - p.x);
    double k_part2 = this->p.y - p.y;
    double b = (p.y*k_part2 - k_part1*p.x)/k_part2;
    cout << "Tangent equation from the circle to the given point (" << p.x << ", " << p.y << "):";
    if (k_part2 == 0) {
        cout << "y = " << p.y << endl; 
    }
    else if (k_part1 == 0) {
        cout << "x = " << p.x << endl; 
    }
    else {

        int divisor = gcd(abs(k_part1), abs(k_part2));
        k_part1 /= divisor;
        k_part2 /= divisor;

        double b = (p.y * k_part2 - k_part1 * p.x) / k_part2;
        if (k_part1 * k_part2 < 0) {
            k_part1 = -abs(k_part1);
            k_part2 = abs(k_part2);
        }
        cout << "y = " << k_part1 << "/" << k_part2 << "x + " << b << endl;
    }
}

double Circle::length() const
{
    return 2*3.14*r;
}

double Circle::area() const
{
    return 3.14*r*r;
}

double Circle::distanceOfCenters(const Circle& c2) const
{
    return sqrt((p.x - c2.p.x) * (p.x - c2.p.x) + (p.y - c2.p.y) * (p.y - c2.p.y));
}

void Circle::xParallelMoveing(double step)
{
    p.x += step;
}

void Circle::yParallelMoveing(double step)
{
    p.y += step;
}

void Circle::changeAreaByK(double k)
{
    r = r * sqrt(k);
}





