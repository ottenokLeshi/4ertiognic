#include "../include/core.h"

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
			newseg->changeSegment(&seg->point1(),&seg->point2());
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