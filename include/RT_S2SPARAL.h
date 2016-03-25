#ifndef RT_S2SPARAL_H
#define RT_S2SPARAL_H
#include "BasicRestriction.h"


class RestrS2SPARAL : public BasicRestriction {
	Segment *_S1;
	Segment *_S2;
public: 
	RestrS2SPARAL(Segment *S1, Segment *S2)
		:_S1(S1), _S2(S2) {}
	~RestrS2SPARAL() {}
	RestrictType get_type() const { return RT_S2SPARAL; }
	double violation() const { return Angle(*_S1, *_S2); }
};

#endif