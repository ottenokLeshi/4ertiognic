#ifndef _SOLVER
#define _SOLVER
#include "ISolver.h"

using namespace std;

const double EPS = 1e-10;

class CGradDescSol :public ISolver {
public:
	virtual bool solve(MyFunction *f, Array <double*> &x);
	virtual void getSolution(Array<double*> &x, MyFunction *f);
};

#endif
