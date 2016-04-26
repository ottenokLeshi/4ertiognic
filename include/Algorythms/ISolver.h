#ifndef _ISOLVER_H
#define _ISOLVER_H
#include "MArray.h"
#include "BasicRestriction.h"


class MyFunction {
	Array <BasicRestriction*> _restrictions;
	Array <double*> _pparams;
	double AbsViol;
public:
	MyFunction() :_pparams(0), _restrictions(0),AbsViol(-1) {}
	MyFunction(const Array<double*> &p) :_pparams(p),AbsViol(-1) {};
	void addRestr(BasicRestriction *rest) { _restrictions.push_back(rest); }

	BasicRestriction* getRestr(size_t i) { return _restrictions[i]; }
	double* getParam(size_t i) { return _pparams[i]; }
	size_t getSizeR() { return _restrictions.size(); }
	size_t getSizeP() { return _pparams.size(); }
	friend Array <double> indexFixedPar(MyFunction*);


	double operator()(const Array<double> x) {
		double sum = 0;
		for (size_t i = 0; i < x.size(); ++i) {
			*_pparams[i] = x[i];
		}

		for (size_t i = 0; i < _restrictions.size(); ++i) {
			AbsViol = abs(_restrictions[i]->violation());
			sum += abs(_restrictions[i]->violation());
		}
		return sum;
	}
};


class ISolver{
public:
	virtual void solve(MyFunction *f, Array<double> x0) = 0;	
	virtual void getSolution(Array<double> &x) = 0;

};
#endif