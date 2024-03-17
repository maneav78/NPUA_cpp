#include "time.h"
#include <iomanip>
int main()
{
    Time t1(20, 2);
    Time t2(t1);
    Time t3(t2);
    Time t4(6, 40);
    Time t5(t4);
    Time t6(15, 14);
    Time t7(t6);
    Time t8(3,59);
    t3.setTime(1, 24);
    cout << "T3: " << t3; 
    t4.setHour(5);
    t4.setMinute(11);
    cout << "The hour of T4 is " << t4.getHour() << " and the minute of it is " << t4.getMinute() << endl;
    t2.print12();
    cin >> t5;  
    cout << "T5: " << t5;
    if (t7 == t6) cout << "The time is same!" << endl;
    else cout << "The time is different!" << endl;
    if (t7 == t5) cout << "The time is same!" << endl;
    else cout << "The time is different!" << endl;
    if (t5 > t6) cout << "T5 is grater then T6!" << endl;
    else cout << "T5 is less then T6" << endl;
    if (t5 < t6) cout << "T5 is less then T6" << endl;
    else cout << "T5 is grater then T6!" << endl;
    //t8++;
    //cout << "T8: " << t8;
    //t5 = t8++(8);
    //cout << "T8 in minutes: " << t8.minuteNumber() << endl;
    Time arr[8] = { t1, t2, t3, t4, t5, t6, t7, t8 };
    cout << "-----------------------" << endl;
    for (int i = 0; i < 8; i++) cout << arr[i];
    cout << "-----------------------" << endl;
    int min = abs((12 * 60) - arr[0].minuteNumber());
    int hour, minute, minfor2;
    for (int i = 0; i < 8; i++)
        if (abs((12*60)- arr[i].minuteNumber()) < min) {
            min = abs((12 * 60) - arr[i].minuteNumber());
            hour = arr[i].getHour();
            minute = arr[i].getMinute();
            minfor2 = arr[i].minuteNumber();
        }
    cout << "The 2 times closer to noon " << endl;
    cout << hour << ":" << setfill('0') << setw(2) << minute << endl;
    minfor2 = abs(minfor2 - arr[0].minuteNumber());
    for (int i = 0; i < 8; i++)
        if (abs(minfor2 - arr[i].minuteNumber()) < minfor2) {
            min = abs((12 * 60) - arr[i].minuteNumber());
            hour = arr[i].getHour();
            minute = arr[i].getMinute();
        }
    cout << hour << ":" << setfill('0') << setw(2) << minute << endl;
    
    return 0;
}
