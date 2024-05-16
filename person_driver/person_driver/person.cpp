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
    if (name != "undefined" && !isValidName(name)) {
        cout << "Invalid name or surname: " << name << endl;
        this->name = "undefined";
    }
    else {
        this->name = name;
    }

    if (surname != "undefined" && !isValidName(surname)) {
        cout << "Invalid name or surname: " << surname << endl;
        this->surname = "undefined";
    }
    else {
        this->surname = surname;
    }

    if (passnum != "undefined" && !isValidPassNumber(passnum)) {
        cout << "Invalid passport number: " << passnum << endl;
        this->passportNumber = "undefined";
    }
    else {
        this->passportNumber = passnum;
    }

    if (year < 1924 || year > CurrentYear()) {
        cout << "Invalid year: " << year << endl;
        this->year = CurrentYear();
    }
    else {
        this->year = year;
    }
}
    
    


int Person::getAge() const
{
    return CurrentYear() - year;
}

bool Person::isValidPassNumber(const string str) const
{
    if (str.length() != 9) return false;
    if (!((str[0] >= 'A' && str[0] <= 'Z'))) return false;
    if (!((str[1] >= 'A' && str[1] <= 'Z'))) return false;
    for (int i = 2; i < str.length(); i++) {
        if (!(str[i] >= '0' && str[i] <= '9')) return false;
    }
    return true;
}



int CurrentYear() {
    time_t currentTime = time(nullptr);
    tm timeinfo;
    localtime_s(&timeinfo, &currentTime);
    return timeinfo.tm_year + 1900;
}

bool Person::isValidName(const string str) const
{   
    if (str.empty()) return false;
    if (!(str[0] >= 'A' && str[0] <= 'Z')) return false;
    for (int i = 1; i < str.length(); i++) {
        if (!(str[i] >= 'a' && str[i] <= 'z')) return false;
    }
    return true;
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
