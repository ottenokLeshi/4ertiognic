#include "batch_processor.h"
#include "string_extensions.h"

typedef ISolver* (_cdecl *PROCFUN)(void);

bool BatchProcessor::generateCode() {
	fstream fin;
	fin.open(_batchfilename);
	if (!fin.is_open()) return false;
	fin.seekg(0, ios::end);
	long file_size = (long)fin.tellg();
	if (file_size == 0) {
		std::cout << "Batch file is empty." << std:: endl;
		system("pause");
		exit(1);
	}
	fin.seekg(0, ios::beg);
	char type;
	ISolver* SOLVE = nullptr;
	string command; // every line in batch.txt
	Array<string> tokens; // splitted command

	while (!fin.eof()) {
		std::getline(fin, command);
		if (command.length() == 0)
			continue;
		tokens = stringSplit(command);
		if (tokens[0][0] == '/' && tokens[0][1] == '/')
			continue;
		Array<double> objParams; // parameters to create objects
		double x = 0, y = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 1, x3 = 2, y3 = 2, r = 1;

		List<unsigned> objId;

		Array< double* > restrParams; // parameters to create restrictions

		HINSTANCE hinstLib;
		PROCFUN Func;
		BOOL fFreeResult, fRunTimeLinkSuccess;

		if (tokens[0].length() != 1) {
			std::cout << "Error while parsing batch:" << std::endl;
			std::cout << "   " << command << std::endl;
			std::cout << "Type of operation must be one symbol" << std::endl;
			system("pause");
			exit(1);
		}
		type = tokens[0][0];

		switch (type) {
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
		} break;
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
		} break;

		case 'p': {
			try {
				x = stod(tokens[1]);
				y = stod(tokens[2]);
			}
			catch (exception) {
				std::cout << "Error while parsing batch:" << std::endl;
				std::cout << "   " << command << std::endl;
				std::cout << "Point arguments must be 2 doubles" << std::endl;
				system("pause");
				exit(1);
			}
			objParams.push_back(x);
			objParams.push_back(y);
			_core->addObject(objParams, IsPoint);
		} break;

		case 'P': {
			objParams.push_back(x);
			objParams.push_back(y);
			_core->addObject(objParams, IsPoint);
		} break;

		case 's': {
			try {
				x1 = stod(tokens[1]);
				y1 = stod(tokens[2]);
				x2 = stod(tokens[3]);
				y2 = stod(tokens[4]);
			}
			catch (exception) {
				std::cout << "Error while parsing batch:" << std::endl;
				std::cout << "   " << command << std::endl;
				std::cout << "Segment arguments must be 4 doubles" << std::endl;
				system("pause");
				exit(1);
			}
			objParams.push_back(x1);
			objParams.push_back(y1);
			objParams.push_back(x2);
			objParams.push_back(y2);
			_core->addObject(objParams, IsSegment);
		} break;

		case 'S': {
			objParams.push_back(x1);
			objParams.push_back(y1);
			objParams.push_back(x2);
			objParams.push_back(y2);
			_core->addObject(objParams, IsSegment);
		} break;

		case 'c': {
			try {
				x3 = stod(tokens[1]);
				y3 = stod(tokens[2]);
				r = stod(tokens[3]);
			}
			catch (exception) {
				std::cout << "Error while parsing batch:" << std::endl;
				std::cout << "   " << command << std::endl;
				std::cout << "Circle arguments must be 3 doubles" << std::endl;
				system("pause");
				exit(1);
			}
			objParams.push_back(x3);
			objParams.push_back(y3);
			objParams.push_back(r);
			_core->addObject(objParams, IsCircle);
		} break;

		case 'C': {
			objParams.push_back(x3);
			objParams.push_back(y3);
			objParams.push_back(r);
			_core->addObject(objParams, IsCircle);
		} break;

		case 'r': {
			string rest = tokens[1];
			objId.deleteAll(); // every restriction needs empty objId

			if (rest == "fix") {
				string fix = tokens[2];
				double zero = 0;

				if (fix == "obj") {
					unsigned id, count;
					try {
						count = stoi(tokens[3]);
					}
					catch (exception) {
						std::cout << "Error while parsing batch:" << std::endl;
						std::cout << "   " << command << std::endl;
						std::cout << "Count of objects must be an integer" << std::endl;
						system("pause");
						exit(1);
					}

					for (size_t i = 0; i < count; i++) {
						try {
							id = stoi(tokens[i+4]);
						}
						catch (exception) {
							std::cout << "Error while parsing batch:" << std::endl;
							std::cout << "   " << command << std::endl;
							std::cout << "ID of object must be an integer" << std::endl;
							system("pause");
							exit(1);
						}

						objId.push_back(id);
					}
					_core->addRestriction(&objId, &zero, RT_FIX, SOLVE);
				}

				else if (fix == "all") {
					for (size_t i = 1; i <= _core->sizeListObj(); i++)
						objId.push_back(i);
					_core->addRestriction(&objId, &zero, RT_FIX, SOLVE);
				}

				else {
					std::cout << "Error while parsing batch:" << std::endl;
					std::cout << "   " << command << std::endl;
					std::cout << "Fix argument must be 'obj' or 'all'" << std::endl;
					system("pause");
					exit(1);
				}
			}


			if (rest == "dpp") {
				unsigned id1, id2;
				restrParams.push_back(new double);

				try {
					id1 = stoi(tokens[2]);
					id2 = stoi(tokens[3]);
					*(restrParams[restrParams.size() - 1]) = stod(tokens[4]);
				}
				catch (exception) {
					std::cout << "Error while parsing batch:" << std::endl;
					std::cout << "   " << command << std::endl;
					std::cout << "ID of objects(2) must be an integer, distance must be a double" << std::endl;
					system("pause");
					exit(1);
				}

				objId.push_back(id1);
				objId.push_back(id2);
				_core->addRestriction(&objId, restrParams[restrParams.size() - 1], RT_P2PDIST, SOLVE);
			}

			if (rest == "dpl") {
				unsigned id1, id2, id3;
				restrParams.push_back(new double);

				try {
					id1 = stoi(tokens[2]);
					id2 = stoi(tokens[3]);
					id3 = stoi(tokens[4]);
					*(restrParams[restrParams.size() - 1]) = stod(tokens[5]);
				}
				catch (exception) {
					std::cout << "Error while parsing batch:" << std::endl;
					std::cout << "   " << command << std::endl;
					std::cout << "ID of objects(3) must be an integer, distance must be a double" << std::endl;
					system("pause");
					exit(1);
				}

				objId.push_back(id1);
				objId.push_back(id2);
				objId.push_back(id3);
				_core->addRestriction(&objId, restrParams[restrParams.size() - 1], RT_P2SDIST, SOLVE);

			}

			if (rest == "dps") {
				unsigned id1, id2, id3;
				restrParams.push_back(new double);

				try {
					id1 = stoi(tokens[2]);
					id2 = stoi(tokens[3]);
					id3 = stoi(tokens[4]);
					*(restrParams[restrParams.size() - 1]) = stod(tokens[5]);
				}
				catch (exception) {
					std::cout << "Error while parsing batch:" << std::endl;
					std::cout << "   " << command << std::endl;
					std::cout << "ID of objects(3) must be an integer, distance must be a double" << std::endl;
					system("pause");
					exit(1);
				}

				objId.push_back(id1);
				objId.push_back(id2);
				objId.push_back(id3);
				_core->addRestriction(&objId, restrParams[restrParams.size() - 1], RT_P2SDISTEX, SOLVE);

			}

			if (rest == "ass") {
				unsigned id1, id2;
				restrParams.push_back(new double);

				try {
					id1 = stoi(tokens[2]);
					id2 = stoi(tokens[3]);
					*(restrParams[restrParams.size() - 1]) = stod(tokens[4]);
					if (stod(tokens[4]) > 3.14) {
						std::cout << "Warning:" << std::endl;
						std::cout << "   " << command << std::endl;
						std::cout << "Angle should be in radians, from 0 to 3.14" << endl;
						system("pause");
					}
				}
				catch (exception) {
					std::cout << "Error while parsing batch:" << std::endl;
					std::cout << "   " << command << std::endl;
					std::cout << "ID of objects(2) must be an integer, distance must be a double" << std::endl;
					system("pause");
					exit(1);
				}

				objId.push_back(id1);
				objId.push_back(id2);
				_core->addRestriction(&objId, restrParams[restrParams.size() - 1], RT_S2SANGLE, SOLVE);

			}

			if (rest == "oss") {
				unsigned id1, id2;
				restrParams.push_back(new double(0));

				try {
					id1 = stoi(tokens[2]);
					id2 = stoi(tokens[3]);
				}
				catch (exception) {
					std::cout << "Error while parsing batch:" << std::endl;
					std::cout << "   " << command << std::endl;
					std::cout << "ID of objects(2) must be an integer" << std::endl;
					system("pause");
					exit(1);
				}

				objId.push_back(id1);
				objId.push_back(id2);
				_core->addRestriction(&objId, restrParams[restrParams.size() - 1], RT_S2SORTHO, SOLVE);

			}

			if (rest == "pss") {
				unsigned id1, id2;
				restrParams.push_back(new double(0));

				try {
					id1 = stoi(tokens[2]);
					id2 = stoi(tokens[3]);
				}
				catch (exception) {
					std::cout << "Error while parsing batch:" << std::endl;
					std::cout << "   " << command << std::endl;
					std::cout << "ID of objects(2) must be an integer" << std::endl;
					system("pause");
					exit(1);
				}

				objId.push_back(id1);
				objId.push_back(id2);
				_core->addRestriction(&objId, restrParams[restrParams.size() - 1], RT_S2SPARAL, SOLVE);
			}

			if (rest == "ess") {
				unsigned id1, id2;
				restrParams.push_back(new double(0));

				try {
					id1 = stoi(tokens[2]);
					id2 = stoi(tokens[3]);
				}
				catch (exception) {
					std::cout << "Error while parsing batch:" << std::endl;
					std::cout << "   " << command << std::endl;
					std::cout << "ID of objects(2) must be an integer" << std::endl;
					system("pause");
					exit(1);
				}

				objId.push_back(id1);
				objId.push_back(id2);
				_core->addRestriction(&objId, restrParams[restrParams.size() - 1], RT_S2SEQUALS, SOLVE);
			}
		} break;
		}
	}

	fin.close();
	size_t i = _batchfilename.size() - 1;
	for (; i != 0; i--)
		if (_batchfilename[i] == '.') break;
	string _resultfilename = "";
	for (size_t t = 0; t < i; t++)
		_resultfilename += _batchfilename[t];
	_resultfilename += ".m";
	ofstream out(_resultfilename);
	out.close();
	//generate code to gui
	//(mb it should create enums GUI_types)
	if (_gui == "matlab") {
		MatlabRenderer matlab(_resultfilename, 10);
		matlab.drawSketch(_core->getInfoObj());
	}
	/*
	... other gui
	*/

	return true;
}
