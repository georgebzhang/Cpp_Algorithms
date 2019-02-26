#pragma once
#include "Set"

template<typename T>
class ListSet : Set<T>
{
private:
	struct Node {
		T data;
		// we compare prev and next to nullptr in this implementation
		Node* prev = nullptr;
		Node* next = nullptr;
	};

	Node* head = nullptr;

	bool empty() {
		return head == nullptr;
	}

	Node* find(T t) {
		Node* ptr = head;
		while (ptr != nullptr) {
			if (ptr->data == t)
				return ptr;
			ptr = ptr->next;
		}
		return nullptr;
	}

public:
	void insert(T t) {
		if (has(t))
			return;
		Node* n = new Node();
		n->data = t;
		n->next = head;
		if (!empty())
			head->prev = n;
		head = n;
	}

	void remove(T t) { // maybe could do better with instance variable Node* tail
		Node* ptr_t = find(t);
		if (ptr_t == nullptr)
			return;
		bool prev_null = ptr_t->prev == nullptr;
		bool next_null = ptr_t->next == nullptr;
		if (!prev_null && !next_null) { // if Node with t is between head and tail (which doesn't exist)
			ptr_t->prev->next = ptr_t->next;
			ptr_t->next->prev = ptr_t->prev;
			delete ptr_t;
		}
		else if (!prev_null) { // if Node with t is at tail (which doesn't exist)
			ptr_t->prev->next = nullptr;
			delete ptr_t;
		}
		else if (!next_null) { // if Node with t is at head
			head = ptr_t->next; // Node at head being removed
			ptr_t->next->prev = nullptr;
			delete ptr_t;
		}
		else { // if Node with t is the only Node in Set
			delete ptr_t;
			head = nullptr;
		}
	}

	bool has(T t) {
		Node* ptr = head;
		while (ptr != nullptr) {
			if (ptr->data == t)
				return true;
			ptr = ptr->next;
		}
		return false;
	}

	void print() {
		Node* ptr = head;
		while (ptr != nullptr) {
			std::cout << ptr->data << " ";
			ptr = ptr->next;
		}
		std::cout << std::endl;
	}
};