#include "point.h"

using namespace std;
int main()
{
    Point p1;
    Point p2(2, 3);
    Point p3(p2);
    Point p4(10, 11);
    Point p5(p4);
    Point p6(0, 4);
    Point p7(3, 0);
    cout << "P1: " << p1;
    cout << "P3: " << p3;
    cout << "X of P1: " << p1.getX() << endl;
    cout << "Y of P2: " << p2.getY() << endl;
    p3.setXY(10, 5);
    cout << "P3: " << p3;
    cin >> p2;
    cout << "P2: " << p2;
    cout << "The quater of p1 is: " << p1.getQuater() << endl;
    p1.setXY(1, 1);
    cout << "The quater of p1 is: " << p1.getQuater() << endl;
    p1.setXY(-1, 1);
    cout << "The quater of p1 is: " << p1.getQuater() << endl;
    p1.setXY(-1, -1);
    cout << "The quater of p1 is: " << p1.getQuater() << endl;
    p1.setXY(1, -1);
    cout << "The quater of p1 is: " << p1.getQuater() << endl;
    cout << "P4: " << p4;
    cout << "P5: " << p5;
    if (p4 == p5) cout << "P4 is equal to P5" << endl;
    else cout << "P4 is not equal to P5" << endl;
    if (p4 != p5) cout << "P4 is not equal to P5" << endl;
    else cout << "P4 is equal to P5" << endl;
    if (p4 == p2) cout << "P4 is equal to P2" << endl;
    else cout << "P4 is not equal to P2" << endl;
    cout << "Distance of P6 and P7 is: " << p6.distance(p7) << endl;
    cout << "Distance of P6 from 0 is: " << p6.distanceFromZero() << endl;
    p6.xParallelMoveing(2);
    cout << "P6: " << p6;
    p7.xParallelMoveing(2);
    cout << "P7: " << p7;

    Point arr[7] = { p1, p2, p3, p4, p5, p6, p7 };
    int dis = 3;
    cout << "Points which distance is grather than dis." << endl;
    for (int i = 0; i < 7; i++) {
        if (arr[i].distanceFromZero() > dis) cout << arr[i];
    }
    double max_dist = arr[0].distance(arr[1]);
    double min_dist = arr[0].distance(arr[1]);
    Point point1, point2, point4, point5;
    for (int i = 0; i < 7; i++)
        for (int j = i + 1; j < 7; j++) {
            if (arr[i].distance(arr[j]) >= max_dist) {
                point1 = arr[i];
                point2 = arr[j];
                max_dist = arr[i].distance(arr[j]);
            }
            if (arr[i].distance(arr[j]) <= max_dist) {
                point4 = arr[i];
                point5 = arr[j];
                min_dist = arr[i].distance(arr[j]);
            }

        }
    cout << "The two points with maximum distance: \n" << point1 << point2;
    cout << "The two points with minimum distance: \n" << point4 << point5;


    return 0;
}