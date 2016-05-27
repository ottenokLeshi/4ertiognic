#ifndef _RESTR_P2SDIST_H
#define _RESTR_P2SDIST_H

#include "BasicRestriction.h"
#include <cmath>

class RestrP2SDIST : public BasicRestriction {
public:
	RestrP2SDIST( Point *beg, Point *end, Point *t, double *dist){
		_dist = dist;
		_beg = beg; _end = end; _t = t;
		x0 = _beg->getX();
		xk = _end->getX();
		xt = _t->getX();
		y0 = _beg->getY();
		yk = _end->getY();
		yt = _t->getY();
		len = sqrt((x0 - xk)*(x0 - xk) + (y0 - yk)*(y0 - yk)); // segment length
		en = x0*yk - xk*y0 - yt*(x0 - xk) + xt*(y0 - yk); // enumerator
	}

	virtual ~RestrP2SDIST() {}
	virtual RestrictType get_type() const { return RT_P2SDIST; }
	virtual double violation() const {
		double a = y0 - yk;
		double b = xk - x0;
		double c = x0*yk - xk*y0;
		return *_dist - abs(a*xt + b*yt + c) / len;          
	}
//	virtual Array<double>* diff() {}
	virtual double diff(size_t par) {
		switch (par) {
		case 1: // parametr _p1x
			return (yk - yt) / len - (x0 - xk)*en / pow(len, 3);
			break;
		case 2: // parametr _p1y
			return -(xk - xt) / len - (y0 - yk)*en / pow(len, 3);
			break;
		case 3: // parametr _p2x
			return -(y0 - yt) / len + (x0 - xk)*en / pow(len, 3);
			break;
		case 4: // parametr _p2y
			return (x0 - xt) / len + (y0 - yk)*en / pow(len, 3);
			break;
		case 5: // parametr _p3x
			return (y0 - yk) / len;
			break;
		case 6: // parametr _p3y
			return (x0 - xk) / len;
			break;
		case 7:
			return 1;
			break;
		}
		return 0;
	}
	double getDist() const {
		if (_beg->getX() == _end->getX()) {
			double k = (_beg->getX() - _end->getX()) / (_beg->getY() - _end->getY()), b = _end->getX() - k*_end->getY();
			return (abs((k*_t->getY() - _t->getX() + b) / sqrt(k*k + 1)));
		}
		double k = (_beg->getY() - _end->getY()) / (_beg->getX() - _end->getX()), b = _end->getY() - k*_end->getX();
		return (abs((k*_t->getX() - _t->getY() + b) / sqrt(k*k + 1)));
	}

private:
	Point *_beg;
	Point *_end;
	Point *_t;
	double *_dist;
	double x0,xk,xt,y0,yk,yt;
	double len, en;
};
#endif