#ifndef _RESTR_P2PDIST_H
#define _RESTR_P2PDIST_H
#include "objects.h"
#include "BasicRestriction.h"
#include "Solver.h"
class RestrP2PDIST:public BasicRestriction
{
private:
	Point *_A;
	Point *_B;
	double *_dist;

public:
	RestrP2PDIST() { }
	RestrP2PDIST(Point *A, Point *B, double *dist){
		_A = A;
		_B = B;
		_dist = dist;
	};
	virtual ~RestrP2PDIST() {}
	virtual RestrictType get_type() const { return RT_P2PDIST; };
        virtual double violation() const {
                return *_dist - sqrt((_A->getX() - _B->getX())*(_A->getX() - _B->getX()) + (_A->getY() - _B->getY())*(_A->getY() - _B->getY()));
        }

		virtual Array<double*> getFixP() {
			Array<double*> F_P;
			if (_A->isFixed()) {
				F_P.push_back(_A->x());
				F_P.push_back(_A->y());
			}
			if (_B->isFixed()) {
				F_P.push_back(_B->x());
				F_P.push_back(_B->y());
			}
			return F_P;
		}
};

#endif
