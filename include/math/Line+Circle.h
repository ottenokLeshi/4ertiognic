// circle fixed => a =const, b = const, R = const, A = const, B = const, C = variable 
// circle (x - a)^2+(y-b)^2=R^2
// line Ax+By+C=0.
#ifndef LINE_CIRCLE_H
#define LINE_CIRCLE_H
#include <iostream>
using namespace std;
void SqEq(double a, double b, double c, double *x_1, double *x_2) {
	if (a == 0 && b != 0) { (*x_1) = -c / b; (*x_2) = -c / b;}
	if (a == 0 && b == 0 && c == 0) { cout << "INF"; return ; }
	if ((a == 0 && b == 0 && c != 0) || ((b*b - 4 * a*c) < 0)) { cout << "Nope"; return; }
	(*x_1) = (-1)*(-b + sqrt(b*b - 4 * a*c)) / (2 * a);
	(*x_2) = (-1)*(-b - sqrt(b*b - 4 * a*c)) / (2 * a);
}
void PtoC(double a,double b,double A,double B,double R, double *C_1, double *C_2) {
	SqEq(4 * A*A / (B*B*B*B) - 4 / (B*B), -8 * a*A / B + 8 * A*A*b / (B*B*B) + 8 * b / B, 4 * a*a + 4 * A*A*b*b / B - 8 * a*A*b / B - 4 * a*a - 4 * b*b - 4 * R,C_1,C_2);
}
#endif
