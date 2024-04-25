#include <iostream>
#include "timeS.h"
#include <cmath>
using namespace std;

int main()
{
    TimeS t1;
    TimeS t2(25, 1);
    TimeS t3(60, 6, 55);
    TimeS t4;
    TimeS t5;
    TimeS t6(20, 20, 21);
    TimeS t7;
    Time temp;
    t7 = t6;
    cout << t1;
    cout << t2;
    cout << t3;
    t4.set(5, 4, 20);
    cout << t4;
    cin >> t5;
    cout << t5;
    t5.print12();
    if (t6 == t7) cout << "t6 is equal to t7!" << endl;
    t7.set(20, 20, 22);
    if (t6 == t7) cout << "t6 is equal to t7!" << endl;
    if (t6 != t7) cout << "t6 is not equal to t7!" << endl;
    if (t6 > t7) cout << "t6 is grater then t7!" << endl;
    if (t6 < t7) cout << "t7 is grater then t6!" << endl;
    cout << t6++;
    cout << t6;
    cout << ++t6;
    cout << t6;
    cout << t6.secondNumber() << endl;
    
    //------------------------------

    Time arr[7] = { t1, t2, t3, t4, t5, t6, t7};
    cout << "-----------------------" << endl;
    for (int i = 0; i < 7; i++) cout << arr[i] << endl;
    cout << "-----------------------" << endl;

    int min = INT_MAX;
    int minInd, minInd2;
    for (int i = 0; i < 7; i++) {
        int x = abs((12 * 60) - arr[i].minuteNumber());
        if (x < min) {
            min = x;
            minInd = i;
        }
    }
    cout << "The 2 times closer to noon " << endl;
    cout << arr[minInd] << endl;
    min = INT_MAX;
    for (int i = 0; i < 8; i++)
        if (i != minInd) {
            int x = abs((12 * 60) - arr[i].minuteNumber());
            if (x < min) {
                min = x;
                minInd2 = i;
            }
        }
    cout << arr[minInd2] << endl;
    
    //--------------------------------

    TimeS arr1[7] = { t1, t2, t3, t4, t5, t6, t7 };
    int max = INT_MIN;
    int ind;
    for (int i = 0; i < 7; i++) {
        if (arr1[i].secondNumber() > max) {
            max = arr1[i].secondNumber();
            ind = i;
        }
    }
    cout << "The latest time : " << arr1[ind];

    return 0;
}

