#ifndef HJSOLVER_H_
#define HJSOLVER_H_
#include "ISolver.h"

class CHJSolver : public ISolver {
public:
	virtual bool solve(MyFunction *f, Array <double*> &x);
	virtual void getSolution(Array<double*> &x, MyFunction *f);

};

#endif