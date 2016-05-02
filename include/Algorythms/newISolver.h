#ifndef NEWISOLVER_H_
#define NEWISOLVER_H_
#include "MyFunction.h"

class newISolver {
public:
	virtual bool solve(MyFunction *f, Array<double> x0) { return 1; };
	virtual void getSolution(Array<double> &x) {};
};

#endif