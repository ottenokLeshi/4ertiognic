#include <stdio.h> 
#include <windows.h>
#include "console.h"
#include <iostream>
#include <stdlib.h>
#include "matlab_renderer.h"

typedef ISolver* (_cdecl *PROCFUN)(void);

bool Console::screen() {
	ISolver* SOLVE = nullptr;
	HINSTANCE hinstLib;
	PROCFUN Func;
	BOOL fFreeResult, fRunTimeLinkSuccess;
	string c;
	Core Cor;
	while (true) {
		system("cls");
		cout << "a. Add graph primitive" << endl;
		cout << "b. Add restriction" << endl;
		cout << "c. Choose your side of the darkness!" << endl;
		cout << "d. Matlab file" << endl;
		cout << "<. UNDO" << endl;
		cout << "q. Exit" << endl;
		getline(cin, c);

switch (c[0]) {
		case 'q':
			return 0;
		case 'a': {
			system("cls");
			cout << "a. Point" << endl;
			cout << "b. Segment" << endl;
			cout << "c. Circle" << endl;
			cout << "q. Cancel" << endl;

			getline(cin, c);

			switch (c[0]) {

			case 'a': {
				system("cls");
				outputAll(Cor);
				cout << "Write coordinates: x and y" << endl;
				double x, y;
				cin >> x >> y;
				Array <double> Arr(0);
				Arr.push_back(x);
				Arr.push_back(y);
				Cor.addObject(Arr, IsPoint);
				break;
			}
			case 'b': {
				system("cls");
				outputAll(Cor);
				cout << "Write coordinates: x1, y1, x2 and y2" << endl;
				double x1, y1, x2, y2;
				cin >> x1 >> y1 >> x2 >> y2;
				Array <double> Arr(0);
				Arr.push_back(x1);
				Arr.push_back(y1);
				Arr.push_back(x2);
				Arr.push_back(y2);
				Cor.addObject(Arr, IsSegment);
				break;
			}
			case 'c': {
				system("cls");
				outputAll(Cor);
				cout << "Write coordinates: x1, y1 and radius" << endl;
				double x, y, r;
				cin >> x >> y >> r;
				Array <double> Arr(0);
				Arr.push_back(x);
				Arr.push_back(y);
				Arr.push_back(r);
				Cor.addObject(Arr, IsCircle);
				break;
				}
			}
			Cor.backupState();
			break;
		}//end of addition

		case 'b': {
			system("cls");
			cout << "a. RT_FIX" << endl;
			cout << "b. RT_P2PDIST" << endl;
			cout << "c. RT_P2SDIST" << endl;
			cout << "d. RT_P2SDISTEX" << endl;
			cout << "e. RT_S2SANGLE" << endl;
			cout << "f. RT_S2SEQUALS" << endl;
			cout << "g. RT_S2SPARAL" << endl;
			cout << "h. RT_S2SORTHO" << endl;
			cout << "q. Cancel" << endl;

			getline(cin, c);
			switch (c[0]) {
			case 'a': {
				system("cls");
				int id;
				double d = 1;
				cout << "Write id of point" << endl;
				cin >> id;
				List <unsigned> List_;
				List_.push_back(id);
				Cor.addRestriction(&List_, &d, RT_FIX, SOLVE);
				break;
			}
			case 'b': {
				system("cls");
				outputAll(Cor);
				int id1, id2;
				double d;
				cout << "Point:" << endl;
				cout << "Write id of 2 points and distance" << endl;
				List <unsigned> List_;
				cin >> id1 >> id2 >> d;
				List_.push_back(id1);
				List_.push_back(id2);
				Cor.addRestriction(&List_, &d, RT_P2PDIST, SOLVE);
				break;
			}
			case 'c': {
				system("cls");
				outputAll(Cor);
				int id1, id2;
				double d;
				cout << "Points:" << endl;
				cout << "Segment:" << endl;
				List <unsigned> List_;
				cout << "Write id of point, segment and distance" << endl;
				cin >> id1 >> id2 >> d;
				List_.push_back(id1);
				List_.push_back(id2);
				Cor.addRestriction(&List_, &d, RT_P2SDIST, SOLVE);
				break;
			}
			case 'd': {
				system("cls");
				outputAll(Cor);
				int id1, id2;
				double d;
				cout << "Segment:" << endl;
				List <unsigned> List_;
				cout << "Write id of two segments and distance" << endl;
				cin >> id1 >> id2 >> d;
				List_.push_back(id1);
				List_.push_back(id2);
				Cor.addRestriction(&List_, &d, RT_P2SDISTEX, SOLVE);
				break;
			}
			case 'e': {
				system("cls");
				outputAll(Cor);
				int id1, id2;
				double d;
				cout << "Segment:" << endl;
				List <unsigned> List_;
				cout << "Write id of two segments and angle" << endl;
				cin >> id1 >> id2 >> d;
				List_.push_back(id1);
				List_.push_back(id2);
				Cor.addRestriction(&List_, &d, RT_S2SANGLE, SOLVE);
				break;
			}
			case 'f': {
				system("cls");
				outputAll(Cor);
				int id1, id2;
				cout << "Segment:" << endl;
				List <unsigned> List_;
				cout << "Write id of two segments" << endl;
				cin >> id1 >> id2;
				List_.push_back(id1);
				List_.push_back(id2);
				Cor.addRestriction(&List_, 0, RT_S2SEQUALS, SOLVE);
				break;
			}
			case 'g': {
				system("cls");
				outputAll(Cor);
				int id1, id2;
				cout << "Segment:" << endl;
				List <unsigned> List_;
				cout << "Write id of two segments" << endl;
				cin >> id1 >> id2;
				List_.push_back(id1);
				List_.push_back(id2);
				Cor.addRestriction(&List_, 0, RT_S2SPARAL, SOLVE);
				break;
			}
			case 'h': {
				system("cls");
				outputAll(Cor);
				int id1, id2;
				cout << "Segment:" << endl;
				List <unsigned> List_;
				cout << "Write id of two segments" << endl;
				cin >> id1 >> id2;
				List_.push_back(id1);
				List_.push_back(id2);
				Cor.addRestriction(&List_, 0, RT_S2SORTHO, SOLVE);
				break;
			}
			Cor.backupState();
			}
			break;
		}
		
		case 'c': {
			system("cls");
			cout << "Write type of solver H or G" << endl;
			getline(cin, c);
			switch (c[0]) {
			case 'H': {
				fRunTimeLinkSuccess = FALSE;
				hinstLib = LoadLibrary(TEXT("HJdll.dll"));
				if (hinstLib != nullptr) {
					cout << "Lib Load" << endl;
					Func = (PROCFUN)GetProcAddress(hinstLib, "getMethod");

					if (nullptr != Func) {
						fRunTimeLinkSuccess = TRUE;
						cout << "O.K." << endl;

						SOLVE = Func();
					}

				}
				if (!fRunTimeLinkSuccess) {
					fFreeResult = FreeLibrary(hinstLib);
					cout << "Hook J: 404 not found" << endl;
					system("pause");
					return 0;
				}
				break;
			}
			case 'G': {
				fRunTimeLinkSuccess = FALSE;
				hinstLib = LoadLibrary(TEXT("dllGD.dll"));
				if (hinstLib != nullptr) {
					cout << "Lib Load" << endl;
					Func = (PROCFUN)GetProcAddress(hinstLib, "getMethod");

					if (nullptr != Func) {
						fRunTimeLinkSuccess = TRUE;
						cout << "O.K." << endl;
						SOLVE = Func();
					}

				}
				if (!fRunTimeLinkSuccess) {
					fFreeResult = FreeLibrary(hinstLib);
					cout << "Grad D: 404 not found" << endl;
					system("pause");
					return 0;
				}
				break;
			}
			}
			break;
		}
		
		case'd': {
			system("cls");
			string _resultfilename = "Batch.m";
			ofstream out(_resultfilename);
			out.close();
			MatlabRenderer matlab(_resultfilename, 10);
			matlab.drawSketch(Cor.getInfoObj());
			break;
		}
		
		case'<': {
			Cor.toBackupState();
		}
}

}

}

void Console::outputAll(Core &Cor)
{
	for (int i = 1; i <= Cor.sizeListObj(); ++i) {
		Point * newp = 0; Circle *newc = 0; Segment * news = 0;
		switch (Cor.searchID(i)->object_type()) {

		case IsPoint:
			newp = dynamic_cast<Point*>(Cor.searchID(i));
			cout << "ID: " << newp->showId() << "   X: " << newp->getX() << "   Y: " << newp->getY() << endl;
			break;

		case IsSegment:
			news = dynamic_cast<Segment*>(Cor.searchID(i));
			cout << "ID: " << news->showId() << "   X1: " << news->getP1()->getX() << "   Y1: " << news->getP1()->getY() << "   X2: " << news->getP2()->getX() << "   Y2: " << news->getP2()->getY() << endl;
			break;

		case IsCircle:
			newc = dynamic_cast<Circle*>(Cor.searchID(i));
			Point t = newc->getCenter();
			cout << "ID: " << newc->showId() << "   X: " << newc->getCenter().getX() << "   Y: " << newc->getCenter().getY() 
				<< "   Radius: " << newc->getRadius() << endl;
			break;
		}
	}
}
