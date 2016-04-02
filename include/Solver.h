#ifndef _SOLVER
#define _SOLVER
#include "BasicRestriction.h"
#include "objects.h"
#include "Array.h"
#include "RestrP2PDIST.h"
const double EPS = 1e-10;
class functi {
	BasicRestriction *_r;
	Point *_p1, *_p2;
	Segment *_S1, *_S2;
public:
	functi(Point *p1, Point *p2, BasicRestriction *r) {
		if (p1 == 0) throw 1;
		if (p2 == 0) throw 1;
		if (r == 0) throw 1;
		_p1 = p1; _p2 = p2; _r = r;
	};
	functi(Segment *S1, Segment *S2, BasicRestriction *r) {
		if (S1 == 0) throw 1;
		if (S2 == 0) throw 1;
		if (r == 0) throw 1;
		_S1 = S1; _S2 = S2; _r = r;
	};
	double operator()(const Array<double> &x) {
		_p1->setX(x[0]);
		_p1->setY(x[1]);
		return _r->violation();
	}
	double operator()(const Segment &S){
		*_S1 = S;
		return _r->violation();
	}
};
class CDer {
public:
	Array<double>& diff(functi *fun, const Array<double>&x0) {
		Array<double> *result = new Array<double>(2);
		Array<double> var(2);
		const double delta = 1e-5;
		(*result) = x0;
		for (size_t i = 0; i < (*result).size(); ++i) {
			var = x0;
			var.set_el(i, x0[i] + delta);
			(*result).set_el(i, ((*fun)(var) - (*fun)(x0)) / delta);
		}
		return *result;
	}
};
class CSol{
public:
void Solve(functi *f, Array<double>&x0) { // naive implementation >>> P2P
		Array<double> V_(2);
		double i = abs((*f)(x0))/2;
		V_.set_el(0, x0[0] + i);
		V_.set_el(1, x0[1]);
		while (abs((*f)(x0))> EPS) { // EPS = 1e-9
			while (true){ 
			if (i < EPS) break;
			if (abs((*f)(V_)) < abs((*f)(x0))) {
					x0 = V_;
					V_.set_el(0, x0[0] + i);
				continue;}
			V_ = x0;
			V_.set_el(0, x0[0] - i);
			if (abs((*f)(V_)) > abs((*f)(x0))) {
				i /= 10;
				V_ = x0; 
				V_.set_el(0, x0[0] - i);
				continue;
				}
				i /= 10;
			}
			i = abs((*f)(x0));
			if (abs((*f)(x0))< EPS) { break; }
			V_.set_el(1, x0[1] + i);
			while (true)
			{
				if (i < EPS) break;
				if (abs((*f)(V_))<abs((*f)(x0))) {
						x0 = V_; 
						V_.set_el(1, x0[1] + i);
					continue;
				}
				V_ = x0;
				V_.set_el(1, x0[1] - i);
				if (abs((*f)(V_)) > abs((*f)(x0))) {
						i /= 10;
						V_ =x0; // continue
						V_.set_el(1, x0[1] - i);
					continue;
				}
				i = abs((*f)(x0));
			}
			// end of While
			}
	} 
void Solve_2(functi *f, Array<double>&x0) { // Gradient  descent >>> P2P
	CDer A;
	bool b_mark = 1;
	double Lam = 1;
	while (abs((*f)(x0))> EPS) { // EPS = 1e-10
		if ((*f)(x0) > EPS) {			
			x0.set_el(0, x0[0] - Lam*A.diff(f, x0)[0]);
			x0.set_el(1, x0[1] - Lam*A.diff(f, x0)[1]);
			if (!b_mark) Lam /= 10;
			b_mark = 1;
			continue;
		}
		if ((*f)(x0) < EPS) {			
			x0.set_el(0, x0[0] + Lam*A.diff(f, x0)[0]);
			x0.set_el(1, x0[1] + Lam*A.diff(f, x0)[1]);
			if (b_mark) Lam /= 10;
			b_mark = 0;
			continue;
		}
	} // end of while
}
void  Solve_2(functi *f,Segment &S) { // S2SANGLE 
	CDer A;
	double X = (*S.getP1).getX()- (*S.getP2).getX(), Y = (*S.getP1).getY()- (*S.getP2).getY();
		X = cos((*f)(S))*X + (sin((*f)(S)))*Y;
		Y = -sin((*f)(S))*X + (cos((*f)(S)))*Y;
	Point Home,End(X,Y);
	Segment _vS(&Home, &End);
	S = _vS;
}
};

#endif

