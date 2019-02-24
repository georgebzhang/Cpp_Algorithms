#pragma once
#include "Queue.h"

template<typename T>
class ArrayQueue : Queue<T>
{
private:
	static const int MAX_CAPACITY = 100;
	T* data = new T[MAX_CAPACITY];
	int ind_front = 0, ind_back = 0;

public:
	void enqueue(T t) {
		data[ind_back] = t;
		ind_back = (ind_back + 1) % MAX_CAPACITY;
	}

	void dequeue() {
		if (empty())
			throw "Queue is empty";
		else {
			ind_front = (ind_front + 1) % MAX_CAPACITY;
		}
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

	~ArrayQueue() {
		std::cout << "called ArrayQueue destructor" << std::endl;
		delete[] data;
	}
};