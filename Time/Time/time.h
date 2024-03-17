#include <iostream>
using namespace std;

class Time
{
public:
	// constructors && destructor
	Time(int, int);
	Time(const Time&);
	~Time();

	//set functions
	void setTime(int, int);
	//Time& setTime(int, int);
	void setHour(int);
	void setMinute(int);

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

private:
	int hour;
	int minute;
};
