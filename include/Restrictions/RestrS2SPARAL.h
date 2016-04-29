#ifndef _RESTR_S2SPARAL_H
#define _RESTR_S2SPARAL_H
#include "BasicRestriction.h"


class RestrS2SPARAL : public BasicRestriction {
private:
	Segment *_S1;
	Segment *_S2;

public: 
	RestrS2SPARAL(Segment *S1, Segment *S2)
		:_S1(S1), _S2(S2) {}



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

	virtual ~RestrS2SPARAL() {}
	virtual RestrictType get_type() const { return RT_S2SPARAL; }
	virtual double violation() const {return _S1->Angle(_S2); }
};

#endif