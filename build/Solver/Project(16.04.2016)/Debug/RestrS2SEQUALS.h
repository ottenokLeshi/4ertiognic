#ifndef _RESTR_S2SEQUALS
#define _RESTR_S2SEQUALS
#include "objects.h"
#include "BasicRestriction.h"

class RestrS2SEQUALS:public BasicRestriction
{
private:
	Segment *_S1;
	Segment *_S2;

public:
	RestrS2SEQUALS(Segment *S1, Segment *S2)
	{
		_S1 = S1;
		_S2 = S2;
	};



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

	virtual ~RestrS2SEQUALS(){ }
	virtual RestrictType get_type()const{return RT_S2SEQUALS;};
	virtual double violation()const { return _S1->getLength() - _S2->getLength(); }

};

#endif
