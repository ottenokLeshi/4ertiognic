#ifndef _CORE_H
#define _CORE_H
#include "../include/Primitives/objects.h"
#include "../include/Containers/MArray.h"
#include "../include/Primitives/primitive_type.h"
#include "../include/Containers/List.h"
#include "../include/Restrictions/restrict_types.h"
#include "../include/Restrictions/BasicRestriction.h"
#include "../include/Restrictions/RestrP2PDIST.h"
#include "../include/Restrictions/RestrP2SDIST.h"
#include "../include/Restrictions/RestrP2SDISTEX.h"
#include "../include/Restrictions/RestrS2SANGLE.h"
#include "../include/Restrictions/RestrS2SEQUALS.h"
#include "../include/Restrictions/RestrS2SPARAL.h"
#include "../include/Restrictions/ResrtS2SORTHO.h"
#include "../include/Algorythms/HJSolver.h"


class Core {


	List<GraphPrimitive*> backupObjects;
public:
    List<GraphPrimitive*> objects;
    List<BasicRestriction*> restrictions;
	Array<double*> params;
	Core() {}
	~Core() {}

	List<unsigned>* selectByRect(double x1, double y1, double x2, double y2);
	unsigned selectByPoint(Point p);
	void addObject(const Array<double> &parametrs, Primitive_Type type);
	bool addRestriction(List<unsigned>* id, double* parametr, RestrictType type);
	void addObjectID(GraphPrimitive* obj) {
		objects.push_back(obj);
	}
	void backupState();
	GraphPrimitive* searchID(int index) {
		List<GraphPrimitive*>::Marker mar(objects);
		for (size_t i = 0; i<objects.sizeList(); i++) {
			if (mar.get_current()->showId() == index) return mar.get_current();
			mar.move_next();
		}
	}
	BasicRestriction* searchIDRestr(int index) {
		List<BasicRestriction*>::Marker mar(restrictions);
		for (size_t i = 0; i < restrictions.sizeList(); i++) {
			if (mar.get_current()->showId() == index) return mar.get_current();
			mar.move_next();
		}
	}
	unsigned sizeListObj() { return objects.sizeList(); }
	unsigned sizeListRestr() { return restrictions.sizeList(); }
	unsigned sizeListBackUpObj() { return backupObjects.sizeList(); }
   Array < Array<double> >* getInfoObj();

};

#endif
