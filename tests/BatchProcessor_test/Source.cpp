#include "core.h"
#include <iostream>
#include "batch_processor.h"
#define EPS 0.00000001

using namespace std;

typedef ISolver* (_cdecl *PROCFUN)(void);

bool BatchProcessor_test() {
	string input, output;
	cout << "Enter batchfile ";
	cin >> input;
	Core core;
	BatchProcessor newbatch(input, &core, "matlab");
	newbatch.generateCode();
	core.ShowRestr();
	return true;
}

double p2pd(double* X) {
	return X[4] - sqrt((X[2] - X[0])*(X[2] - X[0]) + (X[3] - X[1])*(X[3] - X[1]));
}
void testP2PD() {
	const int N = 5;
	double distance = 10.5;
	Point A(1, 1), B(3, 4);
	RestrP2PDIST R(&A, &B, &distance);
	double X[N] = { 1,1,3,4,10.5 };
	for (size_t i = 1; i <= N; i++) {
		double f1 = p2pd(X);
		X[i - 1] += EPS;
		double f2 = p2pd(X);

		cout << R.diff(i) << "    " << (f2 - f1) / EPS << endl;
	}
}

long double p2sdex(long double* X) {
	long double x1 = X[0], x2 = X[2], y1 = X[1], y2 = X[3], xt = X[4], yt = X[5];
	long double vec1x = x1 - xt, vec1y = y1 - yt, vec2x = x2 - xt, vec2y = y2 - yt, segx = x1 - x2, segy = x2 - y2;
	if ((vec1x*segx + vec1y*segy)*(vec2x*segx + vec2y*segy) < 0) {
		if (x1 == x2) {
			long double k = (x1 - x2) / (y1 - y2), b = x2 - k*y2;
			return X[6] - abs((k*yt - xt + b) / sqrt(k*k + 1));
		}
		long double k = (y1 - y2) / (x1 - x2), b = y2 - k*x2;
		return X[6] - abs((k*xt - yt + b) / sqrt(k*k + 1));
	}
	else {
		if (sqrt(vec1x*vec1x + vec1y*vec1y) < sqrt(vec2x*vec2x + vec2y*vec2y))
			return X[6] - sqrt(vec1x*vec1x + vec1y*vec1y);
		else
			return X[6] - sqrt(vec2x*vec2x + vec2y*vec2y);

	}
}
void testP2SDEX() {
	const int N = 7;
	double distance = 10.5;
	Point A(1, 1), P1(500, 600), P2(100, 33);
	Segment S(&P1, &P2);
	RestrP2SDISTEX R(&P1, &P2, &A, &distance);
	long double X[N] = { 500,600,100,33,1,1,10.5 };
	for (size_t i = 1; i <= N; i++) {
		long double f1 = p2sdex(X);
		X[i - 1] += EPS;
		long double f2 = p2sdex(X);

		cout << R.diff(i) << "    " << (f2 - f1) / EPS << endl;
	}
}

long double p2sd(double* X) {
	double a = X[1] - X[3];
	double b = X[2] - X[0];
	double c = X[0]*X[3] - X[2]*X[1];
	double len = sqrt((X[2] - X[0])*(X[2] - X[0]) + (X[3] - X[1])*(X[3] - X[1]));
	return X[6] - abs(a*X[4] + b*X[5] + c) / len;
}
void testP2SD() {
	const int N = 7;
	double distance = 10.5;
	Point A(1, 1), P1(5,6), P2(100,33);
	Segment S(&P1, &P2);
	RestrP2SDIST R(&P1, &P2, &A, &distance);
	double X[N] = { 5,6,100,33,1,1,10.5 };
	for (size_t i = 1; i <= N; i++) {
		double f1 = p2sd(X);
		X[i - 1] += EPS;
		double f2 = p2sd(X);

		cout << R.diff(i) << "    " << (f2 - f1) / EPS << endl;
	}
}


long double s2sa(double* X) {
	double x1 = X[2] - X[0];
	double y1 = X[3] - X[1];
	double x2 = X[6] - X[4];
	double y2 = X[7] - X[5];
	double _angle = ((x1*x2 + y1*y2) / (sqrt((double)x1*x1 + y1*y1)*sqrt((double)x2*x2 + y2*y2)));
	if (_angle < -1) _angle = -1;
	else if (_angle > 1) _angle = 1;
	return X[8] - acos(_angle);
}
void testS2SA() {
	const int N = 9;
	double angle = 3.1415/6;
	Point P1(5, 6), P2(100, 33), P3(543, 54), P4(89, 1200);
	Segment S1(&P1, &P2), S2(&P3,&P4);
	RestrS2SANGLE R(&S1, &S2, &angle);
	double X[N] = { 5, 6, 100, 33, 543, 54, 89, 1200, angle };
	for (size_t i = 1; i <= N; i++) {
		double f1 = s2sa(X);
		X[i - 1] += EPS;
		double f2 = s2sa(X);

		cout << R.diff(i) << "    " << (f2 - f1) / EPS << endl;
	}
}

long double s2so(double* X) {
	double x1 = X[2] - X[0];
	double y1 = X[3] - X[1];
	double x2 = X[6] - X[4];
	double y2 = X[7] - X[5];
	double _angle = ((x1*x2 + y1*y2) / (sqrt((double)x1*x1 + y1*y1)*sqrt((double)x2*x2 + y2*y2)));
	if (_angle < -1) _angle = -1;
	else if (_angle > 1) _angle = 1;
	return 1.57079632 - acos(_angle);
}
void testS2SO() {
	const int N = 8;
	Point P1(5, 6), P2(100, 33), P3(543, 54), P4(89, 1200);
	Segment S1(&P1, &P2), S2(&P3, &P4);
	RestrS2SORTHO R(&S1, &S2);
	double X[N] = { 5, 6, 100, 33, 543, 54, 89, 1200 };
	for (size_t i = 1; i <= N; i++) {
		double f1 = s2so(X);
		X[i - 1] += EPS;
		double f2 = s2so(X);

		cout << R.diff(i) << "    " << (f2 - f1) / EPS << endl;
	}
}
int main() {
	//BatchProcessor_test();
	//testP2PD();	//correct
	//testP2SD();	//correct
	//testP2SDEX();	//correct
	//testS2SA();	//correct, ortho and paral must be either
	testS2SO();
	system("pause");
	return 0;
}