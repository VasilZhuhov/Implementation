#include "Vector.h"
template <class T>
Vector<T>::Vector() {
	size = 0;
	capacity = 8;
	vector = new T[capacity];
}

template <class T>
void Vector<T>::push(T element) {
	this->vector[size] = element;
	this->size = this->size + 1;
	if (size == capacity) {
		capacity = capacity * 2;
		increaseSize(vector);
	}
}
template <class T>
void Vector<T>::print() {
	std::cout << this->size << std::endl;
	for (int i = 0; i < this->size; i++) {
		std::cout << vector[i];
	}
}

//template <class T>
//void Vector<T>::increaseSize(T* vector){
//	T* vector = new T[capacity];
//	for (int i = 0; i < size; i++) {
//		this->vector[i] = vector[i];
//	}
//}

