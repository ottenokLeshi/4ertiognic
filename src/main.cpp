#include "core.h"
#include <iostream>
#include "batch_processor.h"
#include "console.h"
using namespace std;


int main(int argc, char* argv[]) {
	string input;
	cout << "Write batchfile:  " << endl;
		cin >> input;
		Core core;
		BatchProcessor newbatch(input, &core, "matlab");
		newbatch.generateCode();
		core.ShowRestr();
		system("pause");
	return 0;
}