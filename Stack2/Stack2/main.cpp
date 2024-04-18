#include "stack.h"

int main()
{
    Stack <int> st1(5);
    st1.print();
    st1.push(9);
    st1.push(10);
    st1.print();
    Stack <char> st2(10);
    st2.push('a');
    st2.push('l');
    st2.push('o');
    st2.print();
    Stack <char> st3(st2);
    st3.pop();
    st3.print();
    cout << "ST3 is empty: " << (st3.empty() == 1 ? "True" : "False") << endl;
    st3.pop();
    st3.pop();
    cout << "ST3 is empty(after poping all elements): " << (st3.empty() == 1 ? "True" : "False") << endl;
    Stack <int> st4(st1);
    if (st1 == st4) cout << "St1 is equal to st4" << endl;
    else cout << "St1 is not equal to st4" << endl;
    if (st1 != st4) cout << "St1 is not equal to st4" << endl;
    else cout << "St1 is equal to st4" << endl;
    st3 = st2;
    st3.print();


}
