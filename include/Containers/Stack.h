#ifndef _STACK_H
#define _STACK_H
#include "MArray.h"

template <class T> class Stack {
	Array <T> _storage;
public:	
	Stack() {};
	void push(const T& data);
	const T& top();
	T pop();
	bool empty();
};
#endif