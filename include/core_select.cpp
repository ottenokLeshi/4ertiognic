#include "core.h"





List<GraphPrimitive>* Core::selectByRect(double x1, double y1, double x2, double y2) {
	List<GraphPrimitive> PickedObjects;
	//search in a ListPoint
	int s_Point = ListPoint.size();
	for (int i = 1; i <= s_Point;i++) {
		Point* point = ListPoint.get_elem(i);
		if ((x1 <= point->x()) && (point->x() <= x2) && (y1 <= point->y()) && (point->y() <= y2)) {
			PickedObjects.add_back(point);
                        point->changePick();
		}
	}
   //search in a ListSegment
	int s_Segment = ListSegment.size();
	for (int i = 1; i <= s_Segment;i++) {
		Segment* segment = ListSegment.get_elem(i);
		if ((x1 <= segment->x1()) && (segment->x1() <= x2) && (y1 <= segment->y1()) && (segment->y1() <= y2)) || 
			((x1 <= segment->x2()) && (segment->x2() <= x2) && (y1 <= segment->y2()) && (segment->y2) <= y2))
		{
			PickedObjects.add_back(segment);
                        segment->changePick();
		}

	//search in a ListCircle
		int s_Circle = ListCircle.size();
		for (int i = 1; i <= s_Circle;i++) {
			Circle* circle = ListCircle.get_elem(i);
			if ((x1 <= circle->getCenter._x()) && (circle->getCenter._x() <= x2) && (y1 <= circle->getCenter._y()) && (circle->getCenter._y() <= y2)) {
				PickedObjects.add_back(circle);
                                circle->changePick();
			}
		}

		return &PickedObjects;
}
