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
	virtual RestrictType get_type() const { return RT_P2PDIST; };
        virtual double violation() const {
                return *_dist - sqrt((_A->getX() - _B->getX())*(_A->getX() - _B->getX()) + (_A->getY() - _B->getY())*(_A->getY() - _B->getY()));
        }
private:
	Point *_A;
	Point *_B;
	double *_dist;
};

#endif
