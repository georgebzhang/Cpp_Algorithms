#pragma once

template<typename K, typename V>
class Map
{
public:
	virtual void insert(K k, V v) = 0;
	virtual void remove(K k) = 0;
	virtual V get(K k) = 0;
};