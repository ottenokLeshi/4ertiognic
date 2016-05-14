#include "../include/Algorythms/Function.h"
#include <cmath>
Array < double > MyFunction::diff(const Array <double> x0) {
	Array < double > var_ = x0, RES_;
	const double DELTA = 1e-5;
	for (size_t i = 0; i < x0.size(); ++i) {
		var_ = x0;
		var_.Set_el(i, x0[i] + DELTA);
		RES_.push_back(((*this)(var_) - (*this)(x0)) / DELTA);
	}
	return RES_;
}
double MyFunction::operator()(const Array<double> x) {
	double sum = 0;
	for (size_t i = 0; i < x.size(); ++i) {
		*_pparams[i] = x[i];
	}

	for (size_t i = 0; i < _restrictions.size(); ++i) {
        sum += std::abs(_restrictions[i]->violation());
	}
	return sum;
}
void MyFunction::addRestr(BasicRestriction *rest) { _restrictions.push_back(rest); }
