#include "core.h"





List<GraphPrimitive*>* Core::selectByRect(double x1, double y1, double x2, double y2) {
	List<GraphPrimitive*>* PickedObjects = new List<GraphPrimitive*>;
	for (int i = 0; i < objects.size();i++) {
		if (objects.get_elem(i)->isInRect(x1, y1, x2, y2))
			PickedObjects->add_back(objects.get_elem(i));
		}
			return PickedObjects;
}
