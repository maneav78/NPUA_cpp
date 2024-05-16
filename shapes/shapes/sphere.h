#pragma once
#include "Shape3d.h"


class Sphere : public Shape3d
{
private:
    double r;

public:
    Sphere(double r = 1);
    virtual ~Sphere();

    void setValues(double r);
    double area() const override;
    double perimeter() const override;
    double volume() const override;
    void print(ostream& os) const override;
    bool operator<(const Sphere& other) const;
    bool operator>(const Sphere& other) const;

    
};
