#ifndef _EQUATION_H
#define _EQUATION_H

class Equation {
	int _n;
public:
	double* _a;
	Equation() :
		_n(0), _a(0) {};
	Equation(const int n) {
		_n = n;
		double* _a = (double*)calloc(_n, sizeof(double));
	};
};

#endif