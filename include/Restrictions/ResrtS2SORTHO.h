#ifndef _RESTR_S2SORTHO_H
#define _RESTR_S2SORTHO_H

#include "BasicRestriction.h"

class RestrS2SORTHO : public BasicRestriction {
	Segment *_S1, *_S2;
public:
	RestrS2SORTHO(Segment *S1, Segment *S2) :_S1(S1), _S2(S2) {}

	~RestrS2SORTHO() {}

	RestrictType get_type() const { return RT_S2SORTHO; };
	double violation()const {
		return  (1.5707963267949 - _S1->Angle(_S2)); //1.5707963267949 - 90 in radian
	}
	virtual double diff(size_t par) {
		double diff(size_t par) {
			double _p1x, _p2x, _p3x, _p4x, _p1y, _p2y, _p3y, _p4y;
			_p1x = _S1->getP1()->getX(), _p2x = _S1->getP2()->getX(), _p3x = _S2->getP1()->getX(), _p4x = _S2->getP2()->getX(),
				_p1y = _S1->getP1()->getY(), _p2y = _S1->getP2()->getY(), _p3y = _S2->getP1()->getY(), _p4y = _S2->getP2()->getY();

			double skalyar = (_p1x - _p2x)*(_p3x - _p4x) + (_p1y - _p2y)*(_p3y - _p4y);
			double arccos = (-1) / sqrt(1 - pow(_S1->cosAngle(_S2), 2));
			switch (par) {
			case 1: // parametr _p1x
				return (skalyar*(_p1x - _p2x) / (_S2->getLength()*pow(_S1->getLength(), 3)) - (_p3x - _p4x) / (_S1->getLength()*_S2->getLength()))*arccos;
				break;
			case 2: // parametr _p2x
				return (-skalyar*(_p1x - _p2x) / (_S2->getLength()*pow(_S1->getLength(), 3)) + (_p3x - _p4x) / (_S1->getLength()*_S2->getLength()))*arccos;
				break;
			case 3: // parametr _p3x
				return (skalyar*(_p3x - _p4x) / (_S1->getLength()*pow(_S2->getLength(), 3)) - (_p1x - _p2x) / (_S1->getLength()*_S2->getLength()))*arccos;
				break;
			case 4: // parametr _p4x
				return (-skalyar*(_p3x - _p4x) / (_S1->getLength()*pow(_S2->getLength(), 3)) + (_p1x - _p2x) / (_S1->getLength()*_S2->getLength()))*arccos;
				break;
			case 5: // parametr _p1y
				return (skalyar*(_p1y - _p2y) / (_S2->getLength()*pow(_S1->getLength(), 3)) - (_p3y - _p4y) / (_S1->getLength()*_S2->getLength()))*arccos;
				break;
			case 6: // parametr _p2y
				return (-skalyar*(_p1y - _p2y) / (_S2->getLength()*pow(_S1->getLength(), 3)) + (_p3y - _p4y) / (_S1->getLength()*_S2->getLength()))*arccos;
				break;
			case 7: // parametr _p3y
				return (skalyar*(_p3y - _p4y) / (_S1->getLength()*pow(_S2->getLength(), 3)) - (_p1y - _p2y) / (_S1->getLength()*_S2->getLength()))*arccos;
				break;
			case 8: // parametr _p4y
				return (-skalyar*(_p3y - _p4y) / (_S1->getLength()*pow(_S2->getLength(), 3)) + (_p1y - _p2y) / (_S1->getLength()*_S2->getLength()))*arccos;
				break;
			case 9: // _angle
				return 1;
				break;
			}
		}

	double getAngl() const {
		return  _S1->Angle(_S2);
	}
};
#endif