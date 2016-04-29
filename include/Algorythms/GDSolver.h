#ifndef _SOLVER
#define _SOLVER
#include "ISolver.h"

#include "BasicRestriction.h"
#include "objects.h"
#include "MArray.h"
#include "RestrP2PDIST.h"
#include "RestrS2SANGLE.h"
#include <iostream>
using namespace std;
int GraphPrimitive::static_id = 0;
const double EPS = 1e-10;
// http://www.machinelearning.ru/wiki/index.php?title=%D0%9C%D0%B5%D1%82%D0%BE%D0%B4_%D0%B3%D1%80%D0%B0%D0%B4%D0%B8%D0%B5%D0%BD%D1%82%D0%BD%D0%BE%D0%B3%D0%BE_%D1%81%D0%BF%D1%83%D1%81%D0%BA%D0%B0


void FixedLength(Array <double> &X, MyFunction *fun) {


}

Array < double > diff(MyFunction *fun, const Array <double> x0) {
	Array < double > var_ = x0, RES_;
	const double DELTA = 1e-5;

	for (size_t i = 0; i < x0.size(); ++i) {
		bool _b = 0;
		for (size_t j = 0; j < f->indexFixedPar().size(); ++j)	
			if (f->indexFixedPar()[j] == i) { 
				_b = 1; 
				RES_.push_back(0); 
			}
		if (_b) continue;
		var_ = x0;
		//var_[i]  = x0[i] + DELTA;
		//cout << "Const_vector (  "; for (size_t i = 0; i < x0.size() - 1; ++i) cout << x0[i] << " ; " << x0[i + 1]; cout << "  ); " << endl;
		//cout << "Variable_vector (  "; for (size_t i = 0; i < x0.size() - 1; ++i) cout << var_[i] << " ; " << var_[i + 1]; cout << "  ); " << endl;
		//cout << "The increment of the argument: " << x0[i] << " + " << DELTA << " = " << var_[i] << endl;
		//cout << "The increment of the function: (" << (*fun)(var_) <<  "-" <<  (*fun)(x0) << ")/" << DELTA << " = " << ((*fun)(var_) - (*fun)(x0)) / DELTA << endl;
		RES_.push_back(((*fun)(var_) - (*fun)(x0)) / DELTA);
	}
	return RES_;
}



class CGradDescSol:public ISolver {
public:
	virtual void solve(MyFunction *f, Array<double> x0) { // Gradient  descent >>> P2P
		const double NUM_OF_ITER = 56;
		const double DELM = 0.95;
		Array <double> prevX = x0;
		Array <double> DIFF = x0;

		double Square = 0;
		double Lam = 1;
		double Mark = 0;
		int MMark = 0;


		for (int iterations = 1; iterations <= NUM_OF_ITER; ++iterations) {
			// Data
			prevX = x0;
			DIFF = diff(f, x0);

			for (size_t i = 0; i < x0.size(); ++i) {
//				x0.Set_el(i, x0[i] - Lam*DIFF[i]); //New value of function 
			}
			Square = 0;
			for (size_t j = 0; j<DIFF.size(); ++j) 
				Square += DIFF[j] * DIFF[j];

			while ((*f)(x0)>(*f)(prevX) - 0.1*Lam*Square) {
				Lam = Lam*DELM; // New Lambda
				x0 = prevX;
//				for (size_t i = 0; i < x0.size(); ++i) 	x0.Set_el(i, x0[i] - Lam*DIFF[i]);
			}

			double Stop = abs((*f)(x0) - (*f)(prevX));
			if (Stop <= EPS) {
				for (size_t i = 0; i < x0.size(); ++i) 
					cout << "Dot1[" << i << "] = " << x0[i] << endl;
				cout << "Volat: " << (*f)(x0);
				return;
			}
		}
		for (size_t i = 0; i < x0.size(); ++i) 
			cout << "Dot[" << i << "] = " << x0[i] << endl;
		cout << "Volat: " << (*f)(x0);
		cout << endl;
	}
	virtual void getSolution(Array<double> &x){
		x.push_back(0);
		x.push_back(1);
		x.push_back(2);
	};
};

#endif

