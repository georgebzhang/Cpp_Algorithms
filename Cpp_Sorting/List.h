#pragma once

template<typename T>
class List
{
public:
	virtual void insert_front(T t) = 0;
	virtual void insert_back(T t) = 0;
	virtual void remove_front() = 0;
	virtual void remove_back() = 0;
	virtual void insert(int index, T t) = 0;
	virtual void remove(int index) = 0;
	virtual T front() = 0;
	virtual T back() = 0;
	virtual int size() = 0;
	virtual bool empty() = 0;
};