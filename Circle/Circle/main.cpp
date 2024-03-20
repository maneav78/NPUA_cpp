#include "circle.h"

int main()
{
    Circle c1(0, 0, 1);
    Circle c2(2, 5, 4);
    Circle c3(c2);
    Circle c4(0, 0, 1);
    Circle c5(2, 0, 1);
    Circle c(0, 0, 1);
    Point p = { 0, 1 };
    c1.tangentEquation(p);
    cout << "The R of c1: " << c1.getR() << endl;
    c1.getCenter();
    c1.setParametrs(2, 2, 6);
    cout << c1;
    cin >> c1;
    cout << c1;
    if (c2 == c3) cout << "The c2 is equal to c3" << endl;
    else cout << "The c2 is different from c3" << endl;
    if (c1 > c2) cout << "The c1 is grater then c2" << endl;
    else cout << "The c2 is grater then c1" << endl;
    if (c4.isPointOn(1, 0)) cout << "The point is on the circle!" << endl;
    else cout << "The point is not on the circle" << endl;
    cout << "The cont of insections of c1 and c2: " << c1.countOfHatums(c2) << endl;
    cout << "The cont of insections of c3 and c2: " << c3.countOfHatums(c2) << endl;
    cout << "The cont of insections of c4 and c5: " << c4.countOfHatums(c5) << endl;
    cout << "the length of c5: " << c5.length() << endl;
    cout << "The area of c5: " << c5.area() << endl;
    cout << "Distance of centers c4 and c5: " << c4.distanceOfCenters(c5) << endl;
    c4.xParallelMoveing(2);
    c4.yParallelMoveing(1);
    cout << "Area of c4: " << c4.area() << endl;
    c4.changeAreaByK(4);
    cout << "Area of c4: " << c4.area() << endl;
    cout << c4;
    cout << "----------------------" << endl;
    Circle arr[5] = { c1, c2, c3, c4, c5 };
    double num = 6;
    cout << "Circles that have area grater than num: " << endl;
    for (int i = 0; i < 5; i++)
        if (arr[i].area() > num) cout << arr[i];

    int max_intersections = arr[0].countOfHatums(arr[1]);
    for (int i = 0; i < 5; i++) {
        int h = 0;
        for (int j = i; j < 5; j++) if (arr[i].countOfHatums(arr[j]) != -1) h += arr[i].countOfHatums(arr[j]);
        if (h >= max_intersections) {
            max_intersections = h;
            c = arr[i];
        }
    }
    cout << "The circle with the most count of intersections: " << c;
    
    int max = 0;
    for (int i = 0; i < 5; i++) {
        int h = 0;
        for (int j = i; j < 5; j++) {
            if (arr[i].getR() + arr[j].getR() == arr[i].distanceOfCenters(arr[j])) h++;
        }
        if (h >= max) {
            max = h; c = arr[i];
        }
    }
    cout << "The circle with the most count of tangents: " << c;
    
    Circle c6(2, 5, 4);
    Circle c7(3, 5, 1);
    Circle c8(0, 6, 1);
    Circle c9(10, 2, 2);
    Circle c10(14, 8, 3);
    Circle c11(14, 8, 1);
    
    Circle arr1[6] = { c6, c7, c8, c9, c10, c11};
    max = 0;
    for (int i = 0; i < 6; i++) {
        int h = 0;
        for (int j = i; j < 6; j++) {
            if (arr1[i].distanceOfCenters(arr1[j])+arr1[j].getR() <= arr1[i].getR()) h++;
        }
        if (h >= max) {
            max = h;
            c = arr1[i];
        }
    }
    cout << "The circle with the most count of circles in it is: " << c;

    return 0;
}
