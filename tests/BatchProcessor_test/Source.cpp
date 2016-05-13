
#include "core.h"
#include <iostream>
#include "batch_processor.h"

using namespace std;

typedef ISolver* (_cdecl *PROCFUN)(void);

bool BatchProcessor_test() {
	string input, output;
	cout << "Enter batchfile ";
	cin >> input;
	Core core;
	BatchProcessor newbatch(input, &core, "matlab");
	newbatch.generateCode();
	return true;
}



int main() {
	ISolver* SOLVE;
	HINSTANCE hinstLib;
	PROCFUN Func;
	BOOL fFreeResult, fRunTimeLinkSuccess;

	fRunTimeLinkSuccess = FALSE;
	hinstLib = LoadLibrary(TEXT("GDdll.dll"));
	//if (hinstLib != nullptr) {
	cout << "Lib Load" << endl;
	Func = (PROCFUN)GetProcAddress(hinstLib, "getMethod");

	//if (nullptr != Func)
	//{
	fRunTimeLinkSuccess = TRUE;
	//cout << "O.K." << endl;
	SOLVE = Func();
	//}

	//}
	//if (!fRunTimeLinkSuccess) {
	fFreeResult = FreeLibrary(hinstLib);
	//cout << "404 not found" << endl;
	//}

	//BatchProcessor_test();
	Core _Core;
	List<unsigned>* id = new List<unsigned>;
	List<unsigned>* id1 = new List<unsigned>;
	id->push_back(1);
	id->push_back(2);
	id1->push_back(1);
	Array<double> a, b;
	double* anus = new double(0);
	a.push_back(1);
	a.push_back(2);
	b.push_back(3);
	b.push_back(3);
	_Core.addObject(a, IsPoint);
	_Core.addObject(b, IsPoint);
	_Core.addRestriction(id, anus, RT_FIX, SOLVE);
	_Core.ShowFixed();
	cout << endl;
	_Core.addRestriction(id1, anus, RT_UNFIX, SOLVE);
	_Core.ShowFixed();
	system("Pause");

	return 0;
}