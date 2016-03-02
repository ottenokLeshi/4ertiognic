
#ifndef _POINT_H
#define _POINT_H
#include "graphPrimitive.h"


class Point : public GraphPrimitive {
	bool _isFixed;
	double _x;
	double _y;
public:
	Point() 
		:_x(0), _y(0) {}
		
	Point (double x,double y)
		: _x(x), _y(y){}
	double x() { return _x; }
	double y() { return _y; }

	void change_point(double x, double y) {
		if (!_isFixed) {
			_x = x;
			_y = y;
		}
	}

	
};



#endif
