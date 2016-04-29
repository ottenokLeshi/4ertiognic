#include "ISolver.h"
Array <double> MyFunction::indexFixedPar() {
	Array <double*> FixParam;
	Array <double> indexFixedParam;
	for (size_t j = 0; j < this->getSizeR(); ++j) FixParam.Connect(this->getRestr(j)->getFixP());
	for (size_t j = 0; j < FixParam.size(); ++j)
		for (size_t k = 0; k < this->getSizeP(); ++k)
			if (this->getParam(k) == FixParam[j]) indexFixedParam.push_back(k);

	return indexFixedParam;

}
size_t MyFunction::getSizeP() { return _pparams.size(); }
size_t MyFunction::getSizeR() { return _restrictions.size(); }
Array < double > MyFunction::diff(const Array <double> x0) {
	Array < double > var_ = x0, RES_;
	const double DELTA = 1e-5;
	for (size_t i = 0; i < x0.size(); ++i) {
		bool _b = 0;
		for (size_t j = 0; j < this->indexFixedPar().size(); ++j)	if (this->indexFixedPar()[j] == i) { _b = 1; RES_.push_back(0); }
		if (_b) continue;
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
		sum += abs(_restrictions[i]->violation());
	}
	return sum;
}
BasicRestriction* MyFunction::getRestr(size_t i) { return _restrictions[i]; }
void MyFunction::addRestr(BasicRestriction *rest) { _restrictions.push_back(rest); }
double* MyFunction::getParam(size_t i) { return _pparams[i]; }
