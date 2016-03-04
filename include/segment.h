#ifndef _SEGMENT_H
#define _SEGMENT_H
#include "math.h"
#include "Point.h"


class Segment :public Point {
	bool _isFixed;
	Point _t1, _t2;
	double _length;
public:
	Segment ()
		: _t1(0,0), _t2(0,0){} //конструктор по умолчанию !ошибка!

	Segment(double x1, double y1, double x2, double y2)
	: _t1(x1,y1), _t2(x2,y2) {
		_length = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	}
	double length() { return _length; }
	double dote1_x() { return Point::x(); }

};


#endif