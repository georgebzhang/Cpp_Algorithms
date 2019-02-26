#pragma once
#include "Set.h"

template<typename T>
class ArraySet : Set<T>
{
private:
	int capacity = 100; // will implement amortized doubling later
	T* data = new T[capacity];
	int length = 0;

	int find(T t) {
		for (int i = 0; i < length; ++i) {
			if (t == data[i])
				return i;
		}
		return -1;
	}

public:
	void insert(T t) {
		if (has(t))
			return;
		data[length] = t;
		++length;
	}

	void remove(T t) {
		int ind_t = find(t);
		if (ind_t == -1)
			return;
		for (int i = ind_t; i < length; ++i) {
			data[ind_t] = data[ind_t + 1];
		}
		--length;
	}

	bool has(T t) {
		return find(t) != -1;
	}

	void print() {
		for (int i = 0; i < length; ++i) {
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}
};