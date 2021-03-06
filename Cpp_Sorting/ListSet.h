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

		~Node() {
			std::cout << "Called Node destructor" << std::endl;
		}
	};

	Node* head = nullptr;

	bool empty() { // helper function for insert(...)
		return head == nullptr;
	}

	Node* find(T t) { // helper function for remove(...)
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
		if (!prev_null && !next_null) { // if Node with t is between head and tail (which we don't have a variable for)
			ptr_t->prev->next = ptr_t->next;
			ptr_t->next->prev = ptr_t->prev;
			delete ptr_t;
		}
		else if (!prev_null) { // if Node with t is at tail (which we don't have a variable for)
			ptr_t->prev->next = nullptr;
			delete ptr_t;
		}
		else if (!next_null) { // if Node with t is at head
			head = ptr_t->next; // Node at head being removed
			ptr_t->next->prev = nullptr;
			delete ptr_t;
		}
		else { // if Node with t is the only Node in Set
			head = nullptr;
			delete ptr_t;
		}
	}

	bool has(T t) {
		return find(t) != nullptr;
	}

	void print() {
		Node* ptr = head;
		while (ptr != nullptr) {
			std::cout << ptr->data << " ";
			ptr = ptr->next;
		}
		std::cout << std::endl;
	}

	~ListSet() { // memory management
		std::cout << "called ListSet destructor" << std::endl;
		while (!empty()) {
			Node* ptr = head;
			head = head->next;
			delete ptr;
		}
	}
};