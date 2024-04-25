#include "time.h"
#include <iostream>

using namespace std;

Time::Time(int h, int m)
{
	set(h, m);
}

void Time::set(int h, int m)
{
	hour = (h >= 0 && h < 24) ? h : 0;
	minute = (m >= 0 && m < 60) ? m : 0;
}

void Time::print12() const
{
	cout << ((hour == 0 || hour == 12) ? 12 : (hour % 12)) << ":" << minute << ((hour < 12) ? "AM" : "PM");
}

bool Time::operator==(const Time& t) const
{
	return (t.hour == hour && t.minute == minute);
}

bool Time::operator!=(const Time& t) const
{
	return !(t == *this);
}

bool Time::operator>(const Time& t) const
{
	return (hour > t.hour || (hour == t.hour && minute > t.minute));
}

bool Time::operator<(const Time& t) const
{
	return (hour < t.hour || (hour == t.hour && minute < t.minute));
}

Time& Time::operator++()
{
	minute++;
	if (minute == 60) {
		minute = 0;
		hour++;
		if (hour == 24) {
			hour = 0;
		}
	}
	return *this;
}

Time Time::operator++(int)
{
	Time tmp(*this);
	++(*this);
	return tmp;
}

int Time::minuteNumber()
{
	return hour * 60 + minute;
}

istream& operator>>(istream& is, Time& time)
{
	is >> time.hour >> time.minute;
	if ((time.hour >= 0 && time.hour < 24) && (time.minute >= 0 && time.minute < 60)) {
		return is;
	}
	else is >> time;
}

ostream& operator<<(ostream& os, const Time& time)
{
	os << (time.hour < 10 ? "0" : "") << time.hour << ":" << (time.minute < 10 ? "0" : "") << time.minute;
	return os;
}
