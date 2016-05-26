#ifndef _RESTR_P2SDISTEX_H
#define _RESTR_P2SDISTEX_H

#include "BasicRestriction.h"
#include <cmath>
class RestrP2SDISTEX : public BasicRestriction {
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
	
	virtual double diff(size_t par) {
			double x0 = _beg->getX(), xk = _end->getX(), y0 = _beg->getY(), yk = _end->getY(), xt = _t->getX(), yt = _t->getY();
			double len = sqrt((x0 - xk)*(x0 - xk) + (y0 - yk)*(y0 - yk)); // segment length
			double en = (x0 - xk) * (yk - yt) - (xk - xt) * (y0 - yk);
			if (((x0 - xt)*(x0 - xk) + (y0 - yt)*(xk - yk))*((xk - xt)*(x0 - xk) + (yk - yt)*(xk - yk)) < 0) {
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
					return (xk - xt) / len - (y0 - yk)*en / pow(len, 3);
					break;
				case 5: // parametr _p3x
					return (y0 - yk) / len;
					break;
				case 6: // parametr _p3y
					return -(x0 - xk) / len;
					break;
				case 7:
					return 1;
					break;
				}
			}
			else {
				if (length(x0, y0, xt, yt) < length(xk, yk, xt, yt)) {
					switch (par) {
					case 1:
						return (x0 - xt) / length(x0, y0, xt, yt);
						break;
					case 2:
						return (y0 - yt) / length(x0, y0, xt, yt);
						break;
					case 3:
						return 0;
						break;
					case 4:
						return 0;
						break;
					case 5:
						return -(x0 - xt) / length(x0, y0, xt, yt);
						break;
					case 6:
						return -(y0 - yt) / length(x0, y0, xt, yt);
						break;
					case 7:
						return 1;
						break;
					}
				}
				else {
					switch (par) {
					case 1:
						return 0;
						break;
					case 2:
						return 0;
						break;
					case 3:
						return (xk - xt) / length(xk, yk, xt, yt);
						break;
					case 4:
						return (yk - yt) / length(xk, yk, xt, yt);
						break;
					case 5:
						return -(xk - xt) / length(xk, yk, xt, yt);
						break;
					case 6:
						return -(yk - yt) / length(xk, yk, xt, yt);
						break;
					case 7:
						return 1;
						break;
					}
				}
			}
		}

	double getDist() const {
			double x1 = _beg->getX(), x2 = _end->getX(), y1 = _beg->getY(), y2 = _end->getY(), xt = _t->getX(), yt = _t->getY();
			double vec1x = x1 - xt, vec1y = y1 - yt, vec2x = x2 - xt, vec2y = y2 - yt, segx = x1 - x2, segy = x2 - y2;
			if ((vec1x*segx + vec1y*segy)*(vec2x*segx + vec2y*segy) < 0) {
				if (x1 == x2) {
					double k = (x1 - x2) / (y1 - y2), b = x2 - k*y2;
					return abs((k*yt - xt + b) / sqrt(k*k + 1));
				}
				double k = (y1 - y2) / (x1 - x2), b = y2 - k*x2;
				return abs((k*xt - yt + b) / sqrt(k*k + 1));
			}
			else {
				if (sqrt(vec1x*vec1x + vec1y*vec1y) < sqrt(vec2x*vec2x + vec2y*vec2y))
					return sqrt(vec1x*vec1x + vec1y*vec1y);
				else
					return sqrt(vec2x*vec2x + vec2y*vec2y);
			}
	}
private:
	Point *_beg;
	Point *_end;
	Point *_t;
	double *_min;
};
#endif