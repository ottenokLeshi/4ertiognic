#ifndef _RESTR_S2SANGLE
#define _RESTR_S2SANGLE
#include "objects.h"
#include "BasicRestriction.h"
using namespace std;

class RestrS2SANGLE: public BasicRestriction{
private:
	Segment *_S1;
	Segment *_S2;
	double *_angle;


public:
	RestrS2SANGLE(Segment *S1, Segment *S2, double *angle)
	{
		_S1 = S1;
		_S2 = S2;
		_angle = angle;
	};


	virtual ~RestrS2SANGLE(){ }
	virtual RestrictType get_type() const {return RT_S2SANGLE;};
	virtual double violation() const {return _S1->Angle(_S2) - *_angle; }

	 Array<double*> getFixP() {
		Array<double*> F_P;
		if (_S1->isFixed()) {
			F_P.push_back( _S1->getP1()->x());
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
};

#endif
