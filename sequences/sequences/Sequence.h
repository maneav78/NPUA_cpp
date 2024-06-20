#pragma once
#include <iostream>

class Sequence {
public:
    virtual ~Sequence() {};
    virtual double findTheMember(int n) const = 0;
    virtual double findTheSum(int n) const = 0;

    friend std::ostream& operator<<(std::ostream& out, const Sequence&);
    friend std::istream& operator>>(std::istream& in, Sequence&);
};

