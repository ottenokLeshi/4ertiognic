#include <iostream>
#include "dllsample.h"


int main(){
	ISolver *solver = getSolver();
	Array<double> s;
	solver->getSolution(s);
	std::cout << s[0] << s[1] <<std::endl;

	return 0;
}