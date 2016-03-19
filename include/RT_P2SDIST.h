#ifndef _RESTR_P2SDIST_H
#define _RESTR_P2SDIST_H

#include "BasicRestriction.h"

class ResrtP2SDist:BasicRestriction {
public:
	RestrP2SDist();
	~RestrP2SDist();
	
	RestrictType get_type()const{return RT_P2SDIST;};
	double violation()const{return 0;};	
};

#endif