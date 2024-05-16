#include "driver.h"

int main()
{
    int numPersons, numDrivers;
    cout << "Enter the number of Person objects: ";
    cin >> numPersons;
    cout << "Enter the number of Driver objects: ";
    cin >> numDrivers;

    Person* persons = new Person[numPersons];
    Driver* drivers = new Driver[numDrivers];

    for (int i = 0; i < numPersons; ++i) {
        cout << "Enter data for Person " << i + 1 << ", ";
        cin >> persons[i];
    }

    for (int i = 0; i < numDrivers; ++i) {
        cout << "Enter data for Driver " << i + 1 << ", ";;
        cin >> drivers[i];
    }
    
    cout << "--------Person objects--------" << endl;
    for (int i = 0; i < numPersons; ++i) {
        cout << persons[i];
    }
    cout << "--------Driver objects--------" << endl;
    for (int i = 0; i < numDrivers; ++i) {
        cout << drivers[i];
    }

    /*cout << "--------Some test--------" << "endl";

    persons[2].getAge();
    persons[3].getData();
    persons[3].setData("Mari", "Minasyan", "KF7541698", 1978);
    cout << persons[3];

    drivers[2].getAge();
    drivers[3].getData();
    drivers[7].getDataofLicense();
    drivers[8].getExperience();
    */
    

   
    Driver temp = drivers[0];

    for (int i = 1; i < numDrivers; i++) {
        if ((drivers[i].getExperience() > temp.getExperience()) || (drivers[i].getExperience() == temp.getExperience() && drivers[i].getAge() < temp.getAge())) {
            temp = drivers[i];
        }
    }
    cout << "---The youngest driver with the most experience---" << endl;
    cout << temp;

    delete[] persons;
    delete[] drivers;

    return 0;
}
