#include<iostream>
template <class T>
class Vector {
public:
	Vector();
	void print();
	void push(T element);

private:
	int size;
	int capacity;
	void increaseSize(T*);
	T* vector;
};