#ifndef _MATLAB_RENDERER_H
#define _MATLAB_RENDERER_H
#include <iostream>
#include <fstream> 
#include <string>
#include "GUI.h"
#include "GUI_types.h"
#include "objects.h"
#include "MArray.h"
#include "core.h"
using namespace std;
class MatlabRenderer : public GUI {
	string _filename;
	size_t _markersize;
	Core *_core;
public:
	MatlabRenderer(string filename, Core *core, size_t markersize) {
		_filename = filename;
		_core = core;
		_markersize = markersize;
	}
	virtual void drawSketch();

	virtual bool drawPrimitive(Primitive_Type type, Array<double> &parametrs, size_t markersize);
	virtual  GUIType getTypeGUI() {
		return MATLAB;
	}

};
#endif 