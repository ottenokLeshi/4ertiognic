#include "core.h" 

void Core::addObject(const Array<double> &parametrs, Primitive_Type type) {
	GraphPrimitive* newobj;
	switch (type) {
	case IsPoint: if (parametrs.size() == 2)
		newobj = new Point(parametrs[0], parametrs[1]);
	case IsSegment: if (parametrs.size() == 4) {
		Point *t1 = new Point(parametrs[0], parametrs[1]);
		Point *t2 = new Point(parametrs[2], parametrs[3]);
		objects.push_back(t1);
		objects.push_back(t2);
		newobj = new Segment(t1, t2);
	}
	case IsCircle: if (parametrs.size() == 3) {
		Point *t1 = new Point(parametrs[0], parametrs[1]);
		objects.push_back(t1); // otherwise we won't have access to that point by id
		newobj = new Circle(t1, parametrs[2]);
	}
	}
	objects.push_back(newobj);
	return;
}


bool Core::addRestriction(List<unsigned>* id, double* parametr, RestrictType type, ISolver* F) {
	List<GraphPrimitive*>::Marker myMar1(objects);

	if (*parametr == 0.0) *parametr = 1e-5;
	List<GraphPrimitive*> id_obj;
	BasicRestriction* newrest = 0;
	List<GraphPrimitive*>::Marker mar1(objects);
	List<GraphPrimitive*>::Marker fixedObjectsMarker(fixedObjects);
	for (size_t i = 0; i < objects.sizeList(); i++) {
		List<unsigned>::Marker mar_id(*id);
		for (size_t j = 0; j < id->sizeList(); j++) {
			if (mar1.get_current()->showId() == mar_id.get_current())
				id_obj.push_back(mar1.get_current());
			mar_id.move_next();
		}
		mar1.move_next();
	}
	Array<double *> newParams;
	List<GraphPrimitive*>::Marker mar(id_obj);
	switch (type) {

	case RT_FIX:

		for (size_t i = 0; i < id_obj.sizeList(); i++) {
			auto fixedObject = mar.get_current();
			fixedObject->fix(1);
			fixedObjects.push_back(mar.get_current());

			if (fixedObject->object_type() == IsPoint) {
				auto fixedPoint = dynamic_cast<Point*> (fixedObject);
				for (size_t j = 0; j < params.size(); j++) {
					if (params[j] != fixedPoint->x() && params[j] != fixedPoint->y())
						newParams.union_with(params[j]);
				}
				params = newParams;
			}
			else if (fixedObject->object_type() == IsSegment) {
				auto fixedSegment = dynamic_cast<Segment*> (fixedObject);
				for (size_t j = 0; j < params.size(); j++) {
					if (params[j] != fixedSegment->getP1()->x() && params[j] != fixedSegment->getP1()->y())
						if (params[j] != fixedSegment->getP2()->x() && params[j] != fixedSegment->getP2()->y())
							newParams.union_with(params[j]);
				}
				params = newParams;
			}

			else if (fixedObject->object_type() == IsCircle) {
				auto fixedCircle = dynamic_cast<Circle*> (fixedObject);
				for (size_t j = 0; j < params.size(); j++) {
					if (params[j] != fixedCircle->getCenter().x() && params[j] != fixedCircle->getCenter().y())
						newParams.union_with(params[j]);
				}
				params = newParams;
			}
			mar.move_next();
		}
		return true;
		break;
	case RT_UNFIX:
		for (size_t i = 0; i < id_obj.sizeList(); i++) {
			mar.get_current()->fix(0);
			for (size_t j = 0; j < fixedObjects.sizeList(); j++) {
				if (fixedObjectsMarker.get_current()->showId() == mar.get_current()->showId()) {
					fixedObjects.deleteElem(fixedObjectsMarker);
				}
				fixedObjectsMarker.move_next();
			}
			mar.move_next();
		}
		return true;
		break;
	case RT_P2PDIST:
		if (id_obj.sizeList() == 2) {
			Point *p1 = dynamic_cast<Point*> (mar.get_current());
			mar.move_next();
			Point *p2 = dynamic_cast<Point*> (mar.get_current());
			newrest = new RestrP2PDIST(p1, p2, parametr);
			if (!p1->isFixed()) {
				params.union_with(p1->x());
				params.union_with(p1->y());
			}
			if (!p2->isFixed()) {
				params.union_with(p2->x());
				params.union_with(p2->y());
			}
		}
		break;

	case RT_P2SDIST:
		if (id_obj.sizeList() == 3) {
			List<GraphPrimitive*>::Marker mar(id_obj);
			Point *p1 = dynamic_cast<Point*> (mar.get_current());
			mar.move_next();
			Point *p2 = dynamic_cast<Point*> (mar.get_current());
			mar.move_next();
			Point *p3 = dynamic_cast<Point*> (mar.get_current());
			newrest = new RestrP2SDIST(p1, p2, p3, parametr);
			if (!p1->isFixed()) {
				params.union_with(p1->x());
				params.union_with(p1->y());
			}
			if (!p2->isFixed()) {
				params.union_with(p2->x());
				params.union_with(p2->y());
			}
			if (!p3->isFixed()) {
				params.union_with(p3->x());
				params.union_with(p3->y());
			}
		}
		break;

	case RT_P2SDISTEX:
		if (id_obj.sizeList() == 3) {
			List<GraphPrimitive*>::Marker mar(id_obj);
			Point *p1 = dynamic_cast<Point*> (mar.get_current());
			mar.move_next();
			Point *p2 = dynamic_cast<Point*> (mar.get_current());
			mar.move_next();
			Point *p3 = dynamic_cast<Point*> (mar.get_current());
			newrest = new RestrP2SDISTEX(p1, p2, p3, parametr);
			if (!p1->isFixed()) {
				params.union_with(p1->x());
				params.union_with(p1->y());
			}
			if (!p2->isFixed()) {
				params.union_with(p2->x());
				params.union_with(p2->y());
			}
			if (!p3->isFixed()) {
				params.union_with(p3->x());
				params.union_with(p3->y());
			}
		}
		break;

	case RT_S2SANGLE:
		if (id_obj.sizeList() == 2) {
			List<GraphPrimitive*>::Marker mar(id_obj);
			Segment *p1 = dynamic_cast<Segment*> (mar.get_current());
			mar.move_next();
			Segment *p2 = dynamic_cast<Segment*> (mar.get_current());
			newrest = new RestrS2SANGLE(p1, p2, parametr);
			if (!p1->isFixed()) {
				if (!p1->getP1()->isFixed()) {
					params.union_with(p1->getP1()->x());
					params.union_with(p1->getP1()->y());
				}
				if (!p1->getP2()->isFixed()) {
					params.union_with(p1->getP2()->x());
					params.union_with(p1->getP2()->y());
				}
			}
			if (!p2->isFixed()) {
				if (!p2->getP1()->isFixed()) {
					params.union_with(p2->getP1()->x());
					params.union_with(p2->getP1()->y());
				}
				if (!p2->getP2()->isFixed()) {
					params.union_with(p2->getP2()->x());
					params.union_with(p2->getP2()->y());
				}
			}
		}
		break;

	case RT_S2SEQUALS:
		if (id_obj.sizeList() == 2) {
			List<GraphPrimitive*>::Marker mar(id_obj);
			Segment *p1 = dynamic_cast<Segment*> (mar.get_current());
			mar.move_next();
			Segment *p2 = dynamic_cast<Segment*> (mar.get_current());
			newrest = new RestrS2SEQUALS(p1, p2);
			if (!p1->isFixed()) {
				if (!p1->getP1()->isFixed()) {
					params.union_with(p1->getP1()->x());
					params.union_with(p1->getP1()->y());
				}
				if (!p1->getP2()->isFixed()) {
					params.union_with(p1->getP2()->x());
					params.union_with(p1->getP2()->y());
				}
			}
			if (!p2->isFixed()) {
				if (!p2->getP1()->isFixed()) {
					params.union_with(p2->getP1()->x());
					params.union_with(p2->getP1()->y());
				}
				if (!p2->getP2()->isFixed()) {
					params.union_with(p2->getP2()->x());
					params.union_with(p2->getP2()->y());
				}
			}
		}
		break;

	case RT_S2SPARAL:
		if (id_obj.sizeList() == 2) {
			List<GraphPrimitive*>::Marker mar(id_obj);
			Segment *p1 = dynamic_cast<Segment*> (mar.get_current());
			mar.move_next();
			Segment *p2 = dynamic_cast<Segment*> (mar.get_current());
			newrest = new RestrS2SPARAL(p1, p2);
			if (!p1->isFixed()) {
				if (!p1->getP1()->isFixed()) {
					params.union_with(p1->getP1()->x());
					params.union_with(p1->getP1()->y());
				}
				if (!p1->getP2()->isFixed()) {
					params.union_with(p1->getP2()->x());
					params.union_with(p1->getP2()->y());
				}
			}
			if (!p2->isFixed()) {
				if (!p2->getP1()->isFixed()) {
					params.union_with(p2->getP1()->x());
					params.union_with(p2->getP1()->y());
				}
				if (!p2->getP2()->isFixed()) {
					params.union_with(p2->getP2()->x());
					params.union_with(p2->getP2()->y());
				}
			}
		}
		break;

	case RT_S2SORTHO:
		if (id_obj.sizeList() == 2) {
			List<GraphPrimitive*>::Marker mar(id_obj);
			Segment *p1 = dynamic_cast<Segment*> (mar.get_current());
			mar.move_next();
			Segment *p2 = dynamic_cast<Segment*> (mar.get_current());
			newrest = new RestrS2SORTHO(p1, p2);
			if (!p1->isFixed()) {
				if (!p1->getP1()->isFixed()) {
					params.union_with(p1->getP1()->x());
					params.union_with(p1->getP1()->y());
				}
				if (!p1->getP2()->isFixed()) {
					params.union_with(p1->getP2()->x());
					params.union_with(p1->getP2()->y());
				}
			}
			if (!p2->isFixed()) {
				if (!p2->getP1()->isFixed()) {
					params.union_with(p2->getP1()->x());
					params.union_with(p2->getP1()->y());
				}
				if (!p2->getP2()->isFixed()) {
					params.union_with(p2->getP2()->x());
					params.union_with(p2->getP2()->y());
				}
			}
		}
		break;
	}


	if (!params.size()) return false;

	backupState();
	if (!params.size()) return false;
	MyFunction f1(params);
	f1.addRestr(newrest);
	List<BasicRestriction*>::Marker res_mar(restrictions);
	for (size_t i = 0; i < restrictions.sizeList(); i++) {
		f1.addRestr(res_mar.get_current());
		res_mar.move_next();
	}
	// something has to be done with this
	F->solve(&f1, params);
	restrictions.push_back(newrest);
	return true;
	//toBackupState();
	//return false;
	
}