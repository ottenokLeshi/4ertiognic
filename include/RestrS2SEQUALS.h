#ifndef _RESTR_S2SEQUALS
#define _RESTR_S2SEQUALS
#include "objects.h"
#include "BasicRestriction.h"

class RestrS2SEQUALS:BasicRestriction
{
public:
	RestrS2SEQUALS(Segment *S1, Segment *S2)
	{
		_S1 = S1;
		_S2 = S2;
	};
	virtual ~RestrS2SEQUALS(){ }
	virtual RestrictType get_type()const{return RT_S2SEQUALS;};
	virtual double violation()const { return _S1->getLength() - _S2->getLength(); }
private:
	Segment *_S1;
	Segment *_S2;
};

#endif
