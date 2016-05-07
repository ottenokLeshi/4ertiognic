#ifndef _ISOLVER_H
#define _ISOLVER_H
#include "MyFunction.h"

class ISolver {
public:
	virtual bool solve(MyFunction *f, Array<double*> &x) = 0;
	virtual void getSolution(Array<double> &x, MyFunction *f) = 0;
};
#endif