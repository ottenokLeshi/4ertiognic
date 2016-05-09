#ifndef _FUNCTION_H
#define _FUNCTION_H

#include "MArray.h"
#include "BasicRestriction.h"

class MyFunction {
	Array <BasicRestriction*> _restrictions;
	Array <double*> _pparams;

public:
	MyFunction() :_pparams(0), _restrictions(0) {}
	MyFunction(const Array<double*> &p) :_pparams(p) {};
	void addRestr(BasicRestriction *rest);
	Array < double > diff(const Array <double> x0);
	double operator()(const Array<double> x);
	Array <double*> getParam() const { return _pparams; }
};
#endif