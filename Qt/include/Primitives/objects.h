   #ifndef _OBJECTS_H
#define _OBJECTS_H
#include "graphPrimitive.h"
#include <iostream>
using namespace std;

const double eps = 1e-6;

class Point : public GraphPrimitive {
	double *_x;
	double *_y;
public:
	Point() :_x(new double), _y(new double) {
		(*_x) = 0;
		(*_y) = 0;
	}
	Point(double x, double y) :_x(new double), _y(new double) {
		(*_x) = x;
		(*_y) = y;
	}
	Point (double *x, double *y): _x(x), _y(y){}
	virtual ~Point() {}

	double getX() const { return *_x; }
	double getY() const { return *_y; }

	double *x() { return _x; }
	double *y() { return _y; }

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
		}				// add exceptions in case point is fixed 
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


class Segment :public GraphPrimitive {
	Point *_t1, *_t2;
	double *_length;
	double _A, _B, _C;
public:
	// friend ostream& operator<<(ostream& ost, Segment &S);
	Segment() : _t1(new Point), _t2(new Point), _length(new double) {
		_refreshCoeff();
		_refreshLength();
	}

	Segment(Point *t1, Point *t2) : _length(new double) {
		_t1 = t1;
		_t2 = t2;
		_refreshCoeff();
		_refreshLength();
		if (_A < 0) {
			_A *= -1;
			_B *= -1;
			_C *= -1;
		}
	}

	virtual ~Segment() {}


	double *getLength() { 
		_refreshLength();
		return _length; 
	}

	double x1() { return _t1->getX(); }
	double y1() { return _t1->getY(); }
	double x2() { return _t2->getX(); }
	double y2() { return _t2->getY(); }

	double A() { return _A; }
	double B() { return _B; }
	double C() { return _C; }

	Point *getP1() { return _t1; }
	Point *getP2() { return _t2; }

	Segment &operator= (Segment &A) {
        if (_t2 == NULL) _t2 = new Point;
        if (_t1 == NULL) _t1 = new Point;
		(*_t1) = (*A._t1);
		(*_t2) = (*A._t2);
		_length = A.getLength();
		_A = A.A();
		_B = A.B();
		_C = A.C();
		return *this;
	}

	virtual Primitive_Type object_type()
	{
		return IsSegment;
	}

	virtual bool isInRect(double x1, double y1, double x2, double y2)const {
		if (((x1 <= _t1->getX()) && (_t1->getX() <= x2) && (y1 <= _t1->getY()) && (_t1->getY() <= y2)) || ((x1 <= _t2->getX()) && (_t2->getX() <= x2) && (y1 <= _t2->getY()) && (_t2->getY() <= y2)))
			return true;
		else return false;
	}

	void changeSegment(Point *p1, Point *p2) {
		if (!isFixed()) {
			_t1 = p1;
			_t2 = p2;
		}
		_refreshLength();
		_refreshCoeff();
	}

	double Angle(Segment *S2) {
		double x1 = _t2->getX() - _t1->getX();
		double y1 = _t2->getY() - _t1->getY();
		double x2 = S2->x2() - S2->x1();
		double y2 = S2->y2() - S2->y1();
		double _angle = ((x1*x2 + y1*y2) / (sqrt((double)x1*x1 + y1*y1)*sqrt((double)x2*x2 + y2*y2)));
		if (_angle < -1) _angle = -1;
		else if (_angle > 1) _angle = 1;
		return acos(_angle);
	}

	double cosAngle(Segment *S2) {
		double x1 = _t2->getX() - _t1->getX();
		double y1 = _t2->getY() - _t1->getY();
		double x2 = S2->x2() - S2->x1();
		double y2 = S2->y2() - S2->y1();
		double _angle = ((x1*x2 + y1*y2) / (sqrt((double)x1*x1 + y1*y1)*sqrt((double)x2*x2 + y2*y2)));
		if (_angle < -1) _angle = -1;
		else if (_angle > 1) _angle = 1;
		return _angle;
	}


	bool point_in_segment(Point *p) { //checks if the point belongs to segment
		if (_t1->distanceToPoint(p->getX(), p->getY()) + _t2->distanceToPoint(p->getX(), p->getY()) - _t1->distanceToPoint(_t2->getX(), _t2->getY()) < eps)  return 1;
		return 0;
	}

	virtual double distanceToPoint(double xt, double yt) const {
		double x1 = _t1->getX(), x2 = _t2->getX(), y1 = _t1->getY(), y2 = _t2->getY();
		double vec1x = x1 - xt, vec1y = y1 - yt, vec2x = x2 - xt, vec2y = y2 - yt, segx = x1 - x2, segy = x2 - y2;
		if ((vec1x*segx + vec1y*segy)*(vec2x*segx + vec2y*segy) < 0) {
			if (x1 == x2) {
				double k = (x1 - x2) / (y1 - y2), b = x2 - k*y2;
				return abs((k*yt - xt + b) / sqrt(k*k + 1));
			}
			double k = (y1 - y2) / (x1 - x2), b = y2 - k*x2;
			return abs((k*xt - yt + b) / sqrt(k*k + 1));
		}
		else {
			if (sqrt(vec1x*vec1x + vec1y*vec1y) < sqrt(vec2x*vec2x + vec2y*vec2y))
				return sqrt(vec1x*vec1x + vec1y*vec1y);
			else
				return sqrt(vec2x*vec2x + vec2y*vec2y);
		}
	}


	bool segments_intersection(Segment *S2) {
		double det = _A * S2->B() - S2->A() * _B; //Cramer's rule
		if (det > eps) {
			double det1 = -_C * S2->B() + S2->C() * _B; // "-" because we need to reduce the equation to the next form : a11*x1 + a12*x2 = b
			double det2 = -_A * S2->C() + S2->A() * _C; // so now we have something like A*x + B*y = -C
			double x = det1 / det;
			double y = det2 / det; //so I just find the point of intersection of two lines and check, if the point belongs to both segments
			Point P(x, y);
			//Segment S1(&_t1, &_t2);
			return (point_in_segment(&P) && S2->point_in_segment(&P));
		}
		else return 0;
	}

	void _refreshLength() {
		double x = (_t1->getX() - _t2->getX());
		double y = (_t1->getY() - _t2->getY());
		(*_length) = sqrt(x*x + y*y);
	}
	void _refreshCoeff() {
		_A = _t1->getY() - _t2->getY();
		_B = _t2->getX() - _t1->getX();
		_C = _t1->getX()*_t2->getY() - _t2->getX()*_t1->getY();
	}
};

/*ostream& operator<<(ostream& ost, Segment &S) {
ost << '(' << S.x1() << ',' << S.y1() << ')' << ' ' << '(' << S.x2() << ',' << S.y2() << ')';
return ost;
}
*/
class Circle : public GraphPrimitive {
	Point *_center;
	double _radius;

public:
	Circle() :
		_center(new Point), _radius(0) {};
	Circle(Point *center, double radius)
		: _center(center), _radius(radius) {};
	virtual ~Circle() {}

	Point getCenter() { return *_center; };
	double getRadius() { return _radius; };

	void changeCircle(Point *center, double rad) {
		if (!isFixed()) {
			_center = center;
			_radius = rad;
		}
	}

	virtual double distanceToPoint(double x, double y)const {
		return abs(sqrt(pow(_center->getX() - x, 2) + pow(_center->getY() - y, 2)) - _radius);
	}

	Primitive_Type object_type()
	{
		return IsCircle;
	}
	virtual bool isInRect(double x1, double y1, double x2, double y2)const {
		//search min length from center to points
		double X = _center->getX(), Y = _center->getY();
		double l1 = sqrt((X - x1)*(X - x1) + (Y - y2)*(Y - y2)), l2 = sqrt((X - x1)*(X - x1) + (Y - y1)*(Y - y1));
		double l3 = sqrt((X - x2)*(X - x2) + (Y - y2)*(Y - y2)), l4 = sqrt((X - x1)*(X - x1) + (Y - y1)*(Y - y1));
		if (l1 > l2) l1 = l2;
		if (l3 > l4) l3 = l4;
		if (l1 > l3) l1 = l3;
		if (_radius >= l1)
			return true;
		else return false;
	}
};



#endif
