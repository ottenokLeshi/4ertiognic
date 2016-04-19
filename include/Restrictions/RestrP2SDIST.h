#ifndef _RESTR_P2SDIST_H
#define _RESTR_P2SDIST_H

#include "BasicRestriction.h"
#include <cmath>

class RestrP2SDIST : public BasicRestriction {
public:
	RestrP2SDIST( Point *beg, Point *end, Point *t, double *dist)
		:_beg (beg),_end(end),_t(t),_dist(dist){}

	virtual ~RestrP2SDIST() {}
	virtual RestrictType get_type() const { return RT_P2SDIST; }
	virtual double violation() const {
		double x1 = _beg->getX(), x2 = _end->getX(), y1 = _beg->getY(), y2 = _end->getY(), xt = _t->getX(), yt = _t->getY();
		if (x1 == x2) {
			double k = (x1 - x2) / (y1 - y2), b = x2 - k*y2;
			return (*_dist - abs((k*yt - xt + b) / sqrt(k*k + 1)));
		}
		double k = (y1 - y2) / (x1 - x2), b = y2 - k*x2;
		return (*_dist - abs((k*xt-yt+b)/sqrt(k*k+1)));
	}
private:
	Point *_beg;
	Point *_end;
	Point *_t;
	double *_dist;
};
#endif