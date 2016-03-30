#ifndef _CORE_H
#define _CORE_H
#include "objects.h"
#include "Array.h"
#include "primitive_type.h"
#include "../include/List.h"

class Core{
public:
	List<GraphPrimitive*> objects;

	Core(){};
	void addPrimitive(int type, const Array<double> &params) {}; // need to check are the parameters valid
	List<unsigned>* Core::selectByRect(double x1, double y1, double x2, double y2);
	unsigned Core::selectByPoint(Point p);
};

#endif
