#include "Sphere.h"
#include <cmath>


Sphere::Sphere(double r)
{
    setValues(r);
}

Sphere::~Sphere()
{
   // cout << "Sphere destructor worked!" << endl;
}

void Sphere::setValues(double r)
{
    this->r = r > 0 ? r : 1;
}

double Sphere::area() const
{
    return 4 * 3.14 * r * r;
}

double Sphere::perimeter() const
{
    return 2 * 3.14 * r;
}

double Sphere::volume() const {
    return (4.0 / 3.0) * 3.14 * r * r * r;
}

void Sphere::print(ostream& os) const
{
    os << "Sphere radius: " << r << endl;
}

bool Sphere::operator<(const Sphere& other) const
{
    return r < other.r;
}

bool Sphere::operator>(const Sphere& other) const
{
    return r > other.r;
}


