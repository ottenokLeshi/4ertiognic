#ifndef _CIRCLE_H
#define _CIRCLE_H
#include "Point.h"
#include "Equation.h"

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
};


#endif