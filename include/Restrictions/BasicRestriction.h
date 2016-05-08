#ifndef _BASIC_RESTRICTION_H
#define _BASIC_RESTRICTION_H

#include "restrict_types.h"
#include <cmath>
class BasicRestriction
 {
	 int _id;
	 static int static_id;
 public:
	 static int next_object_id() {
		 ++static_id;
		 return static_id;
	 }
	BasicRestriction() { _id = BasicRestriction::next_object_id(); }
	int showId()const { return _id; }
	virtual RestrictType get_type()const = 0;
	virtual double violation()const = 0;
    virtual double diff(size_t par) = 0;
    double length(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	}
};
#endif
