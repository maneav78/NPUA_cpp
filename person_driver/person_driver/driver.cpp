#include "driver.h"

Driver::Driver(string n, string s, string pn, int y, string dln, int gy)
{
    setData(n, s, pn, y);
    setDataofLicense(dln, gy);
}

Driver::Driver(Driver& ob)
{   
    setData(ob.name, ob.surname, ob.passportNumber, ob.year);
    setDataofLicense(ob.dlNumber, ob.gyear);
}

void Driver::getDataofLicense() const
{
    cout << "Number of driver license: " << dlNumber << endl;
    cout << "Year of getting driver license: " << gyear << endl;
}

void Driver::setDataofLicense(string dln, int gy)
{
    if (!isValidDLNumber(dln)) {
        cout << "Invalid Driver License number." << endl;
        dlNumber = "Undefined";

    }else this->dlNumber = dln;
    if (gy < getAge() + 18 || gy > CurrentYear()) {
        cout << "Invalid year of getting Driver License." << endl;
        gy = CurrentYear();
    }else this->gyear = gy;
    
}

int Driver::getExperience() const
{
    return CurrentYear()-gyear;
}

bool Driver::isValidDLNumber(const string str) const
{
    if (str.length() != 8) return false;
    if (!isalpha(str[0]) || !isalpha(str[1])) return false;
    return all_of(str.begin() + 2, str.end(), ::isdigit);
}

ostream& operator<<(ostream& os, Driver& dr)
{
    os << (Person&)dr;
    os << "Driver License Number: " << dr.dlNumber << endl;
    os << "Year of getting driver license: " << dr.gyear << endl;
    return os;
}

istream& operator>>(istream& is, Driver& dr)
{
    is >> (Person&)dr;
    cout << "Give the driver license number and year of getting it: ";
    string num;
    int year;
    is >> num >> year;
    dr.setDataofLicense(num, year);
    return is;
}

