#ifndef _SOLVER
#define _SOLVER
#include "BasicRestriction.h"
#include "objects.h"
#include "Nelder-Mead_Method.h"
#include "Array.h"
#include "RestrP2PDIST.h"
#include "RestrS2SANGLE.h"
const double EPS = 1e-10;

class MyFunction {
	BasicRestriction *_r;
	Point *_p1, *_p2;
	Segment *_S1, *_S2;
public:
	MyFunction() {
		_r = 0;
		_p1 = new Point;
		_p2 = new Point;
		_S1 = new Segment;
		_S2 = new Segment;
	}
	MyFunction(Point *p1, Point *p2, BasicRestriction *r) {
		if (p1 == 0) throw 1;
		if (p2 == 0) throw 1;
		if (r == 0) throw 1;
		_p1 = p1; _p2 = p2; _r = r;
	};
	MyFunction(Segment *S1, Segment *S2, BasicRestriction *r) {
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
	double operator()(Segment &S){
		*_S1 = S;
		return _r->violation();
	}
	double operator()(const Vertex &V) {
		(*_p1).setX(V.x);
		(*_p1).setX(V.y);
		return _r->violation();
	}

};


class CDer {
public:
	Array<double>& diff(MyFunction *fun, const Array<double>&x0) {
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
	Segment& diff(MyFunction *fun, Segment &S) {
		const double delta = 1e-5;
		Segment *_rS = new Segment, _v;
		(*_rS) = S;
		// increment for x of point 1
		_v = S;
		_v.getP1()->setX(S.getP1()->getX() + delta); cout << "\n Xp1 in Diff = " << S.getP1()->getX() + delta;
		_rS->getP1()->setX(((*fun)(S) - (*fun)(_v)) / delta); std::cout << "\n Diiff" << ((*fun)(S) - (*fun)(_v)) / delta << "\n";
		// increment for y of point 1
		_v = S;
		_v.getP1()->setY(S.getP1()->getY() + delta);  cout << "\n Yp1 in Diff = " << S.getP1()->getY() + delta;
		_rS->getP1()->setY(((*fun)(S) - (*fun)(_v)) / delta); std::cout << "\n Diiff" << ((*fun)(S) - (*fun)(_v)) / delta << "\n";
		// increment for x of point 2
		_v = S;
		_v.getP2()->setX(S.getP2()->getX() + delta);
		_rS->getP2()->setX(((*fun)(S) - (*fun)(_v)) / delta); std::cout << "\n Diiff" << ((*fun)(S) - (*fun)(_v)) / delta << "\n";
		// increment for y of point 2
		_v = S;
		_v.getP2()->setY(S.getP2()->getY() + delta);
		_rS->getP2()->setY(((*fun)(S) - (*fun)(_v)) / delta); std::cout << "\n Diiff" << ((*fun)(S) - (*fun)(_v)) / delta << "\n";
		return *_rS;
	}

};

class CSol{
public:
void Solve(MyFunction *f, Array<double>&x0) { // naive implementation >>> P2P
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
void Solve_2(MyFunction *f, Array<double>&x0) { // Gradient  descent >>> P2P
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
void  Solve_2(MyFunction *f, Segment &S) { // S2SANGLE
	CDer _Der;
	Segment GRAD;
	double Lam = 1;
	bool b_mark = 1;
	while (abs((*f)(S)) > EPS) {
		GRAD = _Der.diff(f, S);
		if ((*f)(S) > EPS) {
			S.getP1()->setX(S.getP1()->getX() - GRAD.getP1()->getX());
			S.getP1()->setY(S.getP1()->getY() - GRAD.getP1()->getY());
			S.getP2()->setX(S.getP2()->getX() - GRAD.getP2()->getX());
			S.getP2()->setY(S.getP2()->getY() - GRAD.getP2()->getY());
			if (!b_mark) Lam /= 10;
			b_mark = 1;
			continue;
		}
		if ((*f)(S) < EPS) {
			S.getP1()->setX(S.getP1()->getX() + GRAD.getP1()->getX());
			S.getP1()->setY(S.getP1()->getY() + GRAD.getP1()->getY());
			S.getP2()->setX(S.getP2()->getX() + GRAD.getP2()->getX());
			S.getP2()->setY(S.getP2()->getY() + GRAD.getP2()->getY());
			if (b_mark) Lam /= 10;
			b_mark = 0;
		}
	}
}
};

#endif
