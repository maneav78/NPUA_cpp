#include "times.h"
#include <iomanip>

Times::Times(int h, int m, int s) : Time(h, m) {
	setSecond(s);
}

void Times::setSecond(int s)
{
	second = (s >= 0 && s < 60) ? s : 0;
}


int Times::getSecond() const
{
	return second;
}


ostream& operator<<(ostream& os , const Times& time)
{
	Time t(time.hour, time.minute);
	cout << t;
	os << ":" << setfill('0') << setw(2) << time.second << endl;
	return os;
}

istream& operator>>(istream& is, Times& time)
{
	Time& t = time;
	is >> t;
	cout << "Whats the second? ";
	is >> time.second;
	time.setSecond(time.second);
	return is;
	
}

