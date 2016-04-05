#ifndef _CORE_SELECT_H
#define _CORE_SELECT_H
#include "../include/core.h"
#include "../include/List.h"

List<unsigned>* Core::selectByRect(double x1, double y1, double x2, double y2) {
	List<unsigned>* PickedObjects = new List<unsigned>;
	List<unsigned>::Marker p(*PickedObjects);
	for (List<GraphPrimitive*>::Marker mar(objects);mar.exist();mar.move_next()) {
		if (mar.get_current()->isInRect(x1, y1, x2, y2)) {
			PickedObjects->push_back(mar.get_current()->showId());
			mar.get_current()->changePick(1);
		}
		else mar.get_current()->changePick(0); // delete last selection
	}
		return PickedObjects;
}

unsigned Core::selectByPoint(Point p) {
	const double EPS = 1e-10;
	double current_distance, min_distance = EPS;
	unsigned min_id = 0;
	for (List<GraphPrimitive*>::Marker mar(objects);mar.exist();mar.move_next()) {
		current_distance = mar.get_current()->distanceToPoint(p.getX(),p.getY());
		if (current_distance < min_distance) {
			min_distance = current_distance;
			min_id = mar.get_current()->showId();
		}
}	
	return min_id;
}

#endif
