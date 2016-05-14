#include <iostream>
#include "core.h"

double const PI = 3.141592;
using namespace std;


int main() {

	// test for RestrS2SANGLE
	Point t1(1, 0), t2(6, 4), t3(0, 8), t4(0, 9);
	Segment s1(&t1, &t2), s2(&t3, &t4);
	double an = 90 * PI / 180;
	RestrS2SANGLE res(&s1, &s2, &an);
	cout << "ANGLE = " << an * 180 / PI << endl;
	for (size_t i = 1; i < 10;i++)
		cout << i << ' ' << res.diff(i) << ' ' << res.diff(i) * 180 / PI << endl;

	// test for RestrP2PDIST
	Point p1(0, 1), p2(0, 9);
	double dist = 10;
	RestrP2PDIST res2(&p1, &p2, &dist);
	cout << "DISTANCE = " << dist << endl;
	for (size_t i = 1; i < 6;i++)
		cout << i << ' ' << res2.diff(i) << endl;


	// test for RestrS2SANGLE
	Point u1(0, 1), u2(0, 10), u3(3, 2);
	double dist1 = 4;
	RestrP2SDIST res3(&u1, &u2, &u3, &dist1);
	cout << "DISTANCE = " << dist1 << endl;
	for (size_t i = 1; i < 8;i++)
		cout << i << ' ' << res3.diff(i) << endl;


	system("pause");
	return 0;
}