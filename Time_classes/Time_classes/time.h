#include <iostream>
using namespace std;

class Time
{
public:
	// constructors && destructor
	Time(int=0, int=0);
	Time(const Time&);
	~Time();

	//set functions
	void setTime(int=0, int=0);
	//Time& setTime(int, int);
	void setHour(int=0);
	void setMinute(int=0);

	//get functions
	int getHour() const;
	int getMinute() const;

	//print function
	void print12() const;

	//operators
	friend ostream& operator<<(ostream&, const Time&);
	friend istream& operator>>(istream&, Time&);
	bool operator==(const Time&) const;
	bool operator!=(const Time&) const;
	bool operator>(const Time&) const;
	bool operator<(const Time&) const;
	Time& operator++(int);
	Time& operator++();
	int minuteNumber() const;

protected:
	int hour;
	int minute;
};
