#pragma once
#include "Stack.h"

template<typename T>
class ListStack : Stack<T>
{
private:
	struct Node {
		T data;
		Node *next;

		~Node() {
			std::cout << "called Node destructor" << std::endl;
		}
	};

	Node* head = NULL;

public:
	void push(T t) {
		Node* ptr = new Node();
		ptr->data = t;
		ptr->next = head;
		head = ptr;
	}

	void pop() {
		if (empty())
			std::cout << "Stack is empty" << std::endl;
		else {
			Node *ptr = head;
			head = head->next;
			delete ptr;
		}
	}

	T top() {
		if (empty())
			std::cout << "Stack is empty" << std::endl;
		else {
			return head->data;
		}
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