#include <iostream>
#include "MArray.h"
#include "objects.h"

std::ostream & operator<<(std::ostream & ost, const Point &p){
	ost << '('<<p.getX() << ',' << p.getY() << ')';
	return ost;
}

int main(){
	Point *p1 = new Point(1,1);
	Point *p2 = new Point(2,2);
	Segment *s = new Segment(p1,p2);

	
	Array<GraphPrimitive*> primitives;
	primitives.push_back(p1);
	primitives.push_back(p2);
	primitives.push_back(s);

	Array<GraphPrimitive*>::Marker m = primitives.begin();	

	while ( m != primitives.end() ){
		std::cout << "Object type = " << (*m)->object_type() <<  std::endl;
		switch((*m)->object_type()){
		case IsPoint:{
			Point*p = dynamic_cast<Point*>(*m);
				std::cout << *p << std::endl;
				break;
			}
		default: {
			std::cout << "Wrong object type" << std::endl;
				 }
		}
		++m;
	}
	
	return 0;
}