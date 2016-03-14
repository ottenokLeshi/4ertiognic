#ifndef _CORE_H
#define _CORE_H
#include "objects.h"
#include "lList.h"
#include "Array.h"
#include "Equation.h"
List<GraphPrimitive*> objects;

class Core{
public:
	Core();
	void addPoint(double x, double y);
	void addSegment(double x1, double y1,double x2, double y2);
	void addCircle(double x, double y,double r);

	

	void addPrimitive(int type, const Array<double> &params){
		
	}

	List<GraphPrimitive*>* selectByRect(double x1,double y1,double x2,double y2);
private:

    
};

#endif
