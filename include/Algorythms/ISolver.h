#ifndef _ISOLVER_H
#define _ISOLVER_H
#include "Function.h"

class ISolver {
public:
	virtual void solve(MyFunction *f, Array<double> &x0) = 0;
	virtual void getSolution(Array<double> &x, MyFunction *f) = 0;
};
#endif