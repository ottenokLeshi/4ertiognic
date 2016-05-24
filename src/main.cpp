#include "core.h"
#include <iostream>
#include "batch_processor.h"

using namespace std;



int main(int argc,char* argv[]) {
	string input;
	if (argc > 1)
		input = std::string(argv[1]);
	else{
		cout << "Enter batchfile ";
		cin >> input;
	}
	Core core;
	BatchProcessor newbatch(input, &core, "matlab");
	newbatch.generateCode();
	core.ShowRestr();
	return 0;
}