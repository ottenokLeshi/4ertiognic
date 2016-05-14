#ifndef _GUI_H
#define _GUI_H
#include "GUI_types.h"
#include "../include/Containers/MArray.h"
class GUI {
public:
	GUI() {}
	virtual ~GUI() {}
	virtual void drawSketch( Array <Array<double>> *parametrs) = 0;

	virtual bool drawPrimitive(Array<double> &parametrs, size_t markersize) = 0;
	virtual  GUIType getTypeGUI() = 0;

};

#endif
