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
	~ArrayStack() {
		delete[] data;
	}

	void push(T t) {
		data[length] = t;
		++length;
	}

	void pop() {
		if (empty())
			std::cout << "Stack is empty" << std::endl;
		else
			--length;
	}

	T top() {
		if (empty())
			std::cout << "Stack is empty" << std::endl;
		else
			return data[length - 1];
	}

	bool empty() {
		return length == 0;
	}
};