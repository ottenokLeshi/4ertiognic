// circle fixed => a =const, b = const, R = const, A = const, B = const, C = variable 
// circle (x - a)^2+(y-b)^2=R^2
// line Ax+By+C=0
#include <iostream>
#include <cmath>
using namespace std;
void quad_eq(double a, double b, double c, double &x_1, double &x_2) {
	if (a == 0 && b != 0) { (x_1) = -c / b; (x_2) = -c / b;}
	if (a == 0 && b == 0 && c == 0) { cout << "INF"; return ; }
	if ((a == 0 && b == 0 && c != 0) || ((b*b - 4 * a*c) < 0)) { cout << "Nope"; return; }
	x_1 = (-1)*(-b + sqrt(b*b - 4 * a*c)) / (2 * a);
	x_2 = (-1)*(-b - sqrt(b*b - 4 * a*c)) / (2 * a);
	return;
}
void Seg_to_Circ(double a,double b,double A,double B,double R, double &C_1, double &C_2) {
	if(B!=0) quad_eq(1,-2*(A*a+B*b),(A*A+B*B)*(a*a+b*b-R)-(A*b-B*a)*(A*b-B*a),C_1,C_2);
	else quad_eq(1,-4*a,2*A*(a*a+b*b-R)-2*A*b*b,C_1,C_2);
}
int main() {
	double A = 0, B = 0, C_1 = 0,C_2 = 0, b = 0, a = 0, R = 0;
	cout << "Input coeff of circle (x - a)^2+(y-b)^2=R^2 (a b R^2): ";
	cin >> a >> b >> R;
	cout << "Input coeff of line Ax+By+C=0 (A B): ";
	cin >> A >> B;
	if( (A == 0 && B == 0) || R==0){cout << "Error"; return 0;}
	Seg_to_Circ(a,b,A,B,R,C_1,C_2);
	cout << "C_1 =" << C_1 << endl;
	cout << "C_2 =" << C_2 << endl;
	system("pause");
	return 0;

}
