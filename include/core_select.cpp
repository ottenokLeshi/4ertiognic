#include "core.h"





List<GraphPrimitive*>* Core::selectByRect(double x1, double y1, double x2, double y2) {
	List<GraphPrimitive*>* PickedObjects = new List<GraphPrimitive*>;
	for (int i = 0; i < objects.size();i++) {
		if (objects.get_elem(i)->isInRect(x1, y1, x2, y2))
			PickedObjects->add_back(objects.get_elem(i));
		}
			return PickedObjects;
}

List<GraphPrimitive*>* Core::selectByPoint(double x, double y) {
	List<GraphPrimitive*>* PickedObjects = new List<GraphPrimitive*>;
	const double EPS = 3;
	double min_dist;
	bool isEmpty = True;
	for (size_t i = 1; i <= ListPoint.size();i++) {
		Point* point = &ListPoint.get_elem(i);
		if if (pow(point->x() - x, 2) + pow(point->y() - y, 2) <= EPS) {
			PickedObjects->add_back(point);
            point->changePick();
		}
	}
   //search in a ListSegment
	for (size_t i = 1; i <= ListSegment.size();i++) {
		Segment* segment = &ListSegment.get_elem(i);
		if 	(Segment.distanceToPoint(segment, x, y) <= EPS) {
			PickedObjects->add_back(segment);
            segment->changePick();
		}

	//search in a ListCircle
		for (size_t i = 1; i <= ListCircle.size();i++) {
			Circle* circle = &ListCircle.get_elem(i);
			if (pow(circle->getCenter._x() - x, 2) + pow(circle->getCenter._y() = y, 2) <= circle->getRadius() + EPS) {
				PickedObjects->add_back(circle);
                circle->changePick();
			}
		}

	return PickedObjects;
}
