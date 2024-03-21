#include "cylinder.h"

Cylinder::Cylinder()
{
    r = 1;
    h = 1;
    count++;
}

Cylinder::Cylinder(double r, double h)
{
    this->r = r;
    this->h = h;
    count++;
}

Cylinder::Cylinder(Cylinder& obj)
{
    this->r = obj.r;
    this->h = obj.h;
    count++;
}

Cylinder::~Cylinder()
{
    cout << "The Cylinder was destroyed!" << endl;
}

bool Cylinder::operator==(const Cylinder& other)
{
    return r == other.r && h == other.h;
}

bool Cylinder::operator!=(const Cylinder& other)
{
    return !(*this == other);
}

bool Cylinder::operator>(const Cylinder& obj1)
{
    return this->Volume() > obj1.Volume();
}

bool Cylinder::operator<(const Cylinder& obj1) {
    return !(*this > obj1);
}


Cylinder& Cylinder::operator=(const Cylinder& c)
{
    this->r = c.r;
    this->h = c.h;
    return *this;
}

void Cylinder::editVolume(double k)
{
    if (k < 0)
    {
        cout << "k must be grather than 0";
        return;
    }
    h *= k;
}

double Cylinder::Volume() const
{
    return 3.14 * r * r * h;
}

double Cylinder::baseSurface() const
{
    return 3.14 * r * r;
}

double Cylinder::sideSurface() const
{
    return h * 6.28 * r;
}

double Cylinder::Surface() const
{
    return sideSurface() + 2 * baseSurface();
}

double Cylinder::seperateSurface() const
{
    return 2 * r * h;
}
ostream& operator<<(ostream& os, const Cylinder& c)
{
    os << "Cylinder with r -> " << c.getr() << " and h-> " << c.geth() << endl;
    return os;
}
istream& operator>>(istream& is, Cylinder& cyl)
{
    cout << "Give r and h of Cylinder: ";
    is >> cyl.r >> cyl.h;
    return is;
}

int Cylinder::count = 0;
