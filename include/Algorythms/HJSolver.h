#include "ISolver.h"
#include "objects.h"
#include <iostream>
#include <algorithm> // min
const double EPS = 1e-10;
using namespace std;

class CHJSolver : public ISolver {
	Array <double> sol;
public:
	virtual void solve(MyFunction *f, Array <double> &x);
	virtual void getSolution(Array<double> &x);
};


Array<double> explore(MyFunction *f, Array <double> x, double h) {
	Array <double> res = x;
	for (size_t i = 0; i < res.size(); ++i) {
		Array <double> v1, v2;
		double result = x[i];
		bool fixed = 0;
		// check if param is fixed
		for (size_t j = 0; j < f->indexFixedPar().size(); ++j)
			if (f->indexFixedPar()[j] == i) { 
				fixed = 1;
				res[i] = result;
			}
		if (fixed) continue;
		
		v1 = res;
		v1[i] = res[i] + h;
		v2 = res;
		v2[i] = res[i] - h;
		// if f(v1) < f(v2)
		if (min((*f)(v1), (*f)(v2)) == (*f)(v1)) {
			// if f(v1) < f(x)
			if ((*f)(v1) < (*f)(x)) {
				result = res[i] + h;
			}
		}
		else {
			if ((*f)(v2) < (*f)(x)) {
				result = res[i] - h;
			}
		}
		res[i] = result;
	}
	return res;
}


void CHJSolver::solve(MyFunction *f, Array <double> &x) {
	Array <double> x0 = x;
	Array <double> x0new = x;
	Array <double> x1 = x;
	Array <double> cur = x;
	double h = 1;

	bool flag = 1;

	x0new = explore(f, x0, h);
	while (flag) {
		if ((*f)(x0new) < (*f)(x0)) {
			// pattern search
			for (size_t i = 0; i < x0new.size(); ++i) {
				x1[i] = x0[i] + 2 * (x0new[i] - x0[i]);
			}
			cur = explore(f, x1, h);
			if ((*f)(cur) < (*f)(x0new)) {
				x0 = x0new;
				x0new = cur;
			}
			else {
				x0 = x0new;
				x0new = explore(f, x0, h);
			}
		}
		else {
			if (h < EPS) {
				flag = 0;
				break;
			}
			else {
				h = h / 2;
				x0new = explore(f, x0, h);
			}
		}
	}
	x = x0;
	sol = x0;
}

void CHJSolver::getSolution(Array<double> &x) {
	x = sol;
}