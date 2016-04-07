#ifndef _MATLAB_RENDERER_H
#define _MATLAB_RENDERER_H
#include <iostream>
#include <fstream> 
#include <string>
#include "../include/core.h"

using namespace std;
class MatlabRenderer {
public:
	bool drawPrimitive(string filename,Primitive_Type type, Array<double> parametrs, size_t markersize) {
		fstream f;
		f.open(filename);
		if (!f.is_open()) return false;
		long file_size;
		f.seekg(0, ios::end);
		file_size = f.tellg(); // checking empty file
		if (file_size == 0) {
			string namefunc = "";
			size_t t = 0;
			for (t = filename.size();t != 0;t--)
				if (filename[t - 1] == '/') break;
			for (size_t i = t+1;i <= filename.size() - 2;i++) namefunc = namefunc + filename[i - 1];
			f << "function res = " << namefunc << "()" << endl;
			f << "res = 0" << endl;
			f << "figure; hold on" << endl;
		}

		switch (type) {

		case IsPoint:
			if (parametrs.size() == 2) {
				double x = parametrs[0], y = parametrs[1];
				f << "plot([" << x << " "<< x << "],[" <<y<< 
					" " << y<< "], 'LineWidth', 2, 'Marker', '.', 'MarkerSize', " << markersize << ")" << endl;
			}
			break;

		case IsSegment:
			if (parametrs.size() == 4) {
				double x1 = parametrs[0], y1 = parametrs[1], x2 = parametrs[2], y2 = parametrs[3];
				f << "plot([" << x1 << " " << x2 << "],[" << y1 <<
					" " << y2 << "], 'LineWidth', 2, 'Marker', '.', 'MarkerSize', " << markersize << ")" << endl;
			}
			break;

		case IsCircle:
			if (parametrs.size() == 3) {
				double x = parametrs[0], y = parametrs[1], rad = parametrs[2];
				f << "plot(" << x << " + " << rad << " * cos(0:0.001 : 2 * pi), " << y << " + " << rad <<
					" * sin(0:0.001 : 2 * pi), 'LineWidth', 2, 'Marker', '.', 'MarkerSize', "<< markersize <<")" << endl;
			}
			break;
		}

		f.close();
		return true;
	}

};
#endif 