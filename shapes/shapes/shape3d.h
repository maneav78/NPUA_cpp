#pragma once
#include <iostream>
using namespace std;

class Shape3d {
public:
    virtual ~Shape3d(){};
    virtual double area() const = 0;
    virtual double volume() const = 0;

    virtual void print() const = 0;
};


