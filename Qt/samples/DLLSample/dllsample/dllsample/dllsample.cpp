// dllsample.cpp: ���������� ���������������� ������� ��� ���������� DLL.
//

#include "stdafx.h"
#include "dllsample.h"
#include "GDSolver.h"

__declspec(dllexport) ISolver* getSolver(){
	return new CGradDescSol;
}
