
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
	core.ShowRestr();
	return true;
}



int main() {
	BatchProcessor_test();
	system("pause");
	return 0;
}