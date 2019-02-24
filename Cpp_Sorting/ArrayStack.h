#pragma once
#include "Stack.h"

template<typename T>
class ArrayStack : Stack<T>
{
private:
	static const int MAX_CAPACITY = 100;
	T* data = new T[MAX_CAPACITY];
	int length = 0;

public:
	void push(T t) {
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

	~ArrayStack() {
		std::cout << "called ArrayStack destructor" << std::endl;
		delete[] data;
	}
};