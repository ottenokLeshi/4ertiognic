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

	double FixL1;
	double FixL2;
	bool _isFixLenS1;
	bool _isFixLenS2;
public:
	RestrS2SANGLE(Segment *S1, Segment *S2, double *angle)
	{
		_S1 = S1;
		_S2 = S2;
		_angle = angle;
	};

	void fixLengthS1(bool F) { _isFixLenS1 = F; FixL1 = *_S1->getLength();	}
	void fixLengthS2(bool F) { _isFixLenS2 = F; FixL2 = *_S2->getLength(); }


	virtual ~RestrS2SANGLE(){ }
	virtual RestrictType get_type() const {return RT_S2SANGLE;};
	virtual double violation() const { if (_isFixLenS1) _S1->; return _S1->Angle(_S2) - *_angle; }

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
