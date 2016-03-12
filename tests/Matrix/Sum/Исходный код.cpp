#include <iostream>
#include "matrix.h"

bool testSumRes(){
	Matrix<double> dm(2,2);
	Matrix<double> m(2,2);

	Matrix<double> res = dm+m;
	for (size_t r = 0; r < res.numrows();++r)
		for (size_t c = 0;c< res.numcols();++c)
			if (res.getElem(r,c) != dm.getElem(r,c)+m.getElem(r,c))
				return false;				/// ACHTUNG !!!!
}

int main(){
	std::cout << "Test sum OK ?"  << testSumRes() << std::endl;
	return 0;
}