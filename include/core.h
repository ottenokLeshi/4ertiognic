#ifndef _CORE_H
#define _CORE_H
#include "objects.h"
#include "Array.h"
#include "primitive_type.h"
#include "../include/List.h"
#include "../include/restrict_types.h"
#include "../include/BasicRestriction.h"
#include "../include/RestrP2PDIST.h"
#include "../include/RestrP2SDIST.h"
#include "../include/RestrP2SDISTEX.h"
#include "../include/RestrS2SANGLE.h"
#include "../include/RestrS2SEQUALS.h"
#include "../include/RestrS2SPARAL.h"
#include "../include/ResrtS2SORTHO.h"

class Core{
public:
	List<GraphPrimitive*> objects;
	List<BasicRestriction*> restrictions;
	Core(){};
	void addPrimitive(int type, const Array<double> &params) {}; // need to check are the parameters valid
	List<unsigned>* Core::selectByRect(double x1, double y1, double x2, double y2);
	unsigned Core::selectByPoint(Point p);
	void addObject(Array<double> parametrs, Primitive_Type type);
	bool addRestriction(List<unsigned>* id, double* parametr, RestrictType type);
};

#endif
