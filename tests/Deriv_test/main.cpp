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
	CSol A;
	double dist = 0;
	double x_1 = 0, y_1 = 0;
	double x_2 = 0, y_2 = 0;
	Array<double> Z(2),K(2);
	cout << "Input point 1 (x y): "; cin >> x_1 >> y_1;
	cout << "Input Distance: "; cin >> dist;
	Point p1(0, 0), p2(x_1, y_1);
	RestrP2PDIST D1(&p1, &p2, &dist);
	cout << "Test_viol = " << D1.violation() << endl;
	functi F(&p1, &p2, &D1);
	cout << "Test_viol2 = " << F(Z) << endl; 
	// Naive implement
	A.Solve(&F, Z);
	p1.setX(Z[0]);
	p1.setY(Z[1]);
	cout << endl <<"Naive implement: (X,Y) = (" << Z[0] << "," << Z[1] << ")" << endl;
	cout << "NI: Violation : " << D1.violation() << endl;
	// Gradient  descent *(The accuracy of the gradient descent depends on the compiler)
	A.Solve_2(&F, K);
	p1.setX(K[0]);
	p1.setY(K[1]);
	cout << "Gradeint descent: (X,Y) = (" << K[0] << "," << K[1] << ")" << endl;
	cout << "GD: Violation : " << D1.violation() << endl;
}
int main() {
	CDer B;
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
	cout << endl << "Dif =" << B.diff(&fun, X)[0]/B.diff(&fun, X)[1] << endl;
	Test_Solver(); // Test: Solver
	system("pause");
	return 0;
}
