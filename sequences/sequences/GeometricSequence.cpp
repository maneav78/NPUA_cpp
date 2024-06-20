#include "GeopetricSequence.h"
#include <cmath>

using namespace std;

GeometricSequence::GeometricSequence(double b1, double q)
{
	setValues(b1, q);
}
GeometricSequence::~GeometricSequence()
{
	cout << "GeometricSequence destructr workd!" << endl;
}
void GeometricSequence::setValues(double b1, double q)
{
	this->b1 = b1 != 0 ? b1 : 1;
	this->q = q != 0 ? q : 2;
}


double GeometricSequence::findTheMember(int n) const
{
	return b1 * pow(q, n - 1);
}

double GeometricSequence::findTheSum(int n) const
{
	return b1 * (pow(q, n) - 1) / (q - 1);
}
bool GeometricSequence::operator<(const GeometricSequence& other) const
{
	return this->findTheMember(10) < other.findTheMember(10);
}
bool GeometricSequence::operator>(const GeometricSequence& other) const
{
	return this->findTheMember(10) > other.findTheMember(10);
}
ostream& operator<<(ostream& os, GeometricSequence& gs)
{
	os << "GeometricSequence with first number" << gs.b1 << "and q" << gs.q << endl;
	return os;
}
istream& operator>>(istream& in, GeometricSequence& gs)
{
	in >> gs.b1 >> gs.q;
	gs.setValues(gs.b1, gs.q);
	return in;
}
