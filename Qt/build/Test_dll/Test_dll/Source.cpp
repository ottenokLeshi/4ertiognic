#include <iostream>
#include <cmath>
#include <stdio.h> 
#include <windows.h> 
#include "Function.h"
#include "ISolver.h"
#include "RestrP2PDIST.h"
#include "graphPrimitive.h"

int BasicRestriction::static_id = 1;
int GraphPrimitive::static_id = 0;
using namespace std;

typedef ISolver* (_cdecl *PROCFUN)(void);
int main() {
	int Lol;
	HINSTANCE hinstLib;
	PROCFUN F;
	BOOL fFreeResult, fRunTimeLinkSuccess = FALSE;
	cout << "Hooke - Jeeves or Gradient Descent (1 or 0): "; cin >> Lol; cout << endl;
	if (!Lol) {
		hinstLib = LoadLibrary(TEXT("dllGD.dll"));
	}
	if (Lol) {
		hinstLib = LoadLibrary(TEXT("HJdll.dll"));
	}
	if (hinstLib != nullptr) {
		cout << "Lib Load" << endl;
		F = (PROCFUN)GetProcAddress(hinstLib, "getMethod");

		if (nullptr != F)
		{
			fRunTimeLinkSuccess = TRUE;
			cout << "O.K." << endl;
		}

	}
	if (!fRunTimeLinkSuccess) {
		fFreeResult = FreeLibrary(hinstLib);
		cout << "404 not found" << endl;
		system("pause");
		return 0;
	}
	cin.get();



	// >>>>>>>>>> P2P DISTANCE
	double params[4];
	for (size_t i = 0; i < 4; i++)
	{
		params[i] = i + 1;
	}
	Point p1(&params[0], &params[1]), p2(&params[2], &params[3]);
	double distance = 2;
	RestrP2PDIST r1(&p1, &p2, &distance);
	std::cout << endl << "Point to Point" << endl << "Distance: " << distance << std::endl;

	Array<double*> pparam;
	pparam.push_back(&params[0]);
	pparam.push_back(&params[1]);
	pparam.push_back(&params[2]);
	pparam.push_back(&params[3]);

	MyFunction f1(pparam);
	f1.addRestr(&r1);
	Array<double> newpara;
	newpara.push_back(1);
	newpara.push_back(2);
	newpara.push_back(3);
	newpara.push_back(4);
	// END P2P

	ISolver *solve;
	solve = (*F)();
	solve->getSolution(pparam, &f1);

	for (size_t i = 0; i < 4; i++)
	{
		cout << "coord: " << *pparam[i] << endl;
	}
	cin.get();
	return 0;
}