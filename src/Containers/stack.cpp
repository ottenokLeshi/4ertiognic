#include "Stack.h"
#include <stdexcept>

template <class T> bool Stack <T>::empty() {
	return _storage.empty();
}

template <class T> void Stack <T>::push(const T& data) {
	_storage.push_back(data);
}

template <class T> T Stack <T>::pop() {
	if(empty())
		throw std::out_of_range("Empty Stack");
	T tmp = _storage.back();
	_storage.erase(--(_storage.end()));
	return tmp;
}

template <class T> const T& Stack <T>::top() {
	if(empty())
		throw std::out_of_range("Empty Stack");
	return _storage.back();
}