#ifndef _RESTR_P2PDIST_H
#define _RESTR_P2PDIST_H
#include "objects.h"
#include "BasicRestriction.h"
#include "math.h"
class RestrP2PDIST:BasicRestriction
{
public:
	RestrP2PDIST(Point *A, Point *B, double *dist)
	{
		_A = A;
		_B = B;
		_dist = dist;
	};
	virtual ~RestrP2PDIST() {}
	virtual RestrictType get_type() { return RT_P2PDIST; };
        virtual double violation() {
        	return *_dist - sqrt((A->getX() - B->getX())*(A->getX() - B->getX()) + (A->getY() - B->getY())*(A->getY() - B->getY()));
        }
private:
	Point *_A;
	Point *_B;
	double *_dist;
};

#endif
