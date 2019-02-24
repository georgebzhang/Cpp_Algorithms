#pragma once
#include "Queue.h"

template<typename T>
class ListQueue : Queue<T>
{
private:
	struct Node {
		T data;
		Node* next;

		~Node() { // unnecessary
			std::cout << "called Node destructor" << std::endl;
		}
	};

	Node* first = nullptr;
	Node* last = nullptr;

public:
	void enqueue(T t) {
		Node* n = new Node();
		n->data = t;
		n->next = nullptr;
		if (empty()) {
			first = n;
			last = n;
		}
		else {
			Node* ptr = last;
			ptr->next = n;
			last = n;
		}
	}

	void dequeue() {
		if (empty())
			throw "Queue is empty";
		else if (first == last) { // if queue has 1 element
			delete first;
			first = nullptr;
			last = nullptr;
		}
		else {
			Node* ptr = first;
			first = first->next;
			delete ptr;
		}
	}

	T front() {
		if (empty())
			throw "Queue is empty";
		else
			return first->data;
	}

	bool empty() {
		return first == nullptr && last == nullptr;
	}

	~ListQueue() {
		std::cout << "called ListQueue destructor" << std::endl;
		while (!empty()) {
			if (first == last) { // if queue has 1 element
				delete first;
				first = nullptr;
				last = nullptr;
			}
			else {
				Node* ptr = first;
				first = first->next;
				delete ptr;
			}
		}
	}
};