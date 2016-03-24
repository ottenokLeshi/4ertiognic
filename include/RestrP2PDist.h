#ifndef _RESTR_P2PDIST_H
#define _RESTR_P2PDIST_H
#include "Point.h"
#include "BasicRestriction.h"

class RestrP2PDist:BasicRestriction
{
public:
	RestrP2PDist(Point *beg, Point *end, double *dist)
	{
		_beg = beg;
		_end = end;
		_dist = dist;
	};
	RestrictType get_type()const{return RT_P2PDIST;};
	double violation()const{return 0;};
private:
	Point *_beg;
	Point *_end;
	double _dist;
};

#endif
