#pragma once
#include "List.h"

template<typename T>
class NodeList : List<T>
{
private:
	struct Node {
		T data;
		Node* prev = nullptr;
		Node* next = nullptr;

		~Node() {
			std::cout << "called Node destructor" << std::endl;
		}
	};

	int length = 0;
	Node* head = nullptr;
	Node* tail = nullptr;

public:
	void insert_front(T t) {
		Node* n = new Node();
		n->data = t;
		if (empty()) {
			head = n;
			tail = n;
		}
		else {
			n->next = head;
			head->prev = n;
			head = n;
		}
		++length;
	}

	void insert_back(T t) {
		Node* n = new Node();
		n->data = t;
		if (empty()) {
			head = n;
			tail = n;
		}
		else {
			n->prev = tail;
			tail->next = n;
			tail = n;
		}
		++length;
	}

	void remove_front() {
		if (empty())
			throw "List is empty";
		if (length == 1) {
			delete head; // head is same as tail
			head = nullptr;
			tail = nullptr;
		}
		else {
			Node* ptr = head;
			head = head->next;
			delete ptr;
		}
		--length;
	}

	void remove_back() {
		if (empty())
			throw "List is empty";
		if (length == 1) {
			delete tail; // head is same as tail
			head = nullptr;
			tail = nullptr;
		}
		else {
			Node* ptr = tail;
			tail = tail->prev;
			delete ptr;
		}
		--length;
	}

	Node* find(int index) { // helper function for insert(...) and remove(...)
		Node* ptr = head;
		for (int i = 0; i < index; ++i) { // not <= index, since we do ->next during i = 0
			ptr = ptr->next;
		}
		return ptr;
	}

	void insert(int index, T t) {
		if (empty())
			throw "List is empty";
		if (index >= length)
			throw "Index exceeds length";
		if (index == 0) {
			insert_front(t);
		}
		else if (index == length - 1) {
			insert_back(t);
		}
		else { // if index is between front and back
			Node* n = new Node();
			n->data = t;
			Node* n_index = find(index);
			n_index->prev->next = n;
			n->prev = n_index->prev;
			n->next = n_index;
			n_index->prev = n;
		}
		++length;
	}

	void remove(int index) {
		if (empty())
			throw "List is empty";
		if (index >= length)
			throw "Index exceeds length";
		if (index == 0) {
			remove_front();
		}
		else if (index == length - 1) {
			remove_back();
		}
		else { // if index is between front and back
			Node* n_index = find(index);
			n_index->prev->next = n_index->next;
			n_index->next->prev = n_index->prev;
			delete n_index;
		}
		--length;
	}

	T front() {
		if (empty())
			throw "List is empty";
		return head->data;
	}

	T back() {
		if (empty())
			throw "List is empty";
		return tail->data;
	}

	int size() {
		return length;
	}

	bool empty() {
		return length == 0;
	}

	void print() {
		if (empty())
			std::cout << "List is empty" << std::endl;
		else if (length == 1)
			std::cout << head->data << std::endl;
		else {
			Node* iter = head;
			for (int i = 0; i < length; ++i) {
				std::cout << iter->data << " ";
				iter = iter->next;
			}
			std::cout << std::endl;
		}
	}
};