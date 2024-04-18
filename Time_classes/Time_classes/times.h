#include <iostream>
#include "time.h"

class Times : public Time {
public:
	Times(int, int, int=0);
	//Times(const Times&);

	void setSecond(int=0);
	
	int getSecond() const;
	//void print12() const;
	//int minuteNumber() const;

	//operators
	friend ostream& operator<<(ostream&, const Times&);
	friend istream& operator>>(istream&, Times&);
	//bool operator==(const Time&) const;
	//bool operator!=(const Time&) const;
	//bool operator>(const Time&) const;
	//bool operator<(const Time&) const;
	//Time& operator++(int);
	//Time& operator++();

private:
	int second;
};