#include "driver.h"

int main()
{
    Person p1;
    Person p2("Mane", "Avoyan", "AM78", 2004);
    Person p3("Nare", "Davtyan", "AM1234567", 1200); //00 
    Person p4("Ani", "Gevorgyan", "AM7340964", 2000);
    Person p5;

    Driver d1;
    Driver d2("Mari", "Minasyan", "KF7541698", 1978, "MD198547", 1980);
    Driver d3("Grigor", "Ohanyan", "PK7429012", 2000, "L2789546", 2020);
    Driver d4("Milena", "Hovhanissyan", "JK7854232", 2004, "PO017865", 2024);
    Driver d5("Anna", "Kirakosyan", "QT9064176", 1999, "JH712986", 2017);
    Driver d6("Karine", "Stepanyan", "MK8953092", 1989, "KO761203", 2023);
    Driver d7("Armen", "Harutyunyan", "KE5631283", 1975, "QQ078196", 2018);
    Driver d8("Klara", "Javaryan", "DE2361986", 1995, "FD925103", 2014);
    Driver d9;
    Driver temp;

    cout << p1;
    p2.getAge();
    p3.getData();
    p3.setData("Mari", "Minasyan", "KF7541698", 1978);
    cout << p3;
   // cin >> p5;
   /// cout << p5;

    cout << d1;
    d2.getAge();
    d3.getData();
    d7.getDataofLicense();
    d8.getExperience();
   // cin >> d9;
   // cout << d9;
    
    Driver arr[9] = { d1, d2, d3, d4, d5, d6, d7, d8, d9 };

    for (int i = 0; i < 9; i++) {
        cout << "-------------------------------" << endl;
        cout << arr[i];
    }
   /* for (int i = 0; i < 9; i++)
        for (int j = i + 1; j < 9; j++) {
            if (arr[j].getExperience() > arr[i].getExperience()) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    
    temp = arr[0];  
    for (int i = 1; i < 9; i++) {
        if (arr[i].getExperience() == arr[0].getExperience() && arr[i].getAge() < temp.getAge()) {
            temp = arr[i];
        }
    }
    */
    
    Driver temp = arr[0];

    for (int i = 1; i < 9; i++) {
        if (arr[i].getExperience() > temp.getExperience() ||
            (arr[i].getExperience() == temp.getExperience() && arr[i].getAge() < temp.getAge())) {
            temp = arr[i];
        }
    }
    cout << "The youngest driver with the most experience " << endl;
    cout << temp;
    return 0;
}
