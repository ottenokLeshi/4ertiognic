#ifndef _QUEUE_H
#define _QUEUE_H
#include "MArray.h"

template <class T> class Queue {
	Array <T> _storage;
public:
	Queue() {}
	void pushBack(const T& data);
	bool empty();
	T popFront();
	const T& top();
};

#endif