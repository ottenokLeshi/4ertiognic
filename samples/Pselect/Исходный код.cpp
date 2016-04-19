#include <iostream>
#include "MArray.h"
#include "GraphPrimitive.h"
#include "BasicRestriction.h"


class Point : public GraphPrimitive {
	double *_x;
	double *_y;
public:
	Point()
		:_x(0), _y(0) {}
	Point(double *x, double *y)
		: _x(x), _y(y) {}
	virtual ~Point() {}

	double getX() const { return *_x; }
	double getY() const { return *_y; }

	void setX(double x) { *_x = x; }
	void setY(double y) { *_y = y; }

	Point& operator=(Point &P_) {
		*_x = P_.getX();
		*_y = P_.getY();
		return *this;
	}
	void changePoint(double x, double y) {
		if (!isFixed()) {
			*_x = x;
			*_y = y;
		}					// add exceptions in case point is fixed 
	}

	virtual double distanceToPoint(double x, double y)const {
		return sqrt((*_x - x)*(*_x - x) + (*_y - y)*(*_y - y));
	}

	virtual Primitive_Type object_type()
	{
		return IsPoint;
	}

	virtual bool isInRect(double x1, double y1, double x2, double y2) const {
		if ((x1 <= *_x) && (*_x <= x2) && (y1 <= *_y) && (*_y <= y2))
			return true;
		else return false;
	}

};

class RestrP2PDIST:public BasicRestriction
{
public:
	RestrP2PDIST(Point *A, Point *B, double *dist)
	{
		_A = A;
		_B = B;
		_dist = dist;
	};
	virtual ~RestrP2PDIST() {}
	virtual RestrictType get_type() const { return RT_P2PDIST; };
        virtual double violation() const {
                return *_dist - sqrt((_A->getX() - _B->getX())*(_A->getX() - _B->getX()) + (_A->getY() - _B->getY())*(_A->getY() - _B->getY()));
        }
private:
	Point *_A;
	Point *_B;
	double *_dist;
};

class functi{
	Array<BasicRestriction*> _restrictions;
	Array<double*> _pparams;
public:
	functi(const Array<double*> &pparams):_pparams(pparams){};
	void addRestriction(BasicRestriction*r){_restrictions.push_back(r);};

	double operator()(const Array<double> &x){
		// Set parameters values
		for (size_t k = 0; k< x.size();++k)
			*_pparams[k] = x[k];
		// Calculate total violation
		double totalViol = 0;
		for (size_t k = 0; k< _restrictions.size();++k)
			totalViol += _restrictions[k]->violation();
		return totalViol;
	}
};

class solver{

public:
	solver(functi *f,const Array<double>&x0);
	void solve();
	void getSolution(Array<double>&sol);

};
int GraphPrimitive::static_id = 0;
int main(){
	double params[4];

	Point p1(&params[0],&params[1]),p2(&params[2],&params[3]);
	double distance = 2;
	RestrP2PDIST r1(&p1,&p2,&distance);
	std::cout << r1.violation() << std::endl;
	Array<double*> pparam;
	pparam.push_back(&params[0]);
	pparam.push_back(&params[1]);
	pparam.push_back(&params[2]);
	pparam.push_back(&params[3]);
	
	functi f1(pparam);
	f1.addRestriction(&r1);
	Array<double> newpara;
	newpara.push_back(1);
	newpara.push_back(2);
	newpara.push_back(3);
	newpara.push_back(4);
	
	std::cout << f1(newpara)<< std::endl;



	return 0;
}