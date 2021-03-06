#include "GDSolver.h"
#include "objects.h"
int GraphPrimitive::static_id = 0;
int BasicRestriction::static_id = 0;

extern "C" __declspec(dllexport) ISolver* getMethod() {
	return new CGradDescSol;
}

bool CGradDescSol::solve(MyFunction *f, Array <double*> &x) { // Gradient  descent >>> P2P
	Array <double> x0;
	for (size_t i = 0; i < x.size(); ++i)
		x0.push_back(*x[i]);
	const double NUM_OF_ITER = 56;
	const double DELM = 0.95;
	Array <double> prevX = x0;
	Array <double> DIFF = x0;

	double Square = 0;
	double Lam = 1;
	double Mark = 0;
	int MMark = 0;


	for (int Iterations = 1; Iterations <= NUM_OF_ITER; ++Iterations) {
		// Data

		prevX = x0;
		DIFF = f->diff(x0);

		for (size_t i = 0; i < x0.size(); ++i) {
			x0.Set_el(i, x0[i] - Lam*DIFF[i]); //New value of function 
		}
		Square = 0;

		for (size_t j = 0; j<DIFF.size(); ++j) Square += DIFF[j] * DIFF[j];

		while ((*f)(x0)>(*f)(prevX) - 0.1*Lam*Square) {
			Lam = Lam*DELM; // New Lambda
			x0 = prevX;
			for (size_t i = 0; i < x0.size(); ++i) 	x0.Set_el(i, x0[i] - Lam*DIFF[i]);
		}

		double Stop = abs((*f)(x0) - (*f)(prevX));
		if (Stop <= EPS) { for (size_t i = 0; i < x.size(); ++i)	*x[i] = x0[i]; return 1; }
	}
	return 0;
}
void CGradDescSol::getSolution(Array<double*> &x, MyFunction *f) { solve(f, x); };