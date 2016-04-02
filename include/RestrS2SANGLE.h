#ifndef _RESTR_S2SANGLE
#define _RESTR_S2SANGLE
#include "objects.h"
#include "BasicRestriction.h"

class RestrS2SANGLE:BasicRestriction
{
public:
	RestrS2SANGLE(Segment *S1, Segment *S2, double angle)
	{
		_S1 = S1;
		_S2 = S2;
		_angle = angle;
	};
	virtual ~RestrS2SANGLE(){ }
	virtual RestrictType get_type()const{return RT_S2SANGLE;};
	virtual double violation()const { return return _S1->Angle(_S2) - _angle; }
private:
	Segment *_S1;
	Segment *_S2;
	double _angle;
};

#endif
