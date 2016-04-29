#ifndef _BASIC_RESTRICTION_H
#define _BASIC_RESTRICTION_H

#include "restrict_types.h"

class BasicRestriction
 {
	public:
		BasicRestriction() {}
		int get_id()const {}
		virtual RestrictType get_type()const = 0;
		virtual double violation()const = 0;
                virtual double diff(size_t par) = 0;
				double length(double x1, double y1, double x2, double y2) {
					return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
				}
			virtual Array<double*> getFixP() = 0;
		
};
#endif
