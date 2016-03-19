#ifndef _RESTR_P2PDIST_H
#define _RESTR_P2PDIST_H

#include "BasicRestriction.h"

class RestrP2PDist:BasicRestriction
{
public:
	RestrP2PDist();

	RestrictType get_type()const{return RT_P2PDIST;};
	double violation()const{return 0;};
};

#endif