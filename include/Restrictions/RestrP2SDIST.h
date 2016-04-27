#ifndef _RESTR_P2SDIST_H
#define _RESTR_P2SDIST_H

#include "BasicRestriction.h"
#include <cmath>

class RestrP2SDIST : public BasicRestriction {
public:
	RestrP2SDIST( Point *beg, Point *end, Point *t, double *dist){
		_beg = beg; _end = end; _t = t;
		_p1x = _beg->getX();
		_p2x = _end->getX();
		_p3x = _t->getX();
		_p1y = _beg->getY();
		_p2y = _end->getY();
		_p3y = _t->getY();
	}

	virtual ~RestrP2SDIST() {}
	virtual RestrictType get_type() const { return RT_P2SDIST; }
	virtual double violation() const {
		if (_p1x == _p2x) {
			double k = (_p1x - _p2x) / (_p1y - _p2y), b = _p2x - k*_p2y;
			return (*_dist - abs((k*_p3y - _p3x + b) / sqrt(k*k + 1)));
		}
		double k = (_p1y - _p2y) / (_p1x - _p2x), b = _p2y - k*_p2x;
		return (*_dist - abs((k*_p3x-_p3y+b)/sqrt(k*k+1)));
	}

	virtual double diff(size_t par) {
		if (par == 7)
			return 1;
		if (_p1x*(_p2y - _p3y) + _p1y*(_p3x - _p2x) + _p3y * _p2x - _p2y * _p3x > 0)
		switch (par) {
		case 1: // parametr _p1x
				return (_p3y - _p2y) / length(_p2x, _p2y, _p3x, _p3y);
				break;
		case 2: // parametr _p1y
				return (_p2x - _p3x) / length(_p2x, _p2y, _p3x, _p3y);
				break;
		case 3: // parametr _p2x
				return ((_p1y - _p3y)*length(_p2x, _p2y, _p3x, _p3y) + (_p2x - _p3x)*
					abs(_p1x*(_p2y - _p3y) + _p1y*(_p3x - _p2x) + _p3y * _p2x - _p2y * _p3x) / length(_p2x, _p2y, _p3x, _p3y)) /
				pow(length(_p2x, _p2y, _p3x, _p3y), 2);
				break;
		case 4: // parametr _p2y
				return ((_p3x - _p1x)*length(_p2x, _p2y, _p3x, _p3y) + (_p2y - _p3y)*
					abs(_p1x*(_p2y - _p3y) + _p1y*(_p3x - _p2x) + _p3y * _p2x - _p2y * _p3x) / length(_p2x, _p2y, _p3x, _p3y)) /
				pow(length(_p2x, _p2y, _p3x, _p3y), 2);
				break;
		case 5: // parametr _p3x
				return ((_p2y - _p1y)*length(_p2x, _p2y, _p3x, _p3y) + (_p3x - _p2x)*
					abs(_p1x*(_p2y - _p3y) + _p1y*(_p3x - _p2x) + _p3y * _p2x - _p2y * _p3x) / length(_p2x, _p2y, _p3x, _p3y)) /
				pow(length(_p2x, _p2y, _p3x, _p3y), 2);
				break;
		case 6: // parametr _p3y
				return ((_p1x - _p2x)*length(_p2x, _p2y, _p3x, _p3y) + (_p3y - _p2y)*
					abs(_p1x*(_p2y - _p3y) + _p1y*(_p3x - _p2x) + _p3y * _p2x - _p2y * _p3x) / length(_p2x, _p2y, _p3x, _p3y)) /
				pow(length(_p2x, _p2y, _p3x, _p3y), 2);
				break;
		}
		else
			if (_p1x*(_p2y - _p3y) + _p1y*(_p3x - _p2x) + _p3y * _p2x - _p2y * _p3x < 0)
			switch (par) {
			case 1:// parametr _p1x
					return (-1)*(_p3y - _p2y) / length(_p2x, _p2y, _p3x, _p3y);
					break;
			case 2:// parametr _p1y
					return (-1)*(_p2x - _p3x) / length(_p2x, _p2y, _p3x, _p3y);
					break;
			case 3: // parametr _p2x
					return (-1)*((_p1y - _p3y)*length(_p2x, _p2y, _p3x, _p3y) + (_p2x - _p3x)*
						abs(_p1x*(_p2y - _p3y) + _p1y*(_p3x - _p2x) + _p3y * _p2x - _p2y * _p3x) / length(_p2x, _p2y, _p3x, _p3y)) /
					pow(length(_p2x, _p2y, _p3x, _p3y), 2);
					break;
			case 4: // parametr _p2y
					return (-1)*((_p3x - _p1x)*length(_p2x, _p2y, _p3x, _p3y) + (_p2y - _p3y)*
						abs(_p1x*(_p2y - _p3y) + _p1y*(_p3x - _p2x) + _p3y * _p2x - _p2y * _p3x) / length(_p2x, _p2y, _p3x, _p3y)) /
					pow(length(_p2x, _p2y, _p3x, _p3y), 2);
					break;
			case 5: // parametr _p3x
					return (-1)*((_p2y - _p1y)*length(_p2x, _p2y, _p3x, _p3y) + (_p3x - _p2x)*
						abs(_p1x*(_p2y - _p3y) + _p1y*(_p3x - _p2x) + _p3y * _p2x - _p2y * _p3x) / length(_p2x, _p2y, _p3x, _p3y)) /
					pow(length(_p2x, _p2y, _p3x, _p3y), 2);
					break;
			case 6: // parametr _p3y
					return (-1)*((_p1x - _p2x)*length(_p2x, _p2y, _p3x, _p3y) + (_p3y - _p2y)*
						abs(_p1x*(_p2y - _p3y) + _p1y*(_p3x - _p2x) + _p3y * _p2x - _p2y * _p3x) / length(_p2x, _p2y, _p3x, _p3y)) /
					pow(length(_p2x, _p2y, _p3x, _p3y), 2);
					break;
			}
		return 0;
		
	}
private:
	Point *_beg;
	Point *_end;
	Point *_t;
	double *_dist;
	double _p1x, _p2x, _p3x, _p1y, _p2y, _p3y;
};
#endif