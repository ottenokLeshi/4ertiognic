#ifndef _CONSOLE_H_
#define _CONSOLE_H_ 
#include <iostream>
#include <stdlib.h>
#include "core.h"
#include "string_extensions.h"

using namespace std;

class Console {
public:
	Console() {}
	~Console() {}

	bool screen();
	void outputAll(Core &Cor);
};
#endif
