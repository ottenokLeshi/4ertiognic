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

	backupParametrs = new Array <Array<double>>;
	List<GraphPrimitive*>::Marker mar(objects);
	Point * newp = 0; Circle *newc = 0; Segment * news = 0;
	for (size_t i = 0; i < objects.sizeList(); i++) {
		Array<double> par;

		switch (mar.get_current()->object_type()) {

		case IsPoint:
			newp = dynamic_cast<Point*>(mar.get_current());
			par.push_back(newp->getX()); 
			par.push_back(newp->getY());
			break;

		case IsSegment:
			news = dynamic_cast<Segment*>(mar.get_current());
			par.push_back(news->x1()); 
			par.push_back(news->y1());
			par.push_back(news->x2()); 
			par.push_back(news->y2());
			break;

		case IsCircle:
			newc = dynamic_cast<Circle*>(mar.get_current());
			Point t = newc->getCenter();
			par.push_back(t.getX());
			par.push_back(t.getY());
			par.push_back(newc->getRadius());
			break;
		}

		backupParametrs->push_back(par);
		mar.move_next();
	}
	return;
}



void Core::restoreState()
{
	List<GraphPrimitive*>::Marker mar(objects);
	Point * newp = 0; Circle *newc = 0; Segment * news = 0;
	for (size_t i = 0; i < objects.sizeList(); i++) {

		switch (mar.get_current()->object_type()) {

		case IsPoint:
			newp = dynamic_cast<Point*>(mar.get_current());
			newp->changePoint((*backupParametrs)[i][0], (*backupParametrs)[i][1]);
			break;

		case IsSegment:
			news = dynamic_cast<Segment*>(mar.get_current());
			news->getP1()->changePoint((*backupParametrs)[i][0], (*backupParametrs)[i][1]);
			news->getP2()->changePoint((*backupParametrs)[i][2], (*backupParametrs)[i][3]);
			break;

		case IsCircle:
			newc = dynamic_cast<Circle*>(mar.get_current());
			newc->getC()->changePoint((*backupParametrs)[i][0], (*backupParametrs)[i][1]);
			newc->changeCircle(newc->getC(), (*backupParametrs)[i][2]);
			break;
		}


		mar.move_next();
	}
}

Array <Array<double>>* Core::getInfoObj() {
	Array <Array<double>> *parametrs = new Array <Array<double>>;
	List<GraphPrimitive*>::Marker mar(objects);
	Point * newp = 0; Circle *newc = 0; Segment * news = 0;
	for (size_t i = 0; i < objects.sizeList(); i++) {
		Array<double> par;

		switch (mar.get_current()->object_type()) {
		case IsPoint:
			newp = dynamic_cast<Point*>(mar.get_current());
			par.push_back(newp->getX());
			par.push_back(newp->getY());
			break;

		case IsSegment:
			news = dynamic_cast<Segment*>(mar.get_current());
			par.push_back(news->x1());
			par.push_back(news->y1());
			par.push_back(news->x2());
			par.push_back(news->y2());
			break;

		case IsCircle:
			newc = dynamic_cast<Circle*>(mar.get_current());
			par.push_back(newc->getCenter().getX());
			par.push_back(newc->getCenter().getY());
			par.push_back(newc->getRadius());
			break;
		}
		
		parametrs->push_back(par);
		mar.move_next();
	}
	return  parametrs;
}

void Core::clearState() {
	SOLVE = nullptr;
	objects.deleteAll();
	restrictions.deleteAll();
	backupObjects.deleteAll();
	fixedObjects.deleteAll();
	if (backupParametrs)
		backupParametrs->deleteAll();
	params.deleteAll();
}

void Core::deleteRestrs(Point object) {
	List<GraphPrimitive*>::Marker mar(objects);
	Point * newp = 0;
	for (size_t i = 0; i < objects.sizeList(); i++) {
		if (mar.get_current()->showId() == object.showId()) {
			newp = dynamic_cast<Point*>(mar.get_current());
			break; // found object
		}
		mar.move_next();
	}
	if (newp == 0) return;
	List<BasicRestriction*>::Marker mar1(restrictions);
	size_t restsize = restrictions.sizeList();
	for (size_t i = 0; i < restsize; i++) {
		auto restr = mar1.get_current();
		switch (restr->get_type()) {
		case RT_P2PDIST: {
			auto p2p = dynamic_cast<RestrP2PDIST*> (restr);
			if (p2p->getP1() == newp || p2p->getP2() == newp) {
				restrictions.deleteElem(mar1);
				mar1 = restrictions.inBegin();
				for (size_t j = 0; j < i && mar1.exist(); j++) {
					mar1.move_next();
				}
			}
			else mar1.move_next();
		}break;
		case RT_P2SDIST: {
			auto p2s = dynamic_cast<RestrP2SDIST*> (restr);
			if (p2s->getP1() == newp || p2s->getP2() == newp || p2s->getP3() == newp) {
				restrictions.deleteElem(mar1);
				mar1 = restrictions.inBegin();
				for (size_t j = 0; j < i && mar1.exist(); j++) {
					mar1.move_next();
				}
			}
			else mar1.move_next();
		}break;
		case RT_P2SDISTEX: {
			auto p2sex = dynamic_cast<RestrP2SDISTEX*> (restr);
			if (p2sex->getP1() == newp || p2sex->getP2() == newp || p2sex->getP3() == newp) {
				restrictions.deleteElem(mar1);
				mar1 = restrictions.inBegin();
				for (size_t j = 0; j < i && mar1.exist(); j++) {
					mar1.move_next();
				}
			}
			else mar1.move_next();
		}break;
		case RT_S2SANGLE: {
			auto s2sang = dynamic_cast<RestrS2SANGLE*> (restr);
			if (s2sang->getS1()->getP1() == newp || s2sang->getS2()->getP1() == newp ||
				s2sang->getS1()->getP2() == newp || s2sang->getS2()->getP2() == newp) {
				restrictions.deleteElem(mar1);
				mar1 = restrictions.inBegin();
				for (size_t j = 0; j < i && mar1.exist(); j++) {
					mar1.move_next();
				}
			}
			else mar1.move_next();
		}break;
		case RT_S2SORTHO: {
			auto s2sort = dynamic_cast<RestrS2SORTHO*> (restr);
			if (s2sort->getS1()->getP1() == newp || s2sort->getS2()->getP1() == newp ||
				s2sort->getS1()->getP2() == newp || s2sort->getS2()->getP2() == newp) {
				restrictions.deleteElem(mar1);
				mar1 = restrictions.inBegin();
				for (size_t j = 0; j < i && mar1.exist(); j++) {
					mar1.move_next();
				}
			}
			else mar1.move_next();
		}break;
		case RT_S2SPARAL: {
			auto s2spar = dynamic_cast<RestrS2SPARAL*> (restr);
			if (s2spar->getS1()->getP1() == newp || s2spar->getS2()->getP1() == newp ||
				s2spar->getS1()->getP2() == newp || s2spar->getS2()->getP2() == newp) {
				restrictions.deleteElem(mar1);
				mar1 = restrictions.inBegin();
				for (size_t j = 0; j < i && mar1.exist(); j++) {
					mar1.move_next();
				}
			}
			else mar1.move_next();
		}break;
		case RT_S2SEQUALS: {
			auto s2seq = dynamic_cast<RestrS2SEQUALS*> (restr);
			if (s2seq->getS1()->getP1() == newp || s2seq->getS2()->getP1() == newp ||
				s2seq->getS1()->getP2() == newp || s2seq->getS2()->getP2() == newp) {
				restrictions.deleteElem(mar1);
				mar1 = restrictions.inBegin();
				for (size_t j = 0; j < i && mar1.exist(); j++) {
					mar1.move_next();
				}
			}
			else mar1.move_next();
		}break;
		}
	}
}

void Core::deleteSelected() {
	List<GraphPrimitive*>::Marker mar(objects);
	Point * newp = 0;
	Segment * news = 0;
	Circle * newc = 0;
	for (size_t i = 0; i < objects.sizeList() + 1; i++) {
		switch (mar.get_current()->object_type()) {
		case IsPoint: {
			newp = dynamic_cast<Point*>(mar.get_current());
			if (newp->isPicked()) {
				deleteRestrs(*newp);
				objects.deleteElem(mar);
				mar = objects.inBegin();
				for (size_t j = 0; j < i && mar.exist(); j++) {
					mar.move_next();
				}
			}
			else mar.move_next();
		} break;
		case IsSegment: {
			news = dynamic_cast<Segment*>(mar.get_current());
			if (!searchID(news->getP1()->showId()) || !searchID(news->getP2()->showId())) {
				objects.deleteElem(mar);
				mar = objects.inBegin();
				for (size_t i = 0; i < objects.sizeList() && mar.exist(); i++) {
					if (mar.get_current() == news->getP1()) {
						deleteRestrs(*news->getP1());
						objects.deleteElem(mar);
						break;
					}
					mar.move_next();
				}
				mar = objects.inBegin();
				for (size_t i = 0; i < objects.sizeList() && mar.exist(); i++) {
					if (mar.get_current() == news->getP2()) {
						deleteRestrs(*news->getP2());
						objects.deleteElem(mar);
						break;
					}
					mar.move_next();
				}
				mar = objects.inBegin();
				for (size_t j = 0; j < i && mar.exist(); j++) {
					mar.move_next();
				}
			}
			else mar.move_next();
		} break;
		case IsCircle: {
			newc = dynamic_cast<Circle*>(mar.get_current());
			if (!searchID(newc->getC()->showId())) {
				objects.deleteElem(mar);
				mar = objects.inBegin();
				for (size_t i = 0; i < objects.sizeList() && mar.exist(); i++) {
					if (mar.get_current() == newc->getC()) {
						deleteRestrs(*newc->getC());
						objects.deleteElem(mar);
						break;
					}
					mar.move_next();
				}
				mar = objects.inBegin();
				for (size_t j = 0; j < i && mar.exist(); j++) {
					mar.move_next();
				}
			}
			else mar.move_next();
		}break;
		}
	}
}
