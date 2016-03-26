#ifndef _RESTR_S2SORTHO_H
#define _RESTR_S2SORTHO_H

#include "BasicRestriction.h"

class ResrtS2SORTHO : BasicRestriction {
	Segment *_S1, *_S2;
public:
	ResrtS2SORTHO(Segment *S1, Segment *S2) :_S1(S1), _S2(S2) {}

	~ResrtS2SORTHO() {}

	RestrictType get_type() const { return RT_S2SORTHO; };
	double violation()const {
		return  (1.5707963267949 - _S1->Angle(_S2)); //1.5707963267949 - 90 in radian
	};
};
#endif