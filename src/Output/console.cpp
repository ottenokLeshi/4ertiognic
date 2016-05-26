#include <stdio.h> 
#include <windows.h>
#include "console.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include "matlab_renderer.h"
#include "batch_processor.h"
using namespace std;

typedef ISolver* (_cdecl *PROCFUN)(void);


bool Console::screen() {
	ISolver* SOLVE = nullptr;
	HINSTANCE hinstLib;
	PROCFUN Func;
	BOOL fFreeResult, fRunTimeLinkSuccess;
	Core core;

	string c; // every line in batch.txt
	Array<string> tokens; // splitted command
	char cmd_type;

	while (true) {
		system("cls");
		outputAll(core);
		cout << "a. Add graph primitive" << endl;
		cout << "b. Add restriction" << endl;
		cout << "c. Choose your side of the darkness!" << endl;
		cout << "l. Load from batch" << endl;
		cout << "d. Matlab file" << endl;
		cout << "*. Clear state" << endl;
		cout << "q. Exit" << endl;

		do {
			getline(cin, c);
		} while (c.length() != 1);

		cmd_type = c[0];
		List<unsigned> objId; // List to store objects
		Array< double* > restrParams;

		switch (cmd_type) {
		case 'q':
			return 0;
		case 'a': {
			system("cls");
			outputAll(core);
			cout << "a. Point" << endl;
			cout << "b. Segment" << endl;
			cout << "c. Circle" << endl;
			cout << "q. Cancel" << endl;

			do {
				getline(cin, c);
			} while (c.length() != 1);

			cmd_type = c[0];

			switch (cmd_type) {
			case 'a': {
				system("cls");
				outputAll(core);
				cout << "Write coordinates: x and y" << endl;
				cout << "(q to cancel)" << endl;
				double x, y;

				bool flag;
				do {
					flag = true;
					getline(cin, c);
					tokens = stringSplit(c);
					if (tokens.size() != 2)
						flag = false;
					try {
						if (tokens[0] == "q")
							break;
						x = stod(tokens[0]);
						y = stod(tokens[1]);
					}
					catch (exception) {
						std::cout << "Error: point coordinates must be 2 doubles" << std::endl;
						flag = false;
					}
				} while (!flag);

				if (tokens[0] == "q")
					break;

				Array <double> Arr;
				Arr.push_back(x);
				Arr.push_back(y);
				core.addObject(Arr, IsPoint);
			} break;

			case 'b': {
				system("cls");
				outputAll(core);
				cout << "Write coordinates: x1, y1, x2 and y2" << endl;
				cout << "(q to cancel)" << endl;
				double x1, y1, x2, y2;

				bool flag;
				do {
					flag = true;
					getline(cin, c);
					tokens = stringSplit(c);
					if (tokens.size() != 4)
						flag = false;
					try {
						if (tokens[0] == "q")
							break;
						x1 = stod(tokens[0]);
						y1 = stod(tokens[1]);
						x2 = stod(tokens[2]);
						y2 = stod(tokens[3]);
					}
					catch (exception) {
						std::cout << "Error: segment coordinates must be 4 doubles" << std::endl;
						flag = false;
					}
				} while (!flag);

				if (tokens[0] == "q")
					break;

				Array <double> Arr;
				Arr.push_back(x1);
				Arr.push_back(y1);
				Arr.push_back(x2);
				Arr.push_back(y2);
				core.addObject(Arr, IsSegment);
			} break;

			case 'c': {
				system("cls");
				outputAll(core);
				cout << "Write coordinates: x1, y1 and radius" << endl;
				cout << "(q to cancel)" << endl;
				double x, y, r;

				bool flag;
				do {
					flag = true;
					getline(cin, c);
					tokens = stringSplit(c);
					if (tokens.size() != 3)
						flag = false;
					try {
						if (tokens[0] == "q")
							break;
						x = stod(tokens[0]);
						y = stod(tokens[1]);
						r = stod(tokens[2]);
					}
					catch (exception) {
						std::cout << "Error: circle coordinates must be 2 doubles, s"
							"radius must be double" << std::endl;
						flag = false;
					}
				} while (!flag);

				if (tokens[0] == "q")
					break;

				Array <double> Arr;
				Arr.push_back(x);
				Arr.push_back(y);
				Arr.push_back(r);
				core.addObject(Arr, IsCircle);
			} break;

			default: {
				cout << "Invalid command." << endl;
			}
			}
			core.backupState();
		} break; //end of addition

		case 'b': {

			if (SOLVE == nullptr) {
				system("cls");
				outputAll(core);
				cout << endl;
				cout << "Choose your side first!" << endl;
				system("pause");
				break;
			}

			if (core.sizeListObj() == 0) {
				system("cls");
				outputAll(core);
				cout << endl;
				cout << "No objects yet!" << endl;
				system("pause");
				break;
			}

			objId.deleteAll();

			system("cls");
			outputAll(core);

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
				outputAll(core);
				unsigned id;
				double d = 0;
				cout << "Write id of object" << endl;
				cout << "(q to cancel)" << endl;

				bool flag;
				do {
					flag = true;
					getline(cin, c);
					tokens = stringSplit(c);
					if (tokens.size() != 1)
						flag = false;
					try {
						if (tokens[0] == "q")
							break;
						id = stoi(tokens[0]);
					}
					catch (exception) {
						std::cout << "Error: id of a point must be an integer" << std::endl;
						flag = false;
					}
				} while (!flag);

				if (tokens[0] == "q")
					break;

				objId.push_back(id);
				core.addRestriction(&objId, &d, RT_FIX, SOLVE);
			} break;
			case 'b': {
				system("cls");

				if (core.sizeListObj() < 2) {
					system("cls");
					outputAll(core);
					cout << endl;
					cout << "Not enough objects!" << endl;
					system("pause");
					break;
				}

				outputAll(core);
				unsigned id1, id2;
				cout << "Write id of 2 points and distance" << endl;
				cout << "(q to cancel)" << endl;

				restrParams.push_back(new double);
				bool flag;
				do {
					flag = true;
					getline(cin, c);
					tokens = stringSplit(c);
					if (tokens.size() != 3)
						flag = false;
					try {
						if (tokens[0] == "q")
							break;
						id1 = stoi(tokens[0]);
						id2 = stoi(tokens[1]);
						*(restrParams[restrParams.size() - 1]) = stod(tokens[2]);
					}
					catch (exception) {
						std::cout << "Error: id of a point must be an integer, "
							"distance must be double" << std::endl;
						flag = false;
					}
				} while (!flag);

				if (tokens[0] == "q")
					break;
				if (core.searchID(id1)->object_type() != 1 || core.searchID(id2)->object_type() != 1) {
					cout << "It's not IDs of points" << endl;
					system("pause");
					break;
				}
				objId.push_back(id1);
				objId.push_back(id2);
				core.addRestriction(&objId, restrParams[restrParams.size() - 1], RT_P2PDIST, SOLVE);
			} break;
			case 'c': {
				system("cls");

				if (core.sizeListObj() < 3) {
					system("cls");
					outputAll(core);
					cout << endl;
					cout << "Not enough objects!" << endl;
					system("pause");
					break;
				}

				outputAll(core);
				unsigned id1, id2, id3;
				cout << "Write id of 3 points and distance" << endl;
				cout << "(q to cancel)" << endl;

				restrParams.push_back(new double);
				bool flag;
				do {
					flag = true;
					getline(cin, c);
					tokens = stringSplit(c);
					if (tokens.size() != 4)
						flag = false;
					try {
						if (tokens[0] == "q")
							break;
						id1 = stoi(tokens[0]);
						id2 = stoi(tokens[1]);
						id3 = stoi(tokens[2]);
						*(restrParams[restrParams.size() - 1]) = stod(tokens[3]);
					}
					catch (exception) {
						std::cout << "Error: id of a point and segment must be an integer, "
							"distance must be double" << std::endl;
						flag = false;
					}
				} while (!flag);

				if (tokens[0] == "q")
					break;
				if (core.searchID(id1)->object_type() != 1 || core.searchID(id2)->object_type() != 1 || core.searchID(id3)->object_type() != 1) {
					cout << "It's not IDs of points" << endl;
					system("pause");
					break;
				}
				objId.push_back(id1);
				objId.push_back(id2);
				objId.push_back(id3);
				core.addRestriction(&objId, restrParams[restrParams.size() - 1], RT_P2SDIST, SOLVE);
			} break;
			case 'd': {
				system("cls");

				if (core.sizeListObj() < 3) {
					system("cls");
					outputAll(core);
					cout << endl;
					cout << "Not enough objects!" << endl;
					system("pause");
					break;
				}

				outputAll(core);
				unsigned id1, id2, id3;
				cout << "Write id of 3 points and distance" << endl;
				cout << "(q to cancel)" << endl;

				restrParams.push_back(new double);
				bool flag;
				do {
					flag = true;
					getline(cin, c);
					tokens = stringSplit(c);
					if (tokens.size() != 4)
						flag = false;
					try {
						if (tokens[0] == "q")
							break;
						id1 = stoi(tokens[0]);
						id2 = stoi(tokens[1]);
						id3 = stoi(tokens[2]);
						*(restrParams[restrParams.size() - 1]) = stod(tokens[3]);
					}
					catch (exception) {
						std::cout << "Error: id of point must be an integer, "
							"distance must be double" << std::endl;
						flag = false;
					}
				} while (!flag);

				if (tokens[0] == "q")
					break;
				if (core.searchID(id1)->object_type() != 1 || core.searchID(id2)->object_type() != 1 || core.searchID(id3)->object_type() != 1) {
					cout << "It's not IDs of points" << endl;
					system("pause");
					break;
				}
				objId.push_back(id1);
				objId.push_back(id2);
				objId.push_back(id3);
				core.addRestriction(&objId, restrParams[restrParams.size() - 1], RT_P2SDISTEX, SOLVE);
			} break;
			case 'e': {
				system("cls");

				if (core.sizeListObj() < 6) {
					system("cls");
					outputAll(core);
					cout << endl;
					cout << "Not enough objects!" << endl;
					system("pause");
					break;
				}

				outputAll(core);
				int id1, id2;
				cout << "Write id of two segments and angle" << endl;
				cout << "(q to cancel)" << endl;

				restrParams.push_back(new double);
				bool flag;
				do {
					flag = true;
					getline(cin, c);
					tokens = stringSplit(c);
					if (tokens.size() != 3)
						flag = false;
					try {
						if (tokens[0] == "q")
							break;
						id1 = stoi(tokens[0]);
						id2 = stoi(tokens[1]);
						*(restrParams[restrParams.size() - 1]) = stod(tokens[2]);
					}
					catch (exception) {
						std::cout << "Error: id of segment must be an integer, "
							"angle must be in radians" << std::endl;
						flag = false;
					}
				} while (!flag);

				if (tokens[0] == "q")
					break;
				if (core.searchID(id1)->object_type() != 2 || core.searchID(id2)->object_type() != 2) {
					cout << "It's not IDs of segments" << endl;
					system("pause");
					break;
				}
				objId.push_back(id1);
				objId.push_back(id2);
				core.addRestriction(&objId, restrParams[restrParams.size() - 1], RT_S2SANGLE, SOLVE);
			} break;
			case 'f': {
				system("cls");

				if (core.sizeListObj() < 6) {
					system("cls");
					outputAll(core);
					cout << endl;
					cout << "Not enough objects!" << endl;
					system("pause");
					break;
				}

				outputAll(core);
				double d = 0;
				int id1, id2;

				cout << "Write id of two segments" << endl;
				cout << "(q to cancel)" << endl;

				restrParams.push_back(new double);
				bool flag;
				do {
					flag = true;
					getline(cin, c);
					tokens = stringSplit(c);
					if (tokens.size() != 2)
						flag = false;
					try {
						if (tokens[0] == "q")
							break;
						id1 = stoi(tokens[0]);
						id2 = stoi(tokens[1]);
					}
					catch (exception) {
						std::cout << "Error: id of segment must be an integer" << std::endl;
						flag = false;
					}
				} while (!flag);

				if (tokens[0] == "q")
					break;
				if (core.searchID(id1)->object_type() != 2 || core.searchID(id2)->object_type() != 2) {
					cout << "It's not IDs of segments" << endl;
					system("pause");
					break;
				}
				objId.push_back(id1);
				objId.push_back(id2);
				core.addRestriction(&objId, &d, RT_S2SEQUALS, SOLVE);
			} break;
			case 'g': {
				system("cls");

				if (core.sizeListObj() < 6) {
					system("cls");
					outputAll(core);
					cout << endl;
					cout << "Not enough objects!" << endl;
					system("pause");
					break;
				}

				outputAll(core);
				int id1, id2;
				double d = 0;
				cout << "Write id of two segments" << endl;
				cout << "(q to cancel)" << endl;

				restrParams.push_back(new double);
				bool flag;
				do {
					flag = true;
					getline(cin, c);
					tokens = stringSplit(c);
					if (tokens.size() != 2)
						flag = false;
					try {
						if (tokens[0] == "q")
							break;
						id1 = stoi(tokens[0]);
						id2 = stoi(tokens[1]);
					}
					catch (exception) {
						std::cout << "Error: id of segment must be an integer" << std::endl;
						flag = false;
					}
				} while (!flag);

				if (tokens[0] == "q")
					break;
				if (core.searchID(id1)->object_type() != 2 || core.searchID(id2)->object_type() != 2) {
					cout << "It's not IDs of segments" << endl;
					system("pause");
					break;
				}
				objId.push_back(id1);
				objId.push_back(id2);
				core.addRestriction(&objId, &d, RT_S2SPARAL, SOLVE);
			} break;
			case 'h': {
				system("cls");

				if (core.sizeListObj() < 6) {
					system("cls");
					outputAll(core);
					cout << endl;
					cout << "Not enough objects!" << endl;
					system("pause");
					break;
				}

				outputAll(core);
				int id1, id2;
				double d = 0;
				cout << "Write id of two segments" << endl;
				cout << "(q to cancel)" << endl;

				restrParams.push_back(new double);
				bool flag;
				do {
					flag = true;
					getline(cin, c);
					tokens = stringSplit(c);
					if (tokens.size() != 2)
						flag = false;
					try {
						if (tokens[0] == "q")
							break;
						id1 = stoi(tokens[0]);
						id2 = stoi(tokens[1]);
					}
					catch (exception) {
						std::cout << "Error: id of segment must be an integer" << std::endl;
						flag = false;
					}
				} while (!flag);

				if (tokens[0] == "q")
					break;
				if (core.searchID(id1)->object_type() != 2 || core.searchID(id2)->object_type() != 2) {
					cout << "It's not IDs of segments" << endl;
					system("pause");
					break;
				}
				objId.push_back(id1);
				objId.push_back(id2);
				core.addRestriction(&objId, &d, RT_S2SORTHO, SOLVE);
			} break;
			}
		} break;

		case 'c': {
			system("cls");
			outputAll(core);
			cout << endl;
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
						system("pause");
						SOLVE = Func();
					}

				}
				if (!fRunTimeLinkSuccess) {
					fFreeResult = FreeLibrary(hinstLib);
					cout << "Hook J: 404 not found" << endl;
					system("pause");
					return 0;
				}
			} break;
			case 'G': {
				fRunTimeLinkSuccess = FALSE;
				hinstLib = LoadLibrary(TEXT("dllGD.dll"));
				if (hinstLib != nullptr) {
					cout << "Lib Load" << endl;
					Func = (PROCFUN)GetProcAddress(hinstLib, "getMethod");

					if (nullptr != Func) {
						fRunTimeLinkSuccess = TRUE;
						cout << "O.K." << endl;
						system("pause");
						SOLVE = Func();
					}

				}
				if (!fRunTimeLinkSuccess) {
					fFreeResult = FreeLibrary(hinstLib);
					cout << "Grad D: 404 not found" << endl;
					system("pause");
					return 0;
				}
			} break;
			default: {
				cout << "Choose your side!" << endl;
			}
			}
		} break;

		case'd': {
			system("cls");
			string _resultfilename = "Batch.m";
			ofstream out(_resultfilename);
			out.close();
			MatlabRenderer matlab(_resultfilename, 10);
			matlab.drawSketch(core.getInfoObj());
			cout << "Your state is saved to .m file." << endl;
			system("pause");
		} break;
		
		case'*': {
			core.clearState();
		} break;

		case'l': {
			system("cls");
			outputAll(core);
			if (core.sizeListObj() != 0) {
				cout << endl << "Only initial state is supported." << endl;
				system("pause");
				break;
			}
			cout << endl;
			string input;
			cout << "Enter batch file" << endl;
			cin >> input;
			BatchProcessor newbatch(input, &core, "matlab");
			newbatch.generateCode();
			system("pause");
		} break;

		default: {
			cout << "Invalid command" << endl;
			system("pause");
		}
		}

	}

}

void Console::outputAll(Core &core)
{
	cout << "OBJECTS:" << endl;
	if (core.sizeListObj() == 0)
		cout << "	No objects yet." << endl;
	for (size_t i = 0; i < core.sizeListObj(); ++i) {
		Point * newp = 0; Circle *newc = 0; Segment * news = 0;
		switch (core.searchID(core.getObjIDs()[i])->object_type()) {
		case IsPoint: {
			newp = dynamic_cast<Point*>(core.searchID(core.getObjIDs()[i]));
			cout.precision(2);
			cout << setw(8);
			newp->isFixed() ? cout << "(fixed) " : cout << "";
			cout << setw(8) << "POINT ";
			cout << setw(3) << "ID: " << setw(2) << newp->showId();
			cout << setw(6) << "X: " << setw(8) << newp->getX();
			cout << setw(6) << "Y: " << setw(8) << newp->getY() << endl;
		} break;
		case IsSegment: {
			news = dynamic_cast<Segment*>(core.searchID(core.getObjIDs()[i]));
			cout.precision(2);
			cout << setw(8);
			news->isFixed() ? cout << "(fixed) " : cout << "";
			cout << setw(8) << "SEGMENT ";
			cout << setw(3) << "ID: " << setw(2) << news->showId();
			cout << setw(6) << news->getP1()->showId();
			cout << "-----" << news->getP2()->showId() << endl << endl;
		} break;
		case IsCircle: {
			newc = dynamic_cast<Circle*>(core.searchID(core.getObjIDs()[i]));
			cout.precision(2);
			cout << setw(8);
			Point t = newc->getCenter();
			newc->isFixed() ? cout << "(fixed) " : cout << "";
			cout << setw(8) << "CIRCLE ";
			cout << setw(3) << "ID: " << setw(2) << newc->showId();
			cout << setw(6) << "O: " << setw(8) << newc->getCenter().showId();
			cout << setw(6) << "R: " << setw(8) << newc->getRadius() << endl << endl;
		} break;
		}
	}
	cout << "RESTRICTIONS:" << endl;
	if (core.sizeListRestr() == 0)
		cout << "	No restrictions yet." << endl;
	for (size_t i = 0; i < core.sizeListRestr(); ++i) {
		BasicRestriction * restr;
		switch (core.searchIDRestr(core.getRestrIDs()[i])->get_type()) {

		case RT_P2PDIST: {
			restr = dynamic_cast<RestrP2PDIST*>(core.searchIDRestr(core.getRestrIDs()[i]));
			cout.precision(2);
			cout << setw(16) << "P2PDIST " << setw(3) << "ID: " << setw(2) << restr->showId();
			cout << setw(13) << "violation: " << setw(8) << restr->violation() << endl;
		} break;
		case RT_P2SDIST: {
			restr = dynamic_cast<RestrP2SDIST*>(core.searchIDRestr(core.getRestrIDs()[i]));
			cout.precision(2);
			cout << setw(16) << "P2SDIST " << setw(3) << "ID: " << setw(2) << restr->showId();
			cout << setw(13) << "violation: " << setw(8) << restr->violation() << endl;
		} break;
		case RT_P2SDISTEX: {
			restr = dynamic_cast<RestrP2SDISTEX*>(core.searchIDRestr(core.getRestrIDs()[i]));
			cout.precision(2);
			cout << setw(16) << "P2SDISTEX " << setw(3) << "ID: " << setw(2) << restr->showId();
			cout << setw(13) << "violation: " << setw(8) << restr->violation() << endl;
		} break;
		case RT_S2SANGLE: {
			restr = dynamic_cast<RestrS2SANGLE*>(core.searchIDRestr(core.getRestrIDs()[i]));
			cout.precision(2);
			cout << setw(16) << "S2SANGLE " << setw(3) << "ID: " << setw(2) << restr->showId();
			cout << setw(13) << "violation: " << setw(8) << restr->violation() << endl;
		} break;
		case RT_S2SORTHO: {
			restr = dynamic_cast<RestrS2SORTHO*>(core.searchIDRestr(core.getRestrIDs()[i]));
			cout.precision(2);
			cout << setw(16) << "S2SORTHO " << setw(3) << "ID: " << setw(2) << restr->showId();
			cout << setw(13) << "violation: " << setw(8) << restr->violation() << endl;
		} break;
		case RT_S2SPARAL: {
			restr = dynamic_cast<RestrS2SPARAL*>(core.searchIDRestr(core.getRestrIDs()[i]));
			cout.precision(2);
			cout << setw(16) << "S2SPARAL " << setw(3) << "ID: " << setw(2) << restr->showId();
			cout << setw(13) << "violation: " << setw(8) << restr->violation() << endl;
		} break;
		case RT_S2SEQUALS: {
			restr = dynamic_cast<RestrS2SEQUALS*>(core.searchIDRestr(core.getRestrIDs()[i]));
			cout.precision(2);
			cout << setw(16) << "S2SEQUALS " << setw(3) << "ID: " << setw(2) << restr->showId();
			cout << setw(13) << "violation: " << setw(8) << restr->violation() << endl;
		} break;
		}
	}
	core.ShowRestr();
}