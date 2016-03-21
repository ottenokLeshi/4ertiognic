#ifndef _RESTR_S2SORTHO_H_
#define _RESTR_S2SORTHO_H_

#include "BasicRestriction.h"

class RestrS2Sortho :BasicRestriction {
	public:
		RestrS2Sortho();
		~RestrS2Sortho();
		
		RestrictType get_type()const { return RT_S2SORTHO; };
		double violation()const { return 0; };
};

#endif