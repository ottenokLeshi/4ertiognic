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
		virtual double diff(size_t par) {
			double x1 = _beg->getX(), x2 = _end->getX(), y1 = _beg->getY(), y2 = _end->getY(), xt = _t->getX(), yt = _t->getY();
			if (((x1 - xt)*(x1 - x2) + (y1 - yt)*(x2 - y2))*((x2 - xt)*(x1 - x2) + (y2 - yt)*(x2 - y2)) < 0) {
				if (x1 > x2 && y1 != y2) {
					switch (par) {
					case 1:
						return 2 * (yt - y2)*pow((1 + ((y1 - y2)*(y1 - y2)) / ((x1 - x2)*(x1 - x2))), -3 / 2)*
							((y1 - y2)*(y1 - y2))*pow((x1 - x2), -3) +
							2 * ((y1 - y2)*(y1 - y2))*(xt - x2)*pow(((y1 - y2)*(y1 - y2)) + ((x1 - x2)*(x1 - x2)), -3 / 2);
						break;
					case 2:
						return -2 * (xt - x2)*pow((1 + ((x1 - x2)*(x1 - x2)) / ((y1 - y2)*(y1 - y2))), -3 / 2)*
							((x1 - x2)*(x1 - x2))*pow((y1 - y2), -3) -
							2 * ((x1 - x2)*(x1 - x2))*(yt - y2)*pow(((y1 - y2)*(y1 - y2)) + ((x1 - x2)*(x1 - x2)), -3 / 2);
						break;
					case 3:
						return 2 * (yt - y2)*pow((1 + ((y1 - y2)*(y1 - y2)) / ((x1 - x2)*(x1 - x2))), -3 / 2)*
							((y1 - y2)*(y1 - y2))*pow((x2 - x1), -3) -
							(y1 - y2)*(-(xt - x2)*(x2 - x2)*pow(((y1 - y2)*(y1 - y2)) + ((x1 - x2)*(x1 - x2)), -3 / 2) +
								sqrt(((y1 - y2)*(y1 - y2)) + ((x1 - x2)*(x1 - x2))));
						break;
					case 4:
						return -2 * (xt - x2)*pow((1 + ((y1 - y2)*(y1 - y2)) / ((x1 - x2)*(x1 - x2))), -3 / 2)*
							((x1 - x2)*(x1 - x2))*pow((y2 - y1), -3) -
							(x1 - x2)*((yt - y2)*(y2 - y1)*pow(((y1 - y2)*(y1 - y2)) + ((x1 - x2)*(x1 - x2)), -3 / 2) -
								sqrt(((y1 - y2)*(y1 - y2)) + ((x1 - x2)*(x1 - x2))));
						break;
					case 5:
						return (y1 - y2) / sqrt(((y1 - y2)*(y1 - y2)) + ((x1 - x2)*(x1 - x2)));
						break;
					case 6:
						return -(x1 - x2) / sqrt(((y1 - y2)*(y1 - y2)) + ((x1 - x2)*(x1 - x2)));
						break;
					case 7:
						return 0;
						break;
					}
				}
				else if (x1 < x2 && y1 != y2) {
					switch (par) {
					case 1:
						return -(2 * (yt - y2)*pow((1 + ((y1 - y2)*(y1 - y2)) / ((x1 - x2)*(x1 - x2))), -3 / 2)*
							((y1 - y2)*(y1 - y2))*pow((x1 - x2), -3) +
							2 * ((y1 - y2)*(y1 - y2))*(xt - x2)*pow(((y1 - y2)*(y1 - y2)) + ((x1 - x2)*(x1 - x2)), -3 / 2));
						break;
					case 2:
						return -(-2 * (xt - x2)*pow((1 + ((x1 - x2)*(x1 - x2)) / ((y1 - y2)*(y1 - y2))), -3 / 2)*
							((x1 - x2)*(x1 - x2))*pow((y1 - y2), -3) -
							2 * ((x1 - x2)*(x1 - x2))*(yt - y2)*pow(((y1 - y2)*(y1 - y2)) + ((x1 - x2)*(x1 - x2)), -3 / 2));
						break;
					case 3:
						return -(2 * (yt - y2)*pow((1 + ((y1 - y2)*(y1 - y2)) / ((x1 - x2)*(x1 - x2))), -3 / 2)*
							((y1 - y2)*(y1 - y2))*pow((x2 - x1), -3) -
							(y1 - y2)*(-(xt - x2)*(x2 - x2)*pow(((y1 - y2)*(y1 - y2)) + ((x1 - x2)*(x1 - x2)), -3 / 2) +
								sqrt(((y1 - y2)*(y1 - y2)) + ((x1 - x2)*(x1 - x2)))));
						break;
					case 4:
						return -(-2 * (xt - x2)*pow((1 + ((y1 - y2)*(y1 - y2)) / ((x1 - x2)*(x1 - x2))), -3 / 2)*
							((x1 - x2)*(x1 - x2))*pow((y2 - y1), -3) -
							(x1 - x2)*((yt - y2)*(y2 - y1)*pow(((y1 - y2)*(y1 - y2)) + ((x1 - x2)*(x1 - x2)), -3 / 2) -
								sqrt(((y1 - y2)*(y1 - y2)) + ((x1 - x2)*(x1 - x2)))));
						break;
					case 5:
						return -((y1 - y2) / sqrt(((y1 - y2)*(y1 - y2)) + ((x1 - x2)*(x1 - x2))));
						break;
					case 6:
						return -(-(x1 - x2) / sqrt(((y1 - y2)*(y1 - y2)) + ((x1 - x2)*(x1 - x2))));
						break;
					case 7:
						return 0;
						break;
					}
				}
				else if (x1 == x2 && y1 != y2) {
					if (y1 > y2) {
						switch (par) {
						case 1:
							return 0;
							break;
						case 2:
							return 0;
							break;
						case 3:
							return -1;
							break;
						case 4:
							return 0;
							break;
						case 5:
							return 1;
							break;
						case 6:
							return 0;
							break;
						case 7:
							return 0;
							break;
						}
					}
					if (y1 < y2) {
						switch (par) {
						case 1:
							return 0;
							break;
						case 2:
							return 0;
							break;
						case 3:
							return 1;
							break;
						case 4:
							return 0;
							break;
						case 5:
							return -1;
							break;
						case 6:
							return 0;
							break;
						case 7:
							return 0;
							break;
						}
					}
				}
				else if (y1 == y2 && x1 != x2) {
					if (x1 > x2) {
						switch (par) {
						case 1:
							return 0;
							break;
						case 2:
							return 0;
							break;
						case 3:
							return 0;
							break;
						case 4:
							return 1;
							break;
						case 5:
							return 0;
							break;
						case 6:
							return -1;
							break;
						case 7:
							return 0;
							break;
						}
					}
					if (x1 < x2) {
						switch (par) {
						case 1:
							return 0;
							break;
						case 2:
							return 0;
							break;
						case 3:
							return 0;
							break;
						case 4:
							return -1;
							break;
						case 5:
							return 0;
							break;
						case 6:
							return 1;
							break;
						case 7:
							return 0;
							break;
						}
					}
				}
				else return 0;
			}
			else if (sqrt((x1 - xt)*(x1 - xt) + (y1 - yt)*(y1 - yt)) < sqrt((x2 - xt)*(x2 - xt) + (y2 - yt)*(y2 - yt))) {
				switch (par) {
				case 1:
					return (x1 - xt) / sqrt((x1 - xt)*(x1 - xt) + (y1 - yt)*(y1 - yt));
					break;
				case 2:
					return (y1 - yt) / sqrt((x1 - xt)*(x1 - xt) + (y1 - yt)*(y1 - yt));
					break;
				case 3:
					return 0;
					break;
				case 4:
					return 0;
					break;
				case 5:
					return (xt - x1) / sqrt((x1 - xt)*(x1 - xt) + (y1 - yt)*(y1 - yt));
					break;
				case 6:
					return (yt - y1) / sqrt((x1 - xt)*(x1 - xt) + (y1 - yt)*(y1 - yt));
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
					return (x2 - xt) / sqrt((x2 - xt)*(x2 - xt) + (y2 - yt)*(y2 - yt));
					break;
				case 4:
					return (y2 - yt) / sqrt((x2 - xt)*(x2 - xt) + (y2 - yt)*(y2 - yt));
					break;
				case 5:
					return (xt - x2) / sqrt((x2 - xt)*(x2 - xt) + (y2 - yt)*(y2 - yt));
					break;
				case 6:
					return (yt - y2) / sqrt((x2 - xt)*(x2 - xt) + (y2 - yt)*(y2 - yt));
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