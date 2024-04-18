#include "stack.h"

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

bool isMutuallyPrimeWithStack(int num, Stack<int>& s) {
    Stack<int> temp(s.getTop() + 1); 
    bool isMutuallyPrime = true;  

    while (!s.empty()) {
        int elem = s.pop();
        temp.push(elem);  

        if (gcd(num, elem) != 1) {  
            isMutuallyPrime = false;
        }
    }

    while (!temp.empty()) {
        s.push(temp.pop());
    }

    return isMutuallyPrime;
}

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

    Stack<int> stack1(100), stack2(100);
    int num;

    cout << "Enter natural numbers (0 to stop): ";
    while (cin >> num && num != 0) {
        stack1.push(num);
    }

    Stack<int> temp(stack1.getTop() + 1);

    while (!stack1.empty()) {
        temp.push(stack1.pop());
    }

    while (!temp.empty()) {
        int current = temp.pop();
        stack1.push(current);  // Push back into stack1 to maintain original state

        if (isMutuallyPrimeWithStack(current, stack1)) {
            stack2.push(current);
        }
    }

    cout << "Mutually prime numbers: ";
    while (!stack2.empty()) {
        cout << stack2.pop() << " ";
    }

    cout << "\nThe End!" << endl;
    return 0;
}
