#ifndef _SOLVER
#define _SOLVER
#include "ISolver.h"
#include "BasicRestriction.h"
#include "objects.h"
#include "MArray.h"
#include "RestrP2PDIST.h"
#include "RestrS2SANGLE.h"
#include <iostream>
using namespace std;
 
const double EPS = 1e-10;

class CGradDescSol :public ISolver {
public:
	__declspec(dllexport) virtual void solve(MyFunction *f, Array<double> &x0);
	__declspec(dllexport) virtual void getSolution(Array<double> &x, MyFunction *f);
};

#endif

