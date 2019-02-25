#pragma once
#include "Queue.h"

template<typename T>
class ArrayQueue : Queue<T>
{
private:
	int capacity = 2; // capacity of resizable array
	T* data = new T[capacity];
	int ind_front = 0, ind_back = 0;
	int length = 0; // how many elements in Stack

public:
	void grow_array() { // amortized doubling
		std::cout << "Growing array" << std::endl;
		capacity *= 2;
		T* data_new = new T[capacity];
		for (int i = 0; i < capacity; ++i) {
			data_new[i] = data[i];
		}
		delete[] data;
		data = data_new;
	}

	void enqueue(T t) {
		if (length == capacity - 1) // not == capacity, because b will mod to index 0 and equal f
			grow_array();
		data[ind_back] = t;
		ind_back = (ind_back + 1) % capacity;
		++length;
	}

	void dequeue() {
		if (empty())
			throw "Queue is empty";
		else {
			ind_front = (ind_front + 1) % capacity;
		}
		--length;
	}

	T front() {
		if (empty())
			throw "Queue is empty";
		else {
			return data[ind_front];
		}
	}

	bool empty() {
		return ind_front == ind_back;
	}

	void print() {
		for (int count = 0; count < length; ++count) {
			std::cout << data[(ind_front + count) % capacity] << " ";
		}
		std::cout << std::endl;
	}

	~ArrayQueue() {
		std::cout << "called ArrayQueue destructor" << std::endl;
		delete[] data;
	}
};