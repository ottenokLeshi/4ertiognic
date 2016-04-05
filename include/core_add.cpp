#include "../include/core.h" 

void Core::addObject(Array<double> parametrs, Primitive_Type type) {
	GraphPrimitive* newobj;
	switch (type) {
	case IsPoint: if (parametrs.size() == 2)
		newobj = new Point(parametrs[0], parametrs[1]);
	case IsSegment: if (parametrs.size() == 4) {
		Point *t1 = new Point(parametrs[0], parametrs[1]);
		Point *t2 = new Point(parametrs[2], parametrs[3]);
		newobj = new Segment(t1, t2);
	}
	case IsCircle: if (parametrs.size() == 3) {
		Point *t1 = new Point(parametrs[0], parametrs[1]);
		newobj = new Circle(t1, parametrs[2]);
	}
	}
	objects.push_back(newobj);
	return;
}


bool Core::addRestriction(List<unsigned>* id, double* parametr, RestrictType type) {
	List<GraphPrimitive*> id_obj;
	for (List<GraphPrimitive*>::Marker mar(objects);mar.exist();mar.move_next())
		for (List<unsigned>::Marker mar_id(*id);mar_id.exist();mar.move_next())
			if (mar.get_current()->showId() == mar_id.get_current())
				id_obj.push_back(mar.get_current());
	BasicRestriction* newrest = 0;
	switch (type) {

	case RT_FIX:
		for (List<GraphPrimitive*>::Marker mar(id_obj);mar.exist();mar.move_next())
			mar.get_current()->fix(1);

	case RT_P2PDIST:
		if (id_obj.sizeList() == 2) {
			List<GraphPrimitive*>::Marker mar(id_obj);
			Point *p1 = dynamic_cast<Point*> (mar.get_current());
			mar.move_next();
			Point *p2 = dynamic_cast<Point*> (mar.get_current());
			newrest = new RestrP2PDIST(p1, p2, parametr);
		}

	case RT_P2SDIST:
		if (id_obj.sizeList() == 3) {
			List<GraphPrimitive*>::Marker mar(id_obj);
			Point *p1 = dynamic_cast<Point*> (mar.get_current());
			mar.move_next();
			Point *p2 = dynamic_cast<Point*> (mar.get_current());
			mar.move_next();
			Point *p3 = dynamic_cast<Point*> (mar.get_current());
			newrest = new RestrP2SDIST(p1, p2, p3, parametr);
		}

	case RT_P2SDISTEX:
		if (id_obj.sizeList() == 3) {
			List<GraphPrimitive*>::Marker mar(id_obj);
			Point *p1 = dynamic_cast<Point*> (mar.get_current());
			mar.move_next();
			Point *p2 = dynamic_cast<Point*> (mar.get_current());
			mar.move_next();
			Point *p3 = dynamic_cast<Point*> (mar.get_current());
			newrest = new RestrP2SDISTEX(p1, p2, p3, parametr);
		}

	case RT_S2SANGLE:
		if (id_obj.sizeList() == 2) {
			List<GraphPrimitive*>::Marker mar(id_obj);
			Segment *p1 = dynamic_cast<Segment*> (mar.get_current());
			mar.move_next();
			Segment *p2 = dynamic_cast<Segment*> (mar.get_current());
			newrest = new RestrS2SANGLE(p1, p2, parametr);
		}

	case RT_S2SEQUALS:
		if (id_obj.sizeList() == 2) {
			List<GraphPrimitive*>::Marker mar(id_obj);
			Segment *p1 = dynamic_cast<Segment*> (mar.get_current());
			mar.move_next();
			Segment *p2 = dynamic_cast<Segment*> (mar.get_current());
			newrest = new RestrS2SEQUALS(p1, p2);
		}

	case RT_S2SPARAL:
		if (id_obj.sizeList() == 2) {
			List<GraphPrimitive*>::Marker mar(id_obj);
			Segment *p1 = dynamic_cast<Segment*> (mar.get_current());
			mar.move_next();
			Segment *p2 = dynamic_cast<Segment*> (mar.get_current());
			newrest = new RestrS2SPARAL(p1, p2);
		}

	case RT_S2SORTHO:
		if (id_obj.sizeList() == 2) {
			List<GraphPrimitive*>::Marker mar(id_obj);
			Segment *p1 = dynamic_cast<Segment*> (mar.get_current());
			mar.move_next();
			Segment *p2 = dynamic_cast<Segment*> (mar.get_current());
			newrest = new RestrS2SORTHO(p1, p2);
		}
	}
		// change object and check restrictions
		/*solver()
		...
		*/
		for (List<BasicRestriction*>::Marker mar(restrictions);mar.exist();mar.move_next())
			if (mar.get_current()->violation() != 0) {
				//remove changes
				delete newrest;
				return false;
			}
		//save changes
		restrictions.push_back(newrest);
		return true;
}

int main() {

	return 0;
}