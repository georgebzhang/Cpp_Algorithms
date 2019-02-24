#pragma once
#include "Stack.h"

template<typename T>
class ListStack : Stack<T>
{
private:
	struct Node {
		T data;
		Node *next;

		~Node() { // unnecessary
			std::cout << "called Node destructor" << std::endl;
		}
	};

	Node* head = nullptr;

public:
	void push(T t) {
		Node* ptr = new Node();
		ptr->data = t;
		ptr->next = head;
		head = ptr;
	}

	void pop() {
		if (empty())
			throw "Stack is empty";
		else {
			Node *ptr = head;
			head = head->next;
			delete ptr;
		}
	}

	T top() {
		if (empty())
			throw "Stack is empty";
		else
			return head->data;
		
	}

	bool empty() {
		return head == nullptr;
	}

	~ListStack() {
		std::cout << "called ListStack destructor" << std::endl;
		while (!empty()) {
			Node *ptr = head;
			head = head->next;
			delete ptr;
		}
	}
};