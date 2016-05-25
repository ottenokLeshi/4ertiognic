#include "core.h"
#include <iostream>
#include "batch_processor.h"
#include "console.h"
using namespace std;


int main(int argc,char* argv[]) {
	string input;
	if (argc > 1) {
		input = std::string(argv[1]);
		Core core;
		BatchProcessor newbatch(input, &core, "matlab");
		newbatch.generateCode();
		core.ShowRestr();
		system("pause");
	}
	else {
		Console console;
		console.screen();
	}
	return 0;
}