#ifndef _ISOLVER_H
#define _ISOLVER_H
#include "MArray.h"
#include "BasicRestriction.h"




class MyFunction {
	Array <BasicRestriction*> _restrictions;
	Array <double*> _pparams;
public:
	MyFunction() :_pparams(0), _restrictions(0){}
	MyFunction(const Array<double*> &p) :_pparams(p){};
	void addRestr(BasicRestriction *rest);
	BasicRestriction* getRestr(size_t i);
	double* getParam(size_t i);
	size_t getSizeR();
	size_t getSizeP();
	Array <double> indexFixedPar();
	Array < double > diff(const Array <double> x0);
	double operator()(const Array<double> x);
};


class ISolver{
public:
	virtual void solve(MyFunction *f, Array<double> &x0) = 0;	
	virtual void getSolution(Array<double> &x, MyFunction *f) = 0;
};
#endif