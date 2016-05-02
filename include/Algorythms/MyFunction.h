#include "MArray.h"
#include "BasicRestriction.h"

class MyFunction {
	Array <BasicRestriction*> _restrictions;
	Array <double*> _pparams;
public:
	MyFunction() :_pparams(0), _restrictions(0) {}
	MyFunction(const Array<double*> &p) :_pparams(p) {};
	void addRestr(BasicRestriction *rest) { _restrictions.push_back(rest); }
	BasicRestriction* getRestr(size_t i) { return _restrictions[i]; }
	double* getParam(size_t i) { return _pparams[i]; }
	size_t getSizeR() { return _restrictions.size(); }
	size_t getSizeP() { return _pparams.size(); }

	double operator()(const Array <double> &x) {
		double sum = 0;
		for (size_t i = 0; i < x.size(); ++i) 
			*_pparams[i] = x[i];
		for (size_t i = 0; i < _restrictions.size(); ++i) {
			sum += abs(_restrictions[i]->violation());
		}
		return sum;
	}
};