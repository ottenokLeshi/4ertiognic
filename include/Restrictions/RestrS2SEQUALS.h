#ifndef _RESTR_S2SEQUALS
#define _RESTR_S2SEQUALS
#include "objects.h"
#include "BasicRestriction.h"

class RestrS2SEQUALS:public BasicRestriction
{
public:
	RestrS2SEQUALS(Segment *S1, Segment *S2)
	{
		_S1 = S1;
		_S2 = S2;
	};
	Segment* getS1() {
		return _S1;
	}
	Segment* getS2() {
		return _S2;
	}
	virtual ~RestrS2SEQUALS(){ }
	virtual RestrictType get_type()const{return RT_S2SEQUALS;};
	virtual double violation()const { return *(_S1->getLength()) - *(_S2->getLength()); }
	virtual double diff(size_t par) { return 0; }
private:
	Segment *_S1;
	Segment *_S2;
};

#endif
