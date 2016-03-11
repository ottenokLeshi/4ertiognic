#ifndef _OBJECTS_H
#define _OBJECTS_H
#include "graphPrimitive.h"

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

	void changeCoord(double x, double y) {
		if (!isFixed()) {
			_x = x;
			_y = y;
		}					// add exceptions in case point is fixed 
	}

	double dist_points(Point A, Point B) const {
		double distance = sqrt((A.getX() - B.getX()) ^ 2 + (A.getY() - B.getY()) ^ 2);
		return distance;

	}

	virtual Primitive_Type object_type()
	{
		return IsPoint;
	}
};


class Segment :public GraphPrimitive {
	Point _t1, _t2;
	double _length;
	//?????????? _isFixed ?? ?????? ????? ??????????
	double A, B, C;
public:
	Segment()
		: _t1(0, 0), _t2(0, 0), A(0), B(0), C(0) {} //??????????? ?? ????????? !??????! -- ? ??? ??????? 

	Segment(double x1, double y1, double x2, double y2)
		: _t1(x1, y1), _t2(x2, y2) {
		_length = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
		A = y1 - y2;
		B = x2 - x1;
		C = x1*y2 - x2*y1;
		if (A < 0) {
			A *= -1;
			B *= -1;
			C *= -1;
		}
	}

	Segment(Point &Point1, Point &Point2)
		: _t1(Point1.getX(), Point1.getY()), _t2(Point2.getX(), Point2.getY()), _length(dist_points(Point1, Point2)) {
		A = Point1.getY() - Point2.getY();
		B = Point2.getX() - Point1.getX();
		C = Point1.getX()*Point2.getY() - Point2.getX()*Point1.getY();
		if (A < 0) {
			A *= -1;
			B *= -1;
			C *= -1;
		}
	}
	double getLength() { return _length; }
	//double dote1_x() { return Point::x(); } ????? ??? ????????
	double Angle(Segment &S1, Segment &S2) {
		double _angle = (Point1.getX()*Point2.getX() + Point1.getY()*Point2.getY()) / (sqrt((double)Point1.getX()*Point1.getX() + Point1.getY()*Point1.getY())*sqrt((double)Point2.getX()*Point2.getX() + Point2.getY()*Point2.getY()));
		if (_angle < -1) _angle = -1;
		else if (_angle > 1) _angle = 1;
		return acos(_angle);
	}
	double x1() { return _t1.getX(); }
	double y1() { return _t1.getY(); }
	double x2() { return _t2.getX(); }
	double y2() { return _t2.getY(); }


	virtual Primitive_Type object_type()
	{
		return IsSegment;  
	}

};


class Circle : public GraphPrimitive, Equation {
	Point _center;
	double _radius;
	Equation _equation; // x^2 + y^2 + Ax + By + C = 0
public:
	Circle() : _center(0, 0), _radius(0), _equation(3) {};
	Circle(Point center, double radius) : _equation(3) {
		try {
			const char* e = "Negative raduis!";
			if (radius < 0)
				throw e;
			_radius = radius;
			_center = center;

			_equation._a[0] = -_center.getX() / 2;
			_equation._a[1] = -_center.getY() / 2;
			_equation._a[2] = (-4 * pow(_radius, 2) + pow(_equation._a[0], 2) + pow(_equation._a[1], 2)) / 4;
		}
		catch (const char* e) {
			std::cout << e;
		}
	};
	Point getCenter() { return _center; };
	double getRadius() { return _radius; };
	Equation getEquation() { return _equation; };

	class Circle : public Point, Equation {
	Point _center;
	double _radius;
	Equation _equation; // x^2 + y^2 + Ax + By + C = 0
public:
	Circle() : _center(0, 0), _radius(0), _equation(3) {};
	Circle(Point center, double radius) : _equation(3) {
		try {
			const char* e = "Negative raduis!";
			if (radius < 0)
				throw e;
			_radius = radius;
			_center = center;

			_equation._a[0] = -_center.getX() / 2;
			_equation._a[1] = -_center.getY() / 2;
			_equation._a[2] = (-4 * pow(_radius, 2) + pow(_equation._a[0], 2) + pow(_equation._a[1], 2)) / 4;
		}
		catch (const char* e) {
			std::cout << e;
		}
	};
	Point getCenter() { return _center; };
	double getRadius() { return _radius; };
	Equation getEquation() { return _equation; };

	virtual Primitive_Type object_type()
	{
		return IsCircle;
	}
};



#endif
