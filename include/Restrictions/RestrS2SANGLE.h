#ifndef _RESTR_S2SANGLE
#define _RESTR_S2SANGLE
#include "objects.h"
#include "BasicRestriction.h"

class RestrS2SANGLE: public BasicRestriction{
public:
	RestrS2SANGLE(Segment *S1, Segment *S2, double *angle)
	{
		_S1 = S1;
		_S2 = S2;
		_angle = angle;

		_p1x = _S1->getP1()->getX();
		_p2x = _S1->getP2()->getX();
		_p3x = _S2->getP1()->getX();
		_p4x = _S2->getP2()->getX();
		_p1y = _S1->getP1()->getY();
		_p2y = _S1->getP2()->getY();
		_p3y = _S2->getP1()->getY();
		_p4y = _S2->getP2()->getY();

	};
	virtual ~RestrS2SANGLE(){ }
	
	virtual RestrictType get_type()const {
		return RT_S2SANGLE;
	};
	
	virtual double violation() const {
		return *_angle - _S1->Angle(_S2);
	}

	virtual double diff(size_t par) {
		double skalyar = (_p1x - _p2x)*(_p3x - _p4x) + (_p1y - _p2y)*(_p3y - _p4y);
		double arccos = (-1) / sqrt(1 - pow(_S1->cosAngle(_S2), 2));
		double *LS1 = _S1->getLength(), *LS2 = _S2->getLength();
		switch (par) {
		case 1: // parametr _p1x
				return (skalyar*(_p1x - _p2x)/(*LS2*std::pow(*LS1,3)) - (_p3x - _p4x)/(*LS1*(*LS2)))*arccos;
				break;
		case 2: // parametr _p2x
			return (-skalyar*(_p1x - _p2x) / (*LS2*std::pow(*LS1, 3)) + (_p3x - _p4x) / (*LS1*(*LS2)))*arccos;
				break;
		case 3: // parametr _p3x
				return (skalyar*(_p3x - _p4x) / (*LS1*std::pow(*LS2, 3)) - (_p1x - _p2x) / (*LS1*(*LS2)))*arccos;
				break;
		case 4: // parametr _p4x
				return (- skalyar*(_p3x - _p4x) / (*LS1*std::pow(*LS2, 3)) + (_p1x - _p2x) / (*LS1*(*LS2)))*arccos;
				break;
		case 5: // parametr _p1y
				return (skalyar*(_p1y - _p2y) / (*LS2*std::pow(*LS1, 3)) - (_p3y - _p4y) / (*LS1*(*LS2)))*arccos;
				break;
		case 6: // parametr _p2y
				return (- skalyar*(_p1y - _p2y) / (*LS2*std::pow(*LS1, 3)) + (_p3y - _p4y) / (*LS1*(*LS2)))*arccos;
				break;
		case 7: // parametr _p3y
				return (skalyar*(_p3y - _p4y) / (*LS1*std::pow(*LS2, 3)) - (_p1y - _p2y) / (*LS1*(*LS2)))*arccos;
				break;
		case 8: // parametr _p4y
				return (-skalyar*(_p3y - _p4y) / (*LS1*std::pow(*LS2, 3)) + (_p1y - _p2y) / (*LS1*(*LS2)))*arccos;
				break;
		case 9: // _angle
				return 1;
				break;
		}
		return 0;
	}

	


private:
	Segment *_S1;
	Segment *_S2;
	double *_angle;
	double _p1x, _p2x, _p3x, _p4x, _p1y, _p2y, _p3y, _p4y;

};

#endif
