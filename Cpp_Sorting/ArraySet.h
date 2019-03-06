#pragma once
#include "Set.h"

template<typename T>
class ArraySet : Set<T>
{
private:
	int capacity = 2;
	T* data = new T[capacity];
	int length = 0;

	void grow_array() { // amortized doubling
		std::cout << "Growing array" << std::endl;
		capacity *= 2;
		T* data_new = new T[capacity];
		for (int i = 0; i < capacity; ++i) { // length == capacity
			data_new[i] = data[i];
		}
		delete[] data;
		data = data_new;
	}

	int find(T t) { // helper functions for remove(...) and has(...)
		for (int i = 0; i < length; ++i) {
			if (t == data[i]) return i;
		}
		return -1;
	}

public:
	void insert(T t) {
		if (has(t)) return;
		if (length == capacity) grow_array();
		data[length] = t;
		++length;
	}

	void remove(T t) {
		int ind_t = find(t);
		if (ind_t == -1) return;
		for (int i = ind_t; i < length; ++i) {
			data[i] = data[i + 1];
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

	~ArraySet() { // memory management
		std::cout << "called ArraySet destructor" << std::endl;
		delete[] data;
	}
};