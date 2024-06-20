#include "GeopetricSequence.h"
#include <cmath>

using namespace std;

GeopetricSequence::GeopetricSequence(double b1, double q)
{
	setValues(b1, q);
}
GeopetricSequence::~GeopetricSequence()
{
	cout << "GeopetricSequence destructr workd!" << endl;
}
void GeopetricSequence::setValues(double b1, double q)
{
	this->b1 = b1 != 0 ? b1 : 1;
	this->q = q != 0 ? q : 2;
}


double GeopetricSequence::findTheMember(int n) const
{
	return b1 * pow(q, n - 1);
}

double GeopetricSequence::findTheSum(int n) const
{
	return b1 * (pow(q, n) - 1) / (q - 1);
}

ostream& operator<<(ostream& os, const GeopetricSequence& gs)
{
	os << "GeopetricSequence with first number " << gs.getb1() << " and q " << gs.getq() << endl;
	return os;
}

istream& operator>>(istream& in, GeopetricSequence& gs)
{
	double b1, q;
	in >> b1 >> q;
	gs.setValues(b1, q);
	return in;
}
