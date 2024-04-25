#pragma once
#include <iostream>

using namespace std;

class Time {
protected:
	int hour, minute;
public:
	Time(int = 0, int = 0);
	void set(int, int);

	friend istream& operator>>(istream&, Time&);
	friend ostream& operator<<(ostream&, const Time&);

	void print12() const;

	bool operator==(const Time&) const;
	bool operator!=(const Time&) const;
	bool operator>(const Time&) const;
	bool operator<(const Time&) const;
	Time& operator++();
	Time operator++(int);
	int minuteNumber();
};
