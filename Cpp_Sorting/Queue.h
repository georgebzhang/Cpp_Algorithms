#pragma once

template<typename T>
class Queue
{
private:

public:
	virtual void enqueue(T t) = 0;
	virtual void dequeue() = 0;
	virtual T front() = 0;
	virtual bool empty() = 0;
};