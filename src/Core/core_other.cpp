#include "core.h"
#include <stdio.h> 
#include <windows.h> 

typedef ISolver* (_cdecl *PROCFUN)(void);

void Core::getSOLVE(bool _bSolve) {
	ISolver* SOLVE;

	HINSTANCE hinstLib;
	PROCFUN Func;
	BOOL fFreeResult, fRunTimeLinkSuccess;
	fRunTimeLinkSuccess = FALSE;

	if (_bSolve)	hinstLib = LoadLibrary(TEXT("GDdll.dll"));
	else hinstLib = LoadLibrary(TEXT("HJdll.dll"));

	if (hinstLib != nullptr) {
		cout << "Lib Load" << endl;
		Func = (PROCFUN)GetProcAddress(hinstLib, "getMethod");

		if (nullptr != Func)
		{
			fRunTimeLinkSuccess = TRUE;
			cout << "O.K." << endl;
			SOLVE = Func();
		}

	}
	if (!fRunTimeLinkSuccess) {
		fFreeResult = FreeLibrary(hinstLib);
		cout << "404 not found" << endl;
		system("pause");
		SOLVE = nullptr;
		return;
	}
}
void Core::backupState() {
	backupObjects.deleteAll();
	List<GraphPrimitive*>::Marker mar(objects);
	Point *newpoint = new Point;
	Segment *newseg = new Segment;
	Circle *newcir = new Circle;
	Point *point = 0;
	Segment *seg = 0;
	Circle *circle = 0;
	for (size_t i = 0;i < objects.sizeList();i++) {
		Primitive_Type type = mar.get_current()->object_type();
		switch (type) {
		case IsPoint:
			point = dynamic_cast<Point*>(*mar);
			newpoint = new Point;
			newpoint->changePoint(point->getX(), point->getY());
			backupObjects.push_back(newpoint);
			break;

		case IsSegment:
			seg = dynamic_cast<Segment*>(*mar);
			newseg = new Segment;
			newseg->changeSegment(seg->getP1(),seg->getP2());
			backupObjects.push_back(newseg);
			break;

		case IsCircle:
			circle = dynamic_cast<Circle*>(*mar);
			newcir = new Circle;
			newcir->changeCircle(&circle->getCenter(),circle->getRadius());
			backupObjects.push_back(newcir);
			break;
		}
		mar.move_next();
	}
}

Array <Array<double>>* Core::getInfoObj() {
	Array <Array<double>> *parametrs = new Array <Array<double>>;
	List<GraphPrimitive*>::Marker mar(objects);
	Point * newp = 0; Circle *newc = 0; Segment * news = 0;
	for (size_t i = 0;i < objects.sizeList();i++) {
		Array<double> par;

		switch (mar.get_current()->object_type()) {

		case IsPoint:
			newp = dynamic_cast<Point*>(mar.get_current());
			par.push_back(newp->getX());par.push_back(newp->getY());
			break;

		case IsSegment:
			news = dynamic_cast<Segment*>(mar.get_current());
			par.push_back(news->x1());par.push_back(news->y1());
			par.push_back(news->x2());par.push_back(news->y2());
			break;

		case IsCircle:
			newc = dynamic_cast<Circle*>(mar.get_current());
			Point t = newc->getCenter();
			par.push_back(t.getX());
			par.push_back(t.getY());
			par.push_back(newc->getRadius());
			break;
		}
		
		parametrs->push_back(par);
		mar.move_next();
	}
	return  parametrs;
}