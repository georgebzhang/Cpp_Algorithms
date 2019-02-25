#pragma once

template<typename T>
class PriorityQueue
{
public:
	virtual void insert(T t) = 0;
	virtual void remove() = 0;
	virtual T top() = 0;
	virtual bool empty() = 0;
};