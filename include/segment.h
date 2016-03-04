#ifndef _SEGMENT_H
#define _SEGMENT_H
#include "math.h"
#include "Point.h"


class Segment :public Point {
	Point _t1, _t2;
	double _length;
	//переменная _isFixed не должна здесь находиться
	double A, B, C;
public:
	Segment ()
		: _t1(0,0), _t2(0,0), A(0), B(0), C(0) {} //конструктор по умолчанию !ошибка! -- в чём ошибка? 

	Segment(double x1, double y1, double x2, double y2)
		: _t1(x1,y1), _t2(x2,y2) {
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
	//double dote1_x() { return Point::x(); } зачем эта функция?
	double Angle(Segment &S1, Segment &S2) {
		double _angle = (Point1.getX()*Point2.getX() + Point1.getY()*Point2.getY()) / (sqrt((double)Point1.getX()*Point1.getX() + Point1.getY()*Point1.getY())*sqrt((double)Point2.getX()*Point2.getX() + Point2.getY()*Point2.getY()));
		if (_angle < -1) _angle = -1;
		else if (_angle > 1) _angle = 1;
		return acos(_angle);
	}
};


#endif