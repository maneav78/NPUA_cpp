#include "stack.h"
#include <cassert>

template<class T>
inline Stack<T>::Stack(int n)
{
	size = (n > 0 && n < 100) ? n : 10;
	Element = new T[size];
	assert(Element != nullptr);
}

template<class T>
Stack<T>::Stack(const Stack& st)
{
	top = st.top;
	size = st.size;
	Element = new T[size];
	for (int i = 0; i <= st.top; i++) Element[i] = st.Element[i];
}


template<class T>
Stack<T>::~Stack()
{
	delete[] Element;
	cout << "The Stack was destoryed!" << endl;
}

template<class T>
int Stack<T>::push(const T& elem)
{	
	if (!full()) {
		Element[++top] = elem;
		return 1;
	}
	return 0;
}

template<class T>
int Stack<T>::pop()
{
	if (!empty()) {
		top--;
		return 1;
	}
	return 0;
}

template<class T>
bool Stack<T>::operator==(const Stack& st)
{
	if (top != st.top || size != st.size) return false;
	for (int i = 0; i <= top; i++) {
		if (Element[i] != st.Element[i]) return false;
	}
	return true;
}

template<class T>
bool Stack<T>::operator!=(const Stack& st)
{
	return !(*this == st);
}

template<class T>
Stack<T>& Stack<T>::operator=(Stack& st)
{
	if (this == &st) return *this;
	delete[] Element;
	top = st.top;
	size = st.size;
	Element = new T[size];
	for (int i = 0; i <= st.top; i++) Element[i] = st.Element[i];
	return *this;
}
template<class T>
void Stack<T>::print() const
{
	cout << "The content of stack with top of " << getTop() << " and with size " << size << ": " << endl;
	if (empty()) {
		cout << "Stack is empty." << endl;
		return;
	}
	for (int i = 0; i <= top; i++) {
		cout << Element[i] << endl;
	}
}
/*template<class U>
inline ostream& operator<<(ostream& os, const Stack<U>& st)
{
	os << "The content of stack with top of " << st.getTop() << " and with size " << st.size << ": " << endl;
	if (st.empty()) {
		os << "Stack is empty." << endl;
		return os;
	}
	st.print();
	return os;
}


*/

