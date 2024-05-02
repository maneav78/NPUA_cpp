#pragma once
#include "person.h"

class Driver : public Person {
public:
	Driver(string = "undefined", string = "undefined", string = "undefined", int = CurrentYear(), string="undefined", int = CurrentYear());
	Driver(Driver&);

	void getDataofLicense() const;
	void setDataofLicense(string, int);
	int getExperience() const;

	friend ostream& operator<<(ostream&, Driver&);
	friend istream& operator>>(istream&, Driver&);

private:
	string dlNumber;
	int gyear;
	bool isValidDLNumber(const string) const;
};