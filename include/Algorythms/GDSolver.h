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
// http://www.machinelearning.ru/wiki/index.php?title=%D0%9C%D0%B5%D1%82%D0%BE%D0%B4_%D0%B3%D1%80%D0%B0%D0%B4%D0%B8%D0%B5%D0%BD%D1%82%D0%BD%D0%BE%D0%B3%D0%BE_%D1%81%D0%BF%D1%83%D1%81%D0%BA%D0%B0



class CGradDescSol:public ISolver {
public:
	virtual void solve(MyFunction *f, Array<double> &x0);
	virtual void getSolution(Array<double> &x, MyFunction *f);
};

#endif

