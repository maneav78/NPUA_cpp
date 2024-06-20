#pragma once
#include "Shape3d.h"


class Cone : public Shape3d {
private:
    double r, h;

public:
    Cone(double r = 1, double h = 1);
    virtual ~Cone();

    void setValues(double r, double h);
    double area() const;
    double volume() const;
    void print() const;
   
};
