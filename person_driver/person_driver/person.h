#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
using namespace std;

int CurrentYear();
class Person {
public:
	Person(string="undefined", string="undefined", string="undefined", int=CurrentYear());
	Person(Person&);

	void getData() const;
	void setData(string, string, string, int);
	int getAge() const;

	friend ostream& operator<<(ostream&, Person&);
	friend istream& operator>>(istream&, Person&);

protected:
	string name;
	string surname;
	string passportNumber;
	int year;

	bool isValidName(const string) const;
	bool isValidPassNumber(const string) const;
};