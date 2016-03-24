#include "core.h"


List<GraphPrimitive*>* Core::selectByRect(double x1, double y1, double x2, double y2) {
	List<GraphPrimitive*>* PickedObjects = new List<GraphPrimitive*>;
	for (int i = 0; i < objects.size();i++) {
		if (objects.get_elem(i)->isInRect(x1, y1, x2, y2))
			PickedObjects->add_back(objects.get_elem(i));
		}
			return PickedObjects;
}

GraphPrimitive* Core::selectByPoint(double x, double y) {
	GraphPrimitive* PickedObject = NULL;
	const double EPS = 1e-10;
	double current_distance, min_distance = 0;
	bool isEmpty = true;
	for (int i = 0; i < objects.size(); i++) {
		current_distance = objects.get_elem(i)->distanceToPoint(x, y);
		if (current_distance <= EPS) {
			if (isEmpty) {
				PickedObject = objects.get_elem(i);
				isEmpty = false;
			}
			else if (current_distance < min_distance) {
				PickedObject = object.get_elem(i);
				min_distance = current_distance;
			}
		}
	}
	return PickedObject;
}