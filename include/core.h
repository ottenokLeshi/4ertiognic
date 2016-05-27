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
	ISolver* SOLVE;
	List<GraphPrimitive*> objects;
	List<BasicRestriction*> restrictions;
	List<GraphPrimitive*> backupObjects;
	List<GraphPrimitive*> fixedObjects;
	Array<Array<double>>* backupParametrs;
	Array<double*> params;
public:
	Core() { SOLVE = nullptr; }
	~Core() {}
	void getSOLVE(bool _bSolve);
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
		return nullptr;
	}
	BasicRestriction* searchIDRestr(int index) {
		List<BasicRestriction*>::Marker mar(restrictions);
		for (size_t i = 0; i < restrictions.sizeList(); i++) {
			if (mar.get_current()->showId() == index) return mar.get_current();
			mar.move_next();
		}
		return nullptr;
	}
	Array<unsigned> getPicked() {
		Array <unsigned> picked;
		List<GraphPrimitive*>::Marker mar(objects);
		for (size_t i = 0; i < objects.sizeList(); ++i) {
			if (mar.get_current()->isPicked()) {
				picked.push_back(mar.get_current()->showId());
				mar.move_next();
			}
		}
		return picked;
	}
	void ShowFixed() {
		List<GraphPrimitive*>::Marker mar(fixedObjects);
		for (size_t i = 0; i < fixedObjects.sizeList(); ++i) {
			cout << mar.get_current()->showId() << " ";
			mar.move_next();
		}
		cout << endl;
	}

	void ShowRestr() {
		List<BasicRestriction*>::Marker mar(restrictions);
		for (size_t i = 0; i < restrictions.sizeList(); ++i) {
			cout << mar.get_current()->showId() << " ";
			mar.move_next();
		}
		cout << endl;
	}
	Array <unsigned> getObjIDs() {
		Array <unsigned> objIDs;
		List<GraphPrimitive*>::Marker mar(objects);
		for (size_t i = 0; i < objects.sizeList(); ++i) {
			objIDs.push_back(mar.get_current()->showId());
			mar.move_next();
		}
		return objIDs;
	}

	Array <unsigned> getRestrIDs() {
		Array <unsigned> restrIDs;
		List<BasicRestriction*>::Marker mar(restrictions);
		for (size_t i = 0; i < restrictions.sizeList(); ++i) {
			restrIDs.push_back(mar.get_current()->showId());
			mar.move_next();
		}
		return restrIDs;
	}
	unsigned sizeListObj() { return objects.sizeList(); }
	unsigned sizeListRestr() { return restrictions.sizeList(); }
	unsigned sizeListBackUpObj() { return backupObjects.sizeList(); }
	Array <Array<double>>* getInfoObj();
	void toBackupState();
	void clearState();
	void deleteSelected();
	void deleteRestrs(Point object);
};

#endif