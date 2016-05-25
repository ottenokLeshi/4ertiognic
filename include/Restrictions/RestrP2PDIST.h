#ifndef _RESTR_P2PDIST_H
#define _RESTR_P2PDIST_H
#include "objects.h"
#include "BasicRestriction.h"
#include "math.h"
class RestrP2PDIST:public BasicRestriction
{
public:
	RestrP2PDIST(Point *A, Point *B, double *dist)
	{
		_A = A;
		_B = B;
		_dist = dist;
		_p1x = A->getX(), _p1y = A->getY(), _p2x = B->getX(), _p2y = B->getY();
	};
	virtual ~RestrP2PDIST() {}
	virtual RestrictType get_type() const { return RT_P2PDIST; };
    virtual double violation() const {
            return *_dist - sqrt((_A->getX() - _B->getX())*(_A->getX() - _B->getX()) + (_A->getY() - _B->getY())*(_A->getY() - _B->getY()));
    }

	double length(double x1, double y1, double x2, double y2) {
		return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	}

	virtual double diff(size_t par)
	{
	switch (par) {
		case 1: // parametr _p1x
			return (_p2x - _p1x) / sqrt(length(_p1x, _p1y, _p2x, _p2y));
			break;
		case 2:// parametr _p2x
			return (_p1x - _p2x) / sqrt(length(_p1x, _p1y, _p2x, _p2y));
			break;
		case 3: //parametr _p1y
			return (_p2y - _p1y) / sqrt(length(_p1x, _p1y, _p2x, _p2y));
			break;
		case 4: // parametr _p2y
			return (_p1y - _p2y) / sqrt(length(_p1x, _p1y, _p2x, _p2y));
			break;
		case 5: // parametr *_dist
			return 1;
			break;
		}
		return 0;
	}

	double getDist() const {
		return _A->distanceToPoint(_B->getX(), _B->getY());
	}

private:
	Point *_A;
	Point *_B;
	double *_dist;
	double _p1x, _p2x, _p1y, _p2y;
};

#endif
