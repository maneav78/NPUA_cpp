#pragma once
#include "Sequence.h"
#include <iostream>

using namespace std;

class GeopetricSequence :public Sequence
{
private:
    double b1, q;
public:
    GeopetricSequence(double b1 = 1, double q = 2);
    virtual ~GeopetricSequence();
    void setValues(double b1, double q);
    double findTheMember(int n) const;
    double findTheSum(int n) const;
    double getq() const { return q; };
    double getb1() const { return b1; };

    friend ostream& operator<<(ostream& os, const GeopetricSequence& gs);
    friend istream& operator>>(istream& in, GeopetricSequence& gs);
};
