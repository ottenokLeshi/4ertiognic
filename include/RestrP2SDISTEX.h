#ifndef _RESTR_P2SDISTEX_H
#define _RESTR_P2SDISTEX_H

#include "BasicRestriction.h"
#include <cmath>
class RestrP2SDISTEX : BasicRestriction {
public:
	RestrP2SDISTEX(Point *beg, Point *end, Point *t, double *min)
		:_beg(beg), _end(end), _t(t), _min(min) {}

	virtual ~RestrP2SDISTEX() {}
	virtual RestrictType get_type() const { return RT_P2SDISTEX; }
	virtual double violation() const {
		double x1 = _beg->getX(), x2 = _end->getX(), y1 = _beg->getY(), y2 = _end->getY(), xt = _t->getX(), yt = _t->getY();
		double vec1x = x1 - xt, vec1y = y1 - yt, vec2x = x2 - xt, vec2y = y2 - yt, segx = x1 - x2, segy = x2 - y2;
		if ((vec1x*segx + vec1y*segy)*(vec2x*segx + vec2y*segy) < 0) {
			if (x1 == x2) {
				double k = (x1 - x2) / (y1 - y2), b = x2 - k*y2;
				return *_min - abs((k*yt - xt + b) / sqrt(k*k + 1));
			}
			double k = (y1 - y2) / (x1 - x2), b = y2 - k*x2;
			return *_min - abs((k*xt - yt + b) / sqrt(k*k + 1));
		}
		else { 
			if (sqrt(vec1x*vec1x + vec1y*vec1y) < sqrt(vec2x*vec2x + vec2y*vec2y))
				return *_min - sqrt(vec1x*vec1x + vec1y*vec1y);
			else
				return *_min - sqrt(vec2x*vec2x + vec2y*vec2y);
		}
	}
private:
	Point *_beg;
	Point *_end;
	Point *_t;
	double *_min;
};
#endif