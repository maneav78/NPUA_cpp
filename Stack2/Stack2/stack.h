#include <iostream>
using namespace std;

template<class T>
class Stack {
public:
	Stack(int);
	Stack(const Stack&);
	~Stack();
	int push(const T&);
	int pop();
	int getTop() const { return top; }
	int empty() const { return top == -1; }
	int full() const { return top == size - 1; }
	bool operator==(const Stack&);
	bool operator!=(const Stack&);
	Stack<T>& operator=(Stack&);
	void print() const;

private:
	T* Element;
	int size;
	int top = -1;
};


