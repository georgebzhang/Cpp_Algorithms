#pragma once
#include "Stack.h"

template<typename T>
class ArrayStack : Stack<T>
{
private:
	int capacity = 2; // capacity of resizable array
	T* data = new T[capacity];
	int length = 0; // how many elements in Stack

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

public:
	void push(T t) {
		if (length == capacity) grow_array();
		data[length] = t;
		++length;
	}

	void pop() {
		if (empty())
			throw "Stack is empty";
		else
			--length;
	}

	T top() {
		if (empty())
			throw "Stack is empty";
		else
			return data[length - 1];
	}

	bool empty() {
		return length == 0;
	}

	void print() {
		for (int i = 0; i < length; ++i) {
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}

	~ArrayStack() {
		std::cout << "called ArrayStack destructor" << std::endl;
		delete[] data;
	}
};