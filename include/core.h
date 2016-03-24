#ifndef _CORE_H
#define _CORE_H
#include "objects.h"
#include "lList.h"
#include "Array.h"
#include "Equation.h"
#include "primitive_type.h"
#include "lList.h"
#include "array.h"
#include "objects.h"

List<GraphPrimitive*> objects;

class Core{
public:
	Core();
	void addPrimitive(int type, const Array<double> &params); // need to check are the parameters valid
};

#endif
