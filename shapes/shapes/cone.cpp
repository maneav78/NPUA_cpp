#include "Cone.h"
#include <cmath>


Cone::Cone(double r, double h) {
    setValues(r, h);
}

Cone::~Cone() {
    //cout << "Cone destructor worked!" << endl;
}

void Cone::setValues(double r, double h) {
    this->r = r > 0 ? r : 1;
    this->h = h > 0 ? h : 1;
}

double Cone::area() const {
    //koxmnayinn a
    double l = sqrt(h * h + r * r);
    return 3.14 * r * l;
}

double Cone::perimeter() const {
    return 2 * 3.14 * r;
}

double Cone::volume() const {
    return (3.14 * r * r * h) / 3.0;
}

void Cone::print(ostream& os) const
{
    os << "Cone with radius " << r << " and height " << h << endl;
}


bool Cone::operator<(const Cone& other) const {
    return this->perimeter() < other.perimeter();
}

bool Cone::operator>(const Cone& other) const {
    return this->perimeter() > other.perimeter();
}

