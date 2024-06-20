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
    double area() const;
    double volume() const;
    void print() const;
 
};
