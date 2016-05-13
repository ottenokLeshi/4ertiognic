#include "batch_processor.h"

typedef ISolver* (_cdecl *PROCFUN)(void);

bool BatchProcessor::generateCode() {
	fstream fin;
	fin.open(_batchfilename);
	if (!fin.is_open()) return false;
	char type;
	ISolver* SOLVE;
	while (!fin.eof()) {
		fin >> type;
		Array<double> objParams; // parameters to create objects
		double x = 0, y = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 1, x3 = 2, y3 = 2, r = 1;

		List<unsigned> objId;
		Array< double* > restrParams; // parameters to create restrictions

		HINSTANCE hinstLib;
		PROCFUN Func;
		BOOL fFreeResult, fRunTimeLinkSuccess;

		switch (type) {
		
		case 'G':
			fRunTimeLinkSuccess = FALSE;
			hinstLib = LoadLibrary(TEXT("GDdll.dll"));
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
				return 0;
			}
			break;
		case 'H':
			fRunTimeLinkSuccess = FALSE;
				hinstLib = LoadLibrary(TEXT("HJdll.dll"));
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
				cout  << "Hook J: 404 not found" << endl;
				system("pause");
				return 0;
			}
			break;
		case 'p': // add point
				fin >> x >> y;	
				objParams.push_back(x);
				objParams.push_back(y);
				_core->addObject(objParams, IsPoint);
			break;

		case 'P': // add point
			objParams.push_back(x);
			objParams.push_back(y);
			_core->addObject(objParams, IsPoint);
			break;

		case 's':
			fin >> x1 >> y1 >> x2 >> y2;
			objParams.push_back(x1);
			objParams.push_back(y1);
			objParams.push_back(x2);
			objParams.push_back(y2);
			_core->addObject(objParams, IsSegment);
			break;

		case 'S':
			objParams.push_back(x1);
			objParams.push_back(y1);
			objParams.push_back(x2);
			objParams.push_back(y2);
			_core->addObject(objParams, IsSegment);
			break;

		case 'c':
				fin >> x3 >> y3 >> r;
				objParams.push_back(x3);
				objParams.push_back(y3);
				objParams.push_back(r);
			_core->addObject(objParams, IsCircle);
			break;

		case 'C':
			objParams.push_back(x3);
			objParams.push_back(y3);
			objParams.push_back(r);
			_core->addObject(objParams, IsCircle);
			break;

		case 'r':
			string rest = "   ";
			fin >> rest[0] >> rest[1] >> rest[2];

			objId.deleteAll(); // every restriction needs empty objId

			if (rest == "fix") {
				string fix = "   ";
				double zero = 0;
				fin >> fix[0] >> fix[1] >> fix[2];

				if (fix == "obj") {
					unsigned count, id;
					fin >> count;
					for (size_t i = 0;i < count; i++) {
						fin >> id;
						objId.push_back(id);
					}
					_core->addRestriction(&objId, &zero, RT_FIX, SOLVE);
				}

				if (fix == "all") {
					for (unsigned int i = 0; i < _core->sizeListObj(); i++)
						objId.push_back(i);
					_core->addRestriction(&objId, &zero, RT_FIX, SOLVE);
				}
			}


			if (rest == "dpp") {
				unsigned id1, id2;
				restrParams.push_back(new double);
				fin >> id1 >> id2 >> *(restrParams[restrParams.size() - 1]);
				objId.push_back(id1);
				objId.push_back(id2);
				_core->addRestriction(&objId, restrParams[restrParams.size() - 1], RT_P2PDIST, SOLVE);
				
			}

			if (rest == "dpl") {
				unsigned id1, id2, id3;
				restrParams.push_back(new double);
				fin >> id1 >> id2 >> id3 >> *(restrParams[restrParams.size() - 1]);
				objId.push_back(id1);
				objId.push_back(id2);
				objId.push_back(id3);
				_core->addRestriction(&objId, restrParams[restrParams.size() - 1], RT_P2SDIST, SOLVE);
				
			}

			if (rest == "dps") {
				unsigned id1, id2, id3;
				restrParams.push_back(new double);
				fin >> id1 >> id2 >> id3 >> *(restrParams[restrParams.size() - 1]);
				objId.push_back(id1);
				objId.push_back(id2);
				objId.push_back(id3);
				_core->addRestriction(&objId, restrParams[restrParams.size() - 1], RT_P2SDISTEX, SOLVE);
				
			}

			if (rest == "ass") {
				unsigned id1, id2;
				restrParams.push_back(new double);
				fin >> id1 >> id2 >> *(restrParams[restrParams.size() - 1]);
				objId.push_back(id1);
				objId.push_back(id2);
				_core->addRestriction(&objId, restrParams[restrParams.size() - 1], RT_S2SANGLE, SOLVE);
				
			}

			if (rest == "oss") {
				unsigned id1, id2;
				restrParams.push_back(new double(0));
				fin >> id1 >> id2;
				objId.push_back(id1);
				objId.push_back(id2);
				_core->addRestriction(&objId, restrParams[restrParams.size() - 1], RT_S2SORTHO, SOLVE);
				
			}

			if (rest == "pss") {
				unsigned id1, id2;
				restrParams.push_back(new double(0));
				fin >> id1 >> id2;
				objId.push_back(id1);
				objId.push_back(id2);
				_core->addRestriction(&objId, restrParams[restrParams.size() - 1], RT_S2SPARAL, SOLVE);
			}

			if (rest == "ess") {
				unsigned id1, id2;
				restrParams.push_back(new double(0));
				fin >> id1 >> id2;
				objId.push_back(id1);
				objId.push_back(id2);
				_core->addRestriction(&objId, restrParams[restrParams.size() - 1], RT_S2SEQUALS, SOLVE);
			}
		}
		char str[255];
		fin.getline(str, 255);
	}
	fin.close();
	size_t i = _batchfilename.size() - 1;
	for (; i != 0;i--)
		if (_batchfilename[i] == '.') break;
	string _resultfilename = "";
	for (size_t t = 0; t < i;t++)
		_resultfilename += _batchfilename[t];
	_resultfilename += ".m";
	ofstream out(_resultfilename);
	out.close();
	//generate code to gui
	//(mb it should create enums GUI_types)
	if (_gui == "matlab") {
		MatlabRenderer matlab(_resultfilename, 10);
		matlab.drawSketch( _core->getInfoObj());
	}
	/*
	... other gui
	*/

	return true;
}
