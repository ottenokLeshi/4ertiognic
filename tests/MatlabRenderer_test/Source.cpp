
#include "../include/core.h"
#include <iostream>
#include "../include/matlab_renderer.h"
using namespace std;

bool test_MatlabRenderer(string filename) {
	size_t markersize;
	MatlabRenderer mat(filename);
	size_t type;
	Array<double> parametrs;
	double par;
	cout << "Primitive type is Point(1)/Segment(2)/Circle(3)";
	cin >> type;
	cout << endl;
	switch (type) {
	case 1: 
		cout << "Parametrs are "<<endl;
		for (size_t i = 0;i < 2;i++) {
			cin >> par;
			parametrs.push_back(par);
		}
		cout << "Marker`s size is " << endl;
		cin >> markersize;
		if (mat.drawPrimitive(IsPoint, parametrs, markersize))
			return true;
		return false;
		break;

	case 2:
		cout << "Parametrs are " << endl;
		for (size_t i = 0;i < 4;i++) {
			cin >> par;
			parametrs.push_back(par);
		}
		cout << "Marker`s size is " << endl;
		cin >> markersize;
		if (mat.drawPrimitive(IsSegment, parametrs, markersize))
			return true;
		return false;
		break;

	case 3:
		cout << "Parametrs are " << endl;
		for (size_t i = 0;i < 3;i++) {
			cin >> par;
			parametrs.push_back(par);
		}
		cout << "Marker`s size is " << endl;
		cin >> markersize;
		if (mat.drawPrimitive(IsCircle, parametrs, markersize))
			return true;
		return false;
		break;
	}
}


int main() {
	size_t times;
	cout << "How many objects do u want to add?  :)";
	cin >> times; cout << endl;
	string filename;
	cout << "File`s name is " << endl;
	cin >> filename;cout << endl;
	for (size_t t = 0;t < times;t++) 
	test_MatlabRenderer(filename);
	return 0;
}