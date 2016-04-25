#ifndef _RESTR_S2SORTHO_H
#define _RESTR_S2SORTHO_H

#include "BasicRestriction.h"

class RestrS2SORTHO : public BasicRestriction {
	Segment *_S1, *_S2;
public:
	RestrS2SORTHO(Segment *S1, Segment *S2) :_S1(S1), _S2(S2){}


	Array<double*> getFixP() {
		Array<double*> F_P;
		if (_S1->isFixed()) {
			F_P.push_back(_S1->getP1()->x());
			F_P.push_back(_S1->getP1()->y());
			F_P.push_back(_S1->getP2()->x());
			F_P.push_back(_S1->getP2()->y());
		}
		if (_S2->isFixed()) {
			F_P.push_back(_S2->getP1()->x());
			F_P.push_back(_S2->getP1()->y());
			F_P.push_back(_S2->getP2()->x());
			F_P.push_back(_S2->getP2()->y());
		}
		return F_P;
	}

	~RestrS2SORTHO() {}

	RestrictType get_type() const { return RT_S2SORTHO; };
	double violation()const {
		return  (1.5707963267949 - _S1->Angle(_S2)); //1.5707963267949 - 90 in radian
	};
};
#endif