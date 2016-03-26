#ifndef _GRAPHPRIMITIVE_H
#define _GRAPHPRIMITIVE_H

#include <cmath>
#include "primitive_type.h"

class GraphPrimitive {
	bool _isPicked;
	bool _isFixed;
	int _id;
	static int static_id;
public:
	static int next_object_id() {
		++static_id;
		return static_id;
	}
	GraphPrimitive() { 
		static_id = 0;
		_isFixed = 0;
		_id = GraphPrimitive::next_object_id();
	}
	bool isFixed() const { return _isFixed; }
	void fix(bool f) { _isFixed = f; }
	int showId() { return _id; }

	bool isPicked() const { return _isPicked; }
	void pick(bool f) { _isPicked = f; }
    void changePick() { _isPicked = !_isPicked;}
    void changePick(bool p) { _isPicked = p;}

	virtual Primitive_Type object_type() = 0;
	virtual bool isInRect(double x1, double y1, double x2, double y2) = 0;

	virtual double distanceToPoint(double x, double y) = 0;
	
};


#endif _GRAPHPRIMITIVE_H
