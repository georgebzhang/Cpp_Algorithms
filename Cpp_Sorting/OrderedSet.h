#pragma once

template<typename T>
class OrderedSet
{
public:
	virtual void insert(T t) = 0;
	virtual void remove(T t) = 0;
	virtual bool has(T t) = 0;
};