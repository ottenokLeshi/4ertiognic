#ifndef _CORE_SELECT_H
#define _CORE_SELECT_H
#include "../include/core.h"
#include "../include/List.h"

List<unsigned>* Core::selectByRect(double x1, double y1, double x2, double y2) {
	List<unsigned>* PickedObjects = new List<unsigned>;
	List<unsigned>::Marker p(*PickedObjects);
	for (List<GraphPrimitive*>::Marker mar(objects);mar.exist();mar.move_next()) {
		if (mar.get_current()->isInRect(x1, y1, x2, y2)) {
			PickedObjects->addElem(p, mar.get_current()->showId());
		}
	}
		return PickedObjects;
}
/*
GraphPrimitive* Core::selectByPoint(Point p) {
	GraphPrimitive* PickedObject = NULL;
	const double EPS = 1e-10;
	double current_distance, min_distance = 0;
	bool isEmpty = true;
	for (int i = 0; i < objects.size(); i++) {
		current_distance = objects.get_elem(i)->distanceToPoint(p.getX(),p.getY());
		if (current_distance <= EPS) {
			if (isEmpty) {
				PickedObject = objects.get_elem(i);
				isEmpty = false;
			}
			else if (current_distance < min_distance) {
				PickedObject = objects.get_elem(i);
				min_distance = current_distance;
			}
		}
	}
	return PickedObject;
}
*/
#endif