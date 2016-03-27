#ifndef _SOLVER
#define _SOLVER
#include "BasicRestriction.h"
#include "objects.h"
#include "Array.h"
#include "RestrP2PDIST.h"
const double EPS = 1e-10;
class functi {
	BasicRestriction *_r;
	Point*_p1, *_p2;
public:
	functi(Point *p1, Point *p2, BasicRestriction *r) {
		if (p1 == 0) throw 1;
		if (p2 == 0) throw 1;
		if (r == 0) throw 1;
		_p1 = p1; _p2 = p2; _r = r;
	};
	double operator()(const Array<double> &x) {
		_p1->setX(x[0]);
		_p1->setY(x[1]);
		return _r->violation();
	}
};
Array<double>& diff(functi *fun, const Array<double>&x0) {
	Array<double> *result = new Array<double>(2);
	Array<double> var(2);
	const double delta = 1e-5;
	(*result) = x0;
		for (size_t i = 0; i < (*result).size(); ++i){
		var = x0;
		var.set_el(i, x0[i] + delta);
		(*result).set_el(i, ((*fun)(var) - (*fun)(x0)) / delta);
		}
	return *result;
}
class solver {
public:
	solver(functi *f, Array<double>&x0) {
		while (abs((*f)(x0))> EPS) { // EPS = 1e-10
			if ((*f)(x0) > EPS) {
				x0.set_el(0, x0[0] - diff(f, x0)[0]);
				x0.set_el(0, x0[1] - diff(f, x0)[1]);
			}
			if ((*f)(x0) < EPS) {
				x0.set_el(0, x0[0] + diff(f, x0)[0]);
				x0.set_el(0, x0[1] + diff(f, x0)[1]);
			}
		}
	}
};
#endif
