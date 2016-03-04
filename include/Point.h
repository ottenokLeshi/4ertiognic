#ifndef _POINT_H
#define _POINT_H
#include "graphPrimitive.h"
#include "math.h"


class Point : public GraphPrimitive {
	double _x;
	double _y;
public:
	Point() 
		:_x(0), _y(0) {}
	Point (double x,double y)
		: _x(x), _y(y){}

	double getX() const { return _x; }
	double getY() const { return _y; }

	void changeCoord(double x, double y) {
		if (!_isFixed) {
			_x = x;
			_y = y;
		}					//дописать обработчик ошибок в случае зафиксированной точки
	}

	double dist_points(point A, point B) const {
		double distance = sqrt((A.x() - B.x()) ^ 2 + (A.y() - B.y()) ^ 2);
		return distance;

	}
	
};
#endif
