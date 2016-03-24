#ifndef _BASIC_RESTRICTION_H
#define _BASIC_RESTRICTION_H

#include "restrict_types.h"

class BasicRestriction
{
public:
	BasicRestriction();
	int get_id()const;
	virtual RestrictType get_type()const = 0;
	virtual double violation()const = 0;
};
#endif
