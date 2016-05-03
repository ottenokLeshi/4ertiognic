#include "core.h"

void Core::backupState() {
	backupObjects.deleteAll();
	List<GraphPrimitive*>::Marker mar(objects);
	Point *newpoint = new Point;
	Segment *newseg = new Segment;
	Circle *newcir = new Circle;
	Point *point = 0;
	Segment *seg = 0;
	Circle *circle = 0;
	for (size_t i = 0;i < objects.sizeList();i++) {
		Primitive_Type type = mar.get_current()->object_type();
		switch (type) {
		case IsPoint:
			point = dynamic_cast<Point*>(*mar);
			newpoint = new Point;
			newpoint->changePoint(point->getX(), point->getY());
			backupObjects.push_back(newpoint);
			break;

		case IsSegment:
			seg = dynamic_cast<Segment*>(*mar);
			newseg = new Segment;
			newseg->changeSegment(seg->getP1(),seg->getP2());
			backupObjects.push_back(newseg);
			break;

		case IsCircle:
			circle = dynamic_cast<Circle*>(*mar);
			newcir = new Circle;
			newcir->changeCircle(&circle->getCenter(),circle->getRadius());
			backupObjects.push_back(newcir);
			break;
		}
		mar.move_next();
	}
}

pair<Array<Primitive_Type>*, Array <Array<double>>*> Core::getInfoObj() {
	Array<Primitive_Type> *objType = new Array<Primitive_Type>;
	Array <Array<double>> *parametrs = new Array <Array<double>>;
	List<GraphPrimitive*>::Marker mar(objects);
	Point * newp = 0; Circle *newc = 0; Segment * news = 0;
	for (size_t i = 0;i < objects.sizeList();i++) {
		Array<double> par;

		switch (mar.get_current()->object_type()) {

		case IsPoint:
			newp = dynamic_cast<Point*>(mar.get_current());
			par.push_back(newp->getX());par.push_back(newp->getY());
			break;

		case IsSegment:
			news = dynamic_cast<Segment*>(mar.get_current());
			par.push_back(news->x1());par.push_back(news->y1());
			par.push_back(news->x2());par.push_back(news->y2());
			break;

		case IsCircle:
			newc = dynamic_cast<Circle*>(mar.get_current());
			Point t = newc->getCenter();
			par.push_back(t.getX());
			par.push_back(t.getY());
			par.push_back(newc->getRadius());
			break;
		}
		objType->push_back(mar.get_current()->object_type());
		parametrs->push_back(par);
		mar.move_next();
	}
	return make_pair(objType, parametrs);
}