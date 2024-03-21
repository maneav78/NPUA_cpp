#include <iostream>
using namespace std;

class Cylinder
{
public:
    Cylinder();
    Cylinder(double, double);
    Cylinder(Cylinder&);
    ~Cylinder();
    double getr() const { return r; }
    double geth() const { return h; }
    friend ostream& operator<<(ostream&, const Cylinder&);
    friend istream& operator>>(istream&, Cylinder&);
    bool operator==(const Cylinder&);
    bool operator!=(const Cylinder&);
    bool operator>(const Cylinder&);
    bool operator<(const Cylinder&);
    Cylinder& operator=(const Cylinder&);
    void editVolume(double k);

    double Volume() const;
    double baseSurface() const;
    double sideSurface() const;
    double Surface() const;
    double seperateSurface() const;
    static int getConut() { return count; }

private:
    double r, h;
    static int count;

};

