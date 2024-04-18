#include <iostream>
#include "times.h"

using namespace std;

int main()
{
    Times ob(12, 4, 6);
    cout << ob;
    Times ab(0,0,0);
    cin >> ab;
    cout << ab;
    return 0;
}

