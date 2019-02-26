#pragma once

template<typename T>
class Set // Set is a value-based (as opposed to position-based) data structure
{
public:
	virtual void insert(T t) = 0;
	virtual void remove(T t) = 0;
	virtual bool has(T t) = 0;
};