#ifndef _MATLAB_RENDERER_H
#define _MATLAB_RENDERER_H
#include <iostream>
#include <fstream> 
#include <string>
#include "core.h"

using namespace std;
class MatlabRenderer {
	string _filename;
	Core *_core;
	size_t _markersize;
public:

	MatlabRenderer(string filename, Core *core, size_t markersize)
		: _filename(filename), _core(core), _markersize(markersize) {}

	~MatlabRenderer() {}

	void drawSketch();

	bool drawPrimitive(Primitive_Type type, const Array<double> &parametrs, size_t markersize);

};
#endif 