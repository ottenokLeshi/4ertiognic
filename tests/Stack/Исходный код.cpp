#include <iostream>
#include "Stack.h"

bool testStackEmpty(){
	Stack<size_t> sta;
	if ( !sta.empty() ) return false;
	for (size_t k = 0;k < 100;++k)
		sta.push(k);
	for (size_t k = 0;k < 100;++k)
		sta.pop();
	if ( !sta.empty() ) return false;
	return true;
}
bool testStackAccess(){
	Stack<int> sta;	
	for (int k = 0;k < 100;++k)
		sta.push(k);
	for (int k = 99;k > -1;--k){
		if (sta.top() != k ) return false;
		sta.pop();
	}
	return true;
}

bool testStackNoEl(){
	//  огда достаем из стека больше чем положили

	return true;
}

int main(){
	std::cout << "testStackEmpty " << testStackEmpty() << std::endl;
	std::cout << "testStackAccess " << testStackAccess() << std::endl;
	std::cout << "testStackNoEl " << testStackNoEl() << std::endl;
	return 0;
}