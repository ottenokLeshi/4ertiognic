#ifndef _CORE_H
#define _CORE_H
#include "objects.h"
#include "MArray.h"
#include "primitive_type.h"
#include "List.h"
#include "restrict_types.h"
#include "BasicRestriction.h"
#include "RestrP2PDIST.h"
#include "RestrP2SDIST.h"
#include "RestrP2SDISTEX.h"
#include "RestrS2SANGLE.h"
#include "RestrS2SEQUALS.h"
#include "RestrS2SPARAL.h"
#include "ResrtS2SORTHO.h"
#include "ISolver.h"
class Core {
	List<GraphPrimitive*> objects;
	List<BasicRestriction*> restrictions;
	List<GraphPrimitive*> backupObjects;
public:
	Array<double*> params;
	Core() {}
	~Core() {}
	void addPrimitive(int type, const Array<double> &params) {}; // need to check are the parameters valid
	List<unsigned>* selectByRect(double x1, double y1, double x2, double y2);
	unsigned selectByPoint(Point p);
	void addObject(const Array<double> &parametrs, Primitive_Type type);
	bool addRestriction(List<unsigned>* id, double* parametr, RestrictType type, ISolver* F);
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
	Array <Array<double>>* getInfoObj();

};

#endif