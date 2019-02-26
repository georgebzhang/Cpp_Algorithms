#pragma once
#include "OrderedSet.h"

template<typename T>
class ArrayOrderedSet : OrderedSet<T>
{
private:
	int capacity = 100; // TODO: implement amortized doubling
	T* data = new T[capacity];
	int length = 0;

public:
	void insert(T t) {

	}

	void remove(T t) {

	}

	bool has(T t) {

	}

	~ArrayOrderedSet() {
		std::cout << "called ArrayOrderedSet destructor" << std::endl;
		delete[] data;
	}
};