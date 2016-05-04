#ifndef _ISOLVER_H
#define _ISOLVER_H
#include "MArray.h"
#include "BasicRestriction.h"
#include "Function.h"
class ISolver {
public:
	__declspec(dllexport)	virtual void solve(MyFunction *f, Array<double> &x0) = 0;
	__declspec(dllexport)   virtual void getSolution(Array<double> &x, MyFunction *f) = 0;
};
#endif