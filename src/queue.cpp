#include "../include/Queue.h"
#include <stdexcept>

template <class T> bool Queue <T>::empty() {
	return _storage.empty();
}

template <class T> void Queue <T>::pushBack(const T& data) {
	_storage.push_back(data);
}

template <class T> T Queue <T>::popFront() {
	if(empty())
		throw std::out_of_range("Empty queue");
	T tmp = _storage.front();
	_storage.erase(_storage.begin());
	return tmp;
}

template <class T> const T& Queue <T>::top() {
	if(empty())
		throw std::out_of_range("Empty queue");
	return _storage.front();
}