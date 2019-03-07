#pragma once
#include "OrderedSet.h"

template<typename T>
class ListOrderedSet : OrderedSet<T>
{
private:
	struct Node {
		T data;
		Node* prev = nullptr;
		Node* next = nullptr;
	};

	Node* head = nullptr;

	bool empty() {
		return head == nullptr;
	}

	Node* find(T t) {
		Node* ptr = head;
		while (true) {
			if (t <= ptr->data || ptr->next == nullptr) return ptr; // return ptr also if it is the tail (which we don't have a variable for)
			ptr = ptr->next;
		}
		return nullptr;
	}

	void insert_Node_middle(Node* n, Node* ptr_t) { // inserts Node* n before Node* ptr_t, which must have prev and next not nullptr
		n->next = ptr_t;
		n->prev = ptr_t->prev;
		ptr_t->prev->next = n;
		ptr_t->prev = n;
	}

public:
	void insert(T t) {
		if (has(t)) return;
		Node* n = new Node();
		n->data = t;
		if (empty()) {
			head = n;
			return;
		}
		Node* ptr_t = find(t);
		bool prev_null = ptr_t->prev == nullptr;
		bool next_null = ptr_t->next == nullptr;
		if (!prev_null && !next_null) { // if Node with t is between head and tail (which we don't have a variable for)
			insert_Node_middle(n, ptr_t);
		}
		else if (!prev_null) { // if Node with t is at tail (which we don't have a variable for)
			if (t < ptr_t->data) {
				insert_Node_middle(n, ptr_t);
			}
			else {
				n->prev = ptr_t;
				ptr_t->next = n;
			}
		}
		else if (!next_null) { // if Node with t is at head
			if (t < ptr_t->data) {
				n->next = ptr_t;
				head->prev = n;
				head = n;
			}
			else {
				insert_Node_middle(n, ptr_t);
			}
		}
		else { // if Node with t is the only Node in Set
			if (t < head->data) {
				n->next = head;
				head = n;
			}
			else {
				n->prev = head;
				head->next = n;
			}
		}
	}

	void remove(T t) {
		if (!has(t)) return;
		Node* ptr_t = find(t);
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
		if (empty()) return false;
		return t == find(t)->data;
	}

	void print() {
		Node* ptr = head;
		while (ptr != nullptr) {
			std::cout << ptr->data << " ";
			ptr = ptr->next;
		}
		std::cout << std::endl;
	}

	~ListOrderedSet() { // memory management
		std::cout << "called ListOrderedSet destructor" << std::endl;
		while (!empty()) {
			Node* ptr = head;
			head = head->next;
			delete ptr;
		}
	}
};