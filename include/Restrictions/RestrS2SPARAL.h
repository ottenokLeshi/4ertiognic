#ifndef _RESTR_S2SPARAL_H
#define _RESTR_S2SPARAL_H
#include "BasicRestriction.h"


class RestrS2SPARAL : public BasicRestriction {
	Segment *_S1;
	Segment *_S2;
public: 
	RestrS2SPARAL(Segment *S1, Segment *S2)
		:_S1(S1), _S2(S2) {}
	virtual ~RestrS2SPARAL() {}
	virtual RestrictType get_type() const { return RT_S2SPARAL; }
	virtual double violation() const { return _S1->Angle(_S2); }
	virtual double diff(size_t par) { return 0; }
};

#endif