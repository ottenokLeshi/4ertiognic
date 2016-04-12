
#include "../include/core.h"
#include <iostream>
#include "../include/batch_processor.h"

using namespace std;

bool BatchProcessor_test() {
	string input, output;
	cout << "Enter batchfile ";
	cin >> input;
	cout << "Enter resultfile ";
	cin >> output;
	Core core;
	BatchProcessor newbatch(input, output, &core, "matlab");
	newbatch.generateCode();
	return true;
}



int main() {
	BatchProcessor_test();
	
	return 0;
}