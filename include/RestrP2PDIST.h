#ifndef _RESTR_P2PDIST_H
#define _RESTR_P2PDIST_H
#include "objects.h"
#include "BasicRestriction.h"

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
	virtual RestrictType get_type()const { return RT_P2PDIST; };
        virtual double violation() const {
        	double realDist = Point::dist_points(&_A, &_B);
        	return *_dist - realDist;
        }
private:
	Point *_A;
	Point *_B;
	double _dist;
};
/*
 * In objects.h
 * static dist_points(Point *A, Point *B);
 *
*/
#endif
