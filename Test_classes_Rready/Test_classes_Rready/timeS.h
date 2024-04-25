#pragma once
#include <iostream>
#include "time.h"

using namespace std;

class TimeS : public Time {
private:
	int second;
public:
	TimeS(int = 0, int = 0, int = 0);
	void set(int, int, int);

	friend istream& operator>>(istream&, TimeS&);
	friend ostream& operator<<(ostream&, const TimeS&);

	void print12() const;

	bool operator==(const TimeS&) const;
	bool operator!=(const TimeS&) const;
	bool operator>(const TimeS&) const;
	bool operator<(const TimeS&) const;
	TimeS& operator++();
	TimeS operator++(int);
	int secondNumber();
};