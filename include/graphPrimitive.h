#ifndef _GRAPHPRIMITIVE_H
#define _GRAPHPRIMITIVE_H

#include <cmath>

class GraphPrimitive {
	bool _isFixed;
	int _id;
	static int static_id;
public:
	static int next_object_id() {
		++static_id;
		return static_id;
	}
	GraphPrimitive() { 
		_isFixed = 0;
		_id = GraphPrimitive::next_object_id();
	}
	bool isFixed() const { return _isFixed; }
	void fix(bool f) { _isFixed = f; }
	int showId() { return _id; }
};

int GraphPrimitive::static_id = 0;

#endif _GRAPHPRIMITIVE_H