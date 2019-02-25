#pragma once
#include "Set.h"

template<typename T>
class ArraySet : Set<T>
{
private:
	int capacity = 100;
	T* data = new T[capacity];
	int length = 0;

public:
	void insert(T t) {
		if (has(t))
			return;
		data[length] = t;
		++length;
	}



	void remove(T t) {

		--length;
	}

	bool has(T t) {
		for (int i = 0; i < length; ++i) {
			if (t == data[i])
				return true;
		}
		return false;
	}
};