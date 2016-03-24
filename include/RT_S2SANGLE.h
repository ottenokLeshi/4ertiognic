#ifndef _RT_S2SANGLE
#define _RT_S2SANGLE
#include "objects.h"
#include "BasicRestriction.h"

class RT_S2SANGLE:BasicRestriction
{
public:
	RT_S2SANGLE(Segment *S1, Segment *S2, double angle)
	{
		_S1 = S1;
		_S2 = S2;
		_angle = angle;
	};
	~RT_S2SANGLE(){ }
	RestrictType get_type()const{return RT_S2SANGLE;};
	double violation()const{return Angle(*_S1,*_S2)-_angle};
private:
	Segment *_S1;
	Segment *_S2;
	double _angle;
};

#endif
