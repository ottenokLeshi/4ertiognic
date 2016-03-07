#ifndef REFLECT_H
#define REFLECT_H
#include "Gauss_method.h"
void Reflection(double& xR,double& yR,double x, double y, double A, double B, double C){
	// Line that perpendicular source line
	double newC = -A*y+B*x, newA = -B, newB = A;
	//
	int result = 0;
	vector < double > answ;
	vector< vector<double> > Lacross(2,vector <double>(3));
	// Geniusly, isn't it?
	Lacross[0][0] = A;
	Lacross[0][1] = B;
	Lacross[0][2] = C;
	Lacross[1][0] = newA;
	Lacross[1][1] = newB;
	Lacross[1][2] = newC;
	// 
	result = Gauss_metod(Lacross,answ);
	xR = -2*answ[0]-x;
	yR = -2*answ[1]-y; 
}
#endif
