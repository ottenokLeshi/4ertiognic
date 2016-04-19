#include "batch_processor.h"

bool BatchProcessor::generateCode() {
	fstream fin, fout;
	fin.open(_batchfilename);
	if (!fin.is_open()) return false;
	char type;

	while (!fin.eof()) {
		fin >> type;
		Array<double> par;
		switch (type) {

		case 'p': // add point
			double x, y;
			fin >> x >> y;
			par.push_back(x); par.push_back(y);
			_core->addObject(par, IsPoint);
			break;

		case 's':
			double x1, y1, x2, y2;
			fin >> x1 >> y1 >> x2 >> y2;
			par.push_back(x1); par.push_back(y1);
			par.push_back(x2); par.push_back(y2);
			_core->addObject(par, IsSegment);
			break;

		case 'c':
			double x3, y3, r;
			fin >> x3 >> y3 >> r;
			par.push_back(x3); par.push_back(y3);
			par.push_back(r);
			_core->addObject(par, IsCircle);
			break;

		case 'r':
			string rest = "   ";
			fin >> rest[0] >> rest[1] >> rest[2];
			List<unsigned>* idObj = new List<unsigned>;

			if (rest == "fix") {
				unsigned count, id;
				fin >> count;
				for (size_t i = 0;i < count; i++) {
					fin >> id;
					idObj->push_back(id);
				}
				_core->addRestriction(idObj, 0, RT_FIX);
				delete idObj;
			}

			if (rest == "dpp") {
				unsigned id1, id2;
				double par;
				fin >> id1 >> id2 >> par;
				idObj->push_back(id1);idObj->push_back(id2);
				_core->addRestriction(idObj, &par, RT_P2PDIST);
				delete idObj;
			}

			if (rest == "dpl") {
				unsigned id1, id2, id3;
				double par;
				fin >> id1 >> id2 >> id3 >> par;
				idObj->push_back(id1);idObj->push_back(id2); idObj->push_back(id3);
				_core->addRestriction(idObj, &par, RT_P2SDIST);
				delete idObj;
			}

			if (rest == "dps") {
				unsigned id1, id2, id3;
				double par;
				fin >> id1 >> id2 >> id3 >> par;
				idObj->push_back(id1);idObj->push_back(id2); idObj->push_back(id3);
				_core->addRestriction(idObj, &par, RT_P2SDISTEX);
				delete idObj;
			}

			if (rest == "ass") {
				unsigned id1, id2;
				double par = 0;
				fin >> id1 >> id2;
				idObj->push_back(id1);idObj->push_back(id2);
				_core->addRestriction(idObj, &par, RT_S2SANGLE);
				delete idObj;
			}

			if (rest == "oss") {
				unsigned id1, id2;
				double par = 0;
				fin >> id1 >> id2;
				idObj->push_back(id1);idObj->push_back(id2);
				_core->addRestriction(idObj, &par, RT_S2SORTHO);
				delete idObj;
			}

			if (rest == "pss") {
				unsigned id1, id2;
				double par = 0;
				fin >> id1 >> id2;
				idObj->push_back(id1);idObj->push_back(id2);
				_core->addRestriction(idObj, &par, RT_S2SPARAL);
				delete idObj;
			}

			if (rest == "ess") {
				unsigned id1, id2;
				double par = 0;
				fin >> id1 >> id2;
				idObj->push_back(id1);idObj->push_back(id2);
				_core->addRestriction(idObj, &par, RT_S2SEQUALS);
				delete idObj;
			}
		}
		char str[255];
		fin.getline(str, 255);
	}
	fin.close();

	//generate code to gui
	//(mb it should create enums GUI_types)
	if (_gui == "matlab") {
		MatlabRenderer matlab(_resultfilename, _core, 10);
		matlab.drawSketch();
	}
	/*
	... other gui
	*/

	return true;
}