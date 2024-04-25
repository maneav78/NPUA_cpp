#include "timeS.h"
TimeS::TimeS(int h, int m, int s)
{
	set(h, m, s);
}

void TimeS::set(int h, int m, int s)
{
	Time::set(h, m);
	second = (s >= 0 && s < 60) ? s : 0;
}

void TimeS::print12() const
{
	cout << ((hour == 0 || hour == 12) ? 12 : (hour % 12)) << ":" << minute << ":" << second
		<< ((hour < 12) ? "AM" : "PM") << endl;
}

bool TimeS::operator==(const TimeS& t) const
{
	return (Time::operator==(t) && second == t.second);
}

bool TimeS::operator!=(const TimeS& t) const
{
	return !(*this == t);
}

bool TimeS::operator>(const TimeS& t) const
{
	return (Time::operator>(t) || (Time::operator==(t) && second > t.second));
}

bool TimeS::operator<(const TimeS& t) const
{
	return (Time::operator<(t) || (Time::operator==(t) && second < t.second));
}

TimeS& TimeS::operator++()
{
	second++;
	if (second == 60) {
		second = 0;
		Time::operator++();
	}
	return *this;
}

TimeS TimeS::operator++(int)
{
	TimeS tmp(*this);
	++(*this);
	return tmp;
}

int TimeS::secondNumber()
{
	return Time::minuteNumber() * 60 + second;
}

istream& operator>>(istream& is, TimeS& t)
{
	cout << "Give hour and minute: ";
	is >> (Time&)t;
	cout << "Give seconds: ";
	is >> t.second;
	if (t.second >= 0 && t.second < 60) {
		return is;
	}
	else is >> t;
}

ostream& operator<<(ostream& os, const TimeS& time)
{
	os << (Time&)time;
	os << ":" << (time.second < 10 ? "0" : "") << time.second << endl;
	return os;
}
