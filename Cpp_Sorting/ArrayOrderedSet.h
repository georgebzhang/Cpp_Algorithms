#pragma once
#include "OrderedSet.h"

template<typename T>
class ArrayOrderedSet : OrderedSet<T>
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

	bool empty() {
		return length == 0;
	}

	int find(T t) { // helper functions for remove(...) and has(...)
		if (empty()) return 0;
		int ind_left = 0;
		int ind_right = length - 1;
		while (ind_left <= ind_right) {
			int ind_mid = (ind_left + ind_right) / 2;
			T val_mid = data[ind_mid];
			if (t > val_mid) ind_left = ind_mid + 1;
			else if (t < val_mid) ind_right = ind_mid - 1;
			else return ind_mid;
		}
		return ind_left; // LEFT NOT MID
	}

public:
	void insert(T t) {
		if (has(t)) return;
		if (length == capacity) grow_array();
		int ind_t = find(t);
		for (int i = length - 1; i >= ind_t; --i) { // must iterate backwards or else data is lost
			data[i + 1] = data[i];
		}
		data[ind_t] = t;
		++length;
	}

	void remove(T t) {
		if (!has(t)) return;
		int ind_t = find(t);
		if (ind_t != -1) {
			for (int i = ind_t; i < length; ++i) {
				data[i] = data[i + 1];
			}
		}
		--length;
	}

	bool has(T t) {
		return t == data[find(t)];
	}

	void print() {
		for (int i = 0; i < length; ++i) {
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}

	~ArrayOrderedSet() {
		std::cout << "called ArrayOrderedSet destructor" << std::endl;
		delete[] data;
	}
};