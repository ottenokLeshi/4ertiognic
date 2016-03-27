#include <iostream>
#include <cmath>
using namespace std;
/*
The Test for derivatives 
for restriction P2PDIST: F(x) = sqrt((x-2)^2+(y-2)^2), in (x0,y0) = (5,0)
*/
#include "..\..\include\Array.h"
#include "..\..\include\Solver.h"
int main() {
	const double delta = 0.0001;
	Array<double>  Y(2);
	Array<double>  X(2);
	X.set_el(0,5);
	Y = X;
	cout << "X_0 = " << X[0] << endl << "X_1 = " << X[1] << endl;
	Point p1(1, 1), p2(2, 2);
	double dist = 2;
	RestrP2PDIST D1(&p1,&p2,&dist);
	functi fun(&p1, &p2, &D1);
	cout << D1.violation();
	cout << endl << "Dif =" << diff(&fun, X)[0]/diff(&fun, X)[1] << endl;
	system("pause");
	return 0;
}
