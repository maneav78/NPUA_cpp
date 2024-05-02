#include "person.h"

Person::Person(string n, string s, string pn, int y)
{
    setData(n, s, pn, y);
}

Person::Person(Person& ob)
{
    setData(ob.name, ob.surname, ob.passportNumber, ob.year);
}

void Person::getData() const
{
    cout << "Name: " << name << endl;
    cout << "Surname: " << surname << endl;
    cout << "Passport Number: " << passportNumber << endl;
    cout << "Year of birth: " << year << endl;
}

void Person::setData(string name, string surname, string passnum, int year)
{
    if (!isValidName(name) || !isValidName(surname)) {
        cout << "Invalid name or surname." << endl;
        name = "Undefined";
        surname = "Undefined";
    }
    else {
        this->name = name;
        this->surname = surname;
    }
    if (!isValidPassNumber(passnum)) {
        cout << "Invalid passport number." << endl;
        passportNumber = "Undefined";
    }else this->passportNumber = passnum;
    if (year < 1924 || year > CurrentYear()) {
        cout << "Invalid year." << endl;
        year = CurrentYear();
    }else this->year = year;
    
    
}



/*
void Person::setData(string name, string surname, string passnum, int year)
{
    int h = 0, check = 0;
    for (int i = 0; i < name.length(); i++) 
        if (isalpha(name[i])) h++;

    if (h == name.length()) { this->name = name; check++; }

    h = 0;
    for (int i = 0; i < surname.length(); i++) 
        if (isalpha(surname[i])) h++;
    
    if (h == name.length()) {this->surname = surname; check++;}

    h = 0;
    for (int i = 0; i < passnum.length(); i++){
        if ((i == 0 || i == 1) && isalpha(passnum[i])) h++;
        else if (isdigit(passnum[i])) h++;
    }
    if (h == 9) {passportNumber = passnum; check++;}

    if (year <= 2024 && year >= 1924) {this->year = year; check++;}
    if (check != 4) {
        cout << "The Data is invalid!" << endl;
        return;
    }
}
*/

int Person::getAge() const
{
    return CurrentYear() - year;
}

bool Person::isValidPassNumber(const string str) const
{
    if (str.length() != 9) return false;
    if (!isalpha(str[0]) || !isalpha(str[1])) return false;
    return all_of(str.begin() + 2, str.end(), ::isdigit);
}

int CurrentYear() {
    time_t currentTime = time(nullptr);
    tm timeinfo;
    localtime_s(&timeinfo, &currentTime);
    int currentYear = timeinfo.tm_year + 1900;
    return currentYear;
}

bool Person::isValidName(const string str) const
{
    return all_of(str.begin(), str.end(), ::isalpha);
}


ostream& operator<<(ostream& os, Person& ob)
{
    os << "Person with this data: " << endl;
    os << "Name: " << ob.name << endl;
    os << "Surname: " << ob.surname << endl;
    os << "Passport Number: " << ob.passportNumber << endl;
    os << "Year of birth: " << ob.year << endl;
    return os;
}

istream& operator>>(istream& is, Person& ob)
{
    cout << "Give name, surname, passport number and year of birth: ";
    string n, s, pn;
    int y;
    is >> n >> s >> pn >> y;
    ob.setData(n, s, pn, y);
    return is;
}
