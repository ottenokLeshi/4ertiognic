#ifndef HJSOLVER_H_
#define HJSOLVER_H_
#include "newISolver.h"

class CHJSolver : public newISolver {
public:
	virtual bool solve(MyFunction *f, Array <double*> &x);
	virtual void getSolution(Array<double*> &x);
};

#endif