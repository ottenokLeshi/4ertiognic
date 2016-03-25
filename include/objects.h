#ifndef _OBJECTS_H
#define _OBJECTS_H
#include "graphPrimitive.h"

const double eps = 1e-6;

class Point : public GraphPrimitive {
	double _x;
	double _y;
public:
	Point()
		:_x(0), _y(0) {}
	Point(double x, double y)
		: _x(x), _y(y) {}

	double getX() const { return _x; }
	double getY() const { return _y; }
	
	void setX(double x) { _x = x; }
	void setY(double y) { _y = y; }

	void changeCoord(double x, double y) {
		if (!isFixed()) {
			_x = x;
			_y = y;
		}					// add exceptions in case point is fixed 
	}

	 double dist_points(Point A,Point B) const {
		double distance = sqrt((A.getX() - B.getX())*(A.getX() - B.getX()) + (A.getY() - B.getY())*(A.getY() - B.getY()));
		return distance;

	}

	virtual Primitive_Type object_type()
	{
		return IsPoint;
	}

	virtual bool isInRect(double x1, double y1, double x2, double y2) {
		if ((x1 <= _x) && (_x <= x2) && (y1 <= _y) && (_y <= y2))
			return true;
		else return false;
	}

};


class Segment :public GraphPrimitive {
	Point *_t1,*_t2;
	double _length;
	double _A, _B, _C;
public:
	Segment()
		: _t1(0), _t2(0), _A(0), _B(0), _C(0) {} 

	Segment(Point *t1, Point *t2) {
		_t1 = t1;
		_t2 = t2;
		_length = sqrt((t1->getX() - t2->getX())*(t1->getX() - t1->getX()) + (t1->getY() - t2->getY())*(t1->getY() - t2->getY()));
		_A = t1->getY() - t2->getY();
		_B = t2->getX() - t1->getX();
		_C = t1->getX()*t2->getY() - t2->getX()*t1->getY();
		if (_A < 0) {
			_A *= -1;
			_B *= -1;
			_C *= -1;
		}
	}

	
	double getLength() { return _length; }

	double x1() { return _t1->getX(); }
	double y1() { return _t1->getY(); }
	double x2() { return _t2->getX(); }
	double y2() { return _t2->getY(); }

	double A() { return _A; }
	double B() { return _B; }
	double C() { return _C; }

	Point point1() { return *_t1; }
	Point point2() { return *_t2; }

	virtual Primitive_Type object_type()
	{
		return IsSegment;  
	}

	virtual bool isInRect(double x1, double y1, double x2, double y2) {
		if (((x1 <= _t1->getX()) && (_t1->getX() <= x2) && (y1 <= _t1->getY()) && (_t1->getY() <= y2)) || ((x1 <= _t2->getX()) && (_t2->getX() <= x2) && (y1 <= _t2->getY()) && (_t2->getY() <= y2)))
			return true;
		else return false;
	}
};

double Angle(Segment &S1, Segment &S2) {
	double x1 = S1.x2() - S1.x1();
	double y1 = S1.y2() - S1.y1();
	double x2 = S2.x2() - S2.x1();
	double y2 = S2.y2() - S2.y1();
	double _angle = ((x1*x2 + y1*y2) / (sqrt((double)x1*x1 + y1*y1)*sqrt((double)x2*x2 + y2*y2)));
	if (_angle < -1) _angle = -1;
	else if (_angle > 1) _angle = 1;
	return acos(_angle);
}

bool point_in_segment(Segment s, Point p) { //checks if the point belongs to segment
	if ((dist_points(s.point1(), p) + dist_points(s.point2(), p) - dist_points(s.point1(), s.point2())) < eps)  return 1;
	return 0;
}

bool segments_intersection(Segment S1, Segment S2) {
	double det = S1.A() * S2.B() - S2.A() * S1.B(); //Cramer's rule
	if (det > eps) {
		double det1 = -S1.C() * S2.B() + S2.C() * S1.B(); // "-" because we need to reduce the equation to the next form : a11*x1 + a12*x2 = b
		double det2 = -S1.A() * S2.C() + S2.A() * S1.C(); // so now we have something like A*x + B*y = -C
		double x = det1 / det;
		double y = det2 / det; //so I just find the point of intersection of two lines and check, if the point belongs to both segments
		Point P(x, y);
		return (point_in_segment(S1, P) && point_in_segment(S2, P));
	}
	else return 0;
}

class Circle : public GraphPrimitive {
	Point *_center;
	double _radius;
	//Equation _equation; // x^2 + y^2 + Ax + By + C = 0

public:
	Circle() : 
		_center(0), _radius(0) {};
<<<<<<< HEAD
	Circle(Point *center, double radius) 
		:  _center(center), _radius(radius) {}
	
=======
	Circle(double x, double y, double radius){
		try {
			const char* e = "Negative raduis!";
			if (radius < 0)
				throw e;
			_radius = radius;
			_center->setX(x);
			_center->setY(y);
		}
		catch (const char* e) {}
	};
>>>>>>> 2fa79d41520489d7decda89d5a6f7c159722b49a
	Point getCenter() { return *_center; };
	double getRadius() { return _radius; };
	
	double distanceToPoint(double x, double y) { //distance to circle's border, not center
		return abs(sqrt(pow(_center->getX() - x, 2) + pow(_center->getY() - y, 2)) - _radius);
	}
	
	Primitive_Type object_type()
	{
		return IsCircle;
	}
	bool isInRect(double x1, double y1, double x2, double y2) {
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
