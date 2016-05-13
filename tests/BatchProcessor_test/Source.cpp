
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
	//BatchProcessor_test();

	Core _Core;
	_Core.getSOLVE(1);
	system("pause");
	return 0;
}