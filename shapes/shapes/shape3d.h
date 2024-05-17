#pragma once
#include <iostream>
using namespace std;

class Shape3d {
public:
    virtual ~Shape3d(){
        // std::cout << "Shape destructor worked!" << std::endl;
    };
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual double volume() const = 0;

    virtual void print(ostream& os) const = 0;

    friend ostream& operator<<(ostream& os, const Shape3d& shape) {
        shape.print(os);
        return os;
    }
};


