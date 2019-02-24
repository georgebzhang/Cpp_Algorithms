#pragma once

template<typename T>
class Stack
{
private:
	
public:
	virtual void push(T t) = 0;
	virtual void pop() = 0;
	virtual T top() = 0;
	virtual bool empty() = 0;
};