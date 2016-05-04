#ifndef _GUI_H
#define _GUI_H
#include "GUI_types.h"
#include "objects.h"
#include "MArray.h"
class GUI {
public:
	GUI() {}
	virtual ~GUI() {}
	virtual void drawSketch(Array<Primitive_Type> *objType, Array <Array<double>> *parametrs) = 0;

	virtual bool drawPrimitive(Primitive_Type type, Array<double> &parametrs, size_t markersize) = 0;
	virtual  GUIType getTypeGUI() = 0;

};

#endif