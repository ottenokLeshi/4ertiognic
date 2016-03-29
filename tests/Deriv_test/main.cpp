#include <iostream>
#include <cmath>
using namespace std;
/*
The Test for derivatives 
for restriction P2PDIST: F(x) = sqrt((x-2)^2+(y-2)^2), in (x0,y0) = (5,0)
*/
#include "..\..\include\Array.h"
#include "..\..\include\Solver.h"
void  Test_Solver() {
	double dist = 0;
	double x_1 = 0, y_1 = 0;
	double x_2 = 0, y_2 = 0;
	Array<double> Z(2);
	cout << "Input point 1 (x y): "; cin >> x_1 >> y_1;
	cout << "Input Distance: "; cin >> dist;
	Point p1(x_1/2, x_2/2), p2(x_1, x_2);
	RestrP2PDIST D1(&p1, &p2, &dist);
	functi F(&p1, &p2, &D1);
	solver(&F, Z);
	p1.setX(Z[0]);
	p1.setY(Z[1]);
	cout << "Violation = " << D1.violation() << endl;
	cout << "X = " << Z[0] << endl << "Y = " << Z[1] << endl;
}
int main() {
	const double delta = 0.0001;
	Array<double>  Y(2);
	Array<double>  X(2);
	Array<double> Z(2);
	Z.set_el(0, 3);
	Z.set_el(1, 2);
	X.set_el(0,5);
	Y = X;
	X.set_el(1, 1);
	X.set_el(0, 1);
	cout << "X_0 = " << X[0] << endl << "X_1 = " << X[1] << endl;
	Point p1(4, 3), p2(70, 10);
	double dist = 2;
	RestrP2PDIST D1(&p1,&p2,&dist);
	functi fun(&p1, &p2, &D1);
	cout << endl << "Dif =" << diff(&fun, X)[0]/diff(&fun, X)[1] << endl;
	Test_Solver(); // Test: Solver
	system("pause");
	return 0;
}
