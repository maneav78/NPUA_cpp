#include "cylinder.h"

int main()
{
    Cylinder c1;
    Cylinder c2(2, 4);
    Cylinder c3(c2);
    Cylinder c4;
    Cylinder c5;
    Cylinder c6(2, 2);
    Cylinder c7(4, 5);
    Cylinder c8(10, 20);

    cout << "The R of c1: " << c1.getr() << endl;
    cout << "The H of c1: " << c1.geth() << endl;
    cout << c2;
    cin >> c4;
    if (c2 == c3) cout << "C2 is equal to C3!" << endl;
    else cout << "C2 is not equal to C3!" << endl;
    if (c2 != c3) cout << "C2 is not equal to C3!" << endl;
    else cout << "C2 is equal to C3!" << endl;
    if (c2 > c1) cout << "C2 is grater than C1!" << endl;
    if (c1 < c2) cout << "C2 is grater than C1!" << endl;
    
    cout << "The volume of C2: " << c2.Volume() << endl;
    cout << "The base surface of C2: " << c2.baseSurface() << endl;
    cout << "The side surface of C2: " << c2.sideSurface() << endl;
    cout << "The surface of C2: " << c2.Surface() << endl;
    cout << "The seperate surface of C2: " << c2.seperateSurface() << endl;

    c5 = c2;
    cout << c5;
    cout << "The count of cylinders: " << c1.getConut() << endl;
    cout << "The volume of c5 before: " << c5.Volume() << endl;
    c5.editVolume(5);
    cout << "The volume of c5 after: " << c5.Volume() << endl;
    
    cout << "--------------------------" << endl;

    Cylinder arr[8] = { c1, c2, c3, c4, c5, c6, c7, c8 };
    int volume = 50;
    cout << "Cylinders that have less volume then number of volume variable: " << endl;
    for (int i = 0; i < 8; i++)
        if (arr[i].Volume() < volume) cout << arr[i];

    for (int i = 1; i < 8; i++) {
        Cylinder current = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].Volume() < current.Volume()) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
    cout << "3 Cylinders with the most value of volumes: " << endl;
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << arr[i].Volume() << endl;
    }

    return 0;
}

