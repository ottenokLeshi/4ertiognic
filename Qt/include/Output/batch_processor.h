#ifndef _BATCH_PROCESSOR_H
#define _BATCH_PROCESSOR_H
#include <fstream>
#include <string>
#include <iostream>
#include "core.h"
#include "matlab_renderer.h"
using namespace std;

class BatchProcessor {
	string _batchfilename;
	Core *_core;
	string _gui;
public:
	BatchProcessor(string batchfilename,  Core *core, string gui)
		: _batchfilename(batchfilename),  _core(core), _gui(gui) {}

	~BatchProcessor() {}

	bool generateCode();
	
};
#endif