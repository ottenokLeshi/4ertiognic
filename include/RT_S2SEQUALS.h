#ifndef _RT_S2SEQUALS
#define _RT_S2SEQUALS
#include "objects.h"
#include "BasicRestriction.h"

class RT_S2SEQUALS:BasicRestriction
{
public:
	RT_S2SEQUALS(Segment *S1, Segment *S2)
	{
		_S1 = S1;
		_S2 = S2;
	};
	~RT_S2SEQUALS(){ }
	RestrictType get_type()const{return RT_S2SEQUALS;};
	double violation()const{return _S1.getLength-_S2.getLength};
private:
	Segment *_S1;
	Segment *_S2;
};

#endif
