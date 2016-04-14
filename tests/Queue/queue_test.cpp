#include <iostream>
#include "../../src/queue.cpp"

bool testQueueEmpty(){
	Queue<size_t> que;
	if ( !que.empty() ) return false;
	for (size_t k = 0;k < 100;++k)
		que.pushBack(k);
	for (size_t k = 0;k < 100;++k)
		que.popFront();
	if ( !que.empty() ) return false;
	return true;
}
bool testQueueAccess(){
	Queue<int> que;	
	for (int k = 0;k < 100;++k)
		que.pushBack(k);
	for (int k = 0;k < 100;++k){
		if (que.top() != k ) return false;
		que.popFront();
	}
	return true;
}

bool testQueueNoEl(){
	Queue<int> que;	
	for (int k = 0;k < 100;++k)
		que.pushBack(k);
	try {
		for (int k = 0;k < 101;++k) 
			que.popFront();
	} 
	catch(std::out_of_range){
		return true;
	}
	return false;
}

int main(){
	std::cout << "testQueueEmpty " << testQueueEmpty() << std::endl;
	std::cout << "testQueueAccess " << testQueueAccess() << std::endl;
	std::cout << "testQueueNoEl " << testQueueNoEl() << std::endl;
	return 0;
}