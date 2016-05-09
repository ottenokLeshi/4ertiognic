#ifndef _ISOLVER_H
#define _ISOLVER_H
#include "MArray.h"
#include "BasicRestriction.h"
#include "Function.h"
class ISolver {
public:
	virtual bool solve(MyFunction *f, Array <double*> &x) = 0;
	virtual void getSolution(Array<double*> &x, MyFunction *f) = 0;
};
#endif