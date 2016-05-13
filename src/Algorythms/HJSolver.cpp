#include "objects.h"
#include <iostream>
#include "HJSolver.h"
#include <algorithm> // min
const double EPS = 1e-10;
using namespace std;

extern "C" __declspec(dllexport) ISolver* getMethod() {
	return new CHJSolver;
}

Array<double> explore(MyFunction *f, Array <double> x, double h) {
	Array <double> res = x;
	for (size_t i = 0; i < res.size(); ++i) {
		Array <double> v1, v2;
		double result = x[i];

		// search nearby minimum
		v1 = res;
		v1[i] = res[i] + h;
		v2 = res;
		v2[i] = res[i] - h;
		// if f(v1) < f(v2)
		if ((*f)(v1)<(*f)(v2)) {
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


bool CHJSolver::solve(MyFunction *f, Array <double*> &x) {
	Array <double> x0;
	for (size_t i = 0; i < x.size(); ++i)
		x0.push_back(*x[i]);
	Array <double> x0new = x0;
	Array <double> x1 = x0;
	Array <double> cur = x0;
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
			if (h < EPS || abs((*f)(x0)) < EPS) {
				flag = 0;
				break;
			}
			else {
				h = h / 2;
				x0new = explore(f, x0, h);
			}
		}
	}

	if ((*f)(x0) > EPS) {
		Array <double> xe;
		for (size_t i = 0; i < x.size(); ++i)
			xe.push_back(*x[i]);
		(*f)(xe);
		return 0;
	}
	for (size_t i = 0; i < x.size(); ++i)	*x[i] = x0[i];
	return 1;
}


void CHJSolver::getSolution(Array<double*> &x, MyFunction *f) {solve(f, x);}

