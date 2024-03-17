#include "time.h"
#include <iomanip>

Time::Time(int hour, int minute)
{
	setTime(hour, minute);
}

Time::Time(const Time& other)
{
	setTime(other.getHour(), other.getMinute());
}

Time::~Time()
{
	cout << "The Time object was destroyed!" << endl;
}

void Time::setTime(int h, int m)
{
	setHour(h);
	setMinute(m);
}

void Time::setHour(int h)
{
	hour = (h >= 0 && h < 24) ? h : 0;
}

void Time::setMinute(int m)
{
	minute = (m >= 0 && m < 60) ? m : 0;
}

int Time::getHour() const
{
	return hour;
}

int Time::getMinute() const
{
	return minute;
}

void Time::print12() const
{
	cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":" << setfill('0') << setw(2) << minute << endl;
}

bool Time::operator==(const Time& obj) const
{
	return hour == obj.getHour() && minute == obj.getMinute();
}

bool Time::operator!=(const Time& obj) const
{
	return !(*this == obj);
}

bool Time::operator>(const Time& obj) const
{
	if (hour >= obj.getHour() && minute > obj.getMinute()) return true;
	return false;
}

bool Time::operator<(const Time& obj) const
{
	return !(*this > obj);
}

Time& Time::operator++(int min)
{
	minute += min;
	while (minute >= 60) {
		minute -= 60;
		hour++;
	}
	while (hour >= 24) {
		hour -= 24;
	}
	return *this;
}


Time& Time::operator++()
{
	minute++;
	while (minute >= 60) {
		minute -= 60;
		hour++;
	}
	while (hour >= 24) {
		hour -= 24;
	}
	return *this;
}

int Time::minuteNumber() const
{
	return hour < 12 ? (hour * 12) + minute : ((hour % 12) * 12) + minute;
}

ostream& operator<<(ostream& os, const Time& time)
{
	os << "The time is " << time.getHour() << ":" << setfill('0') << setw(2) << time.getMinute() << "." << endl;
	return os;
}

istream& operator>>(istream& is, Time& time)
{
	int h, m;
	cout << "What's the hour and minute? ";
	is >> h >> m;
	time.setHour(h);
	time.setMinute(m);
	return is;
}
