#include <iostream>
#include "HJSolver.h"
#include "RestrP2PDIST.h"
#include "RestrS2SANGLE.h"
using namespace std;

int GraphPrimitive::static_id = 0;
const double EPS = 1e-05;

bool P2PDISTtest(CHJSolver *solv) {
	Array<double> result;
	// creating primitives
	double params[8];
	Point p1(&params[0], &params[1]);
	Point p2(&params[2], &params[3]);
	Point p3(&params[4], &params[5]);
	Point p4(&params[6], &params[7]);

	// creating restrictions
	double dist = 2;
	double dist1 = 3;
	double dist2 = 6;
	RestrP2PDIST r1(&p1, &p2, &dist);
	RestrP2PDIST r2(&p2, &p3, &dist1);
	RestrP2PDIST r3(&p3, &p4, &dist2);
	p1.fix(1);

	// creating function params
	Array<double*> pparam;
	for (size_t i = 0; i < 8; ++i) {
		pparam.push_back(&params[i]);
	}

	// adding restrictions to function
	MyFunction f1(pparam);
	f1.addRestr(&r1);
	f1.addRestr(&r2);
	f1.addRestr(&r3);

	// state
	Array<double> newpara;
	newpara.push_back(1);
	newpara.push_back(2);
	newpara.push_back(12);
	newpara.push_back(12);
	newpara.push_back(5);
	newpara.push_back(5);
	newpara.push_back(8);
	newpara.push_back(7);

	solv->solve(&f1, newpara);
	solv->getSolution(result);

	if (f1(newpara) < EPS) return 1;
	else return 0;
}


bool S2SAngletest(CHJSolver *solv) {
	Array<double> result;
	// creating primitives & restrictions
	double sparams[8];
	Point S1p1(&sparams[0], &sparams[1]);
	Point S1p2(&sparams[2], &sparams[3]);
	Point S2p1(&sparams[4], &sparams[5]);
	Point S2p2(&sparams[6], &sparams[7]);
	Segment S1(&_S1p1, &_S1p2);
	Segment S2(&_S2p1, &_S2p2);
	S1.fix(true); // FIXED
	double angle = 3.1415926535;
	RestrS2SANGLE S2S(&S1, &S2, &angle);

	Array<double*> spparam;
	for (size_t i = 0; i < 8; ++i) {
		spparam.push_back(&sparams[i]);
	}

	MyFunction f2(spparam);
	f2.addRestr(&S2S);

	Array <double> snewpara;
	snewpara.push_back(0);
	snewpara.push_back(-5);
	snewpara.push_back(5);
	snewpara.push_back(0);
	snewpara.push_back(0);
	snewpara.push_back(2);
	snewpara.push_back(2);
	snewpara.push_back(0);

	solv->solve(&f2, snewpara);
	solv->getSolution(result);

	if (f2(snewpara) < EPS) return 1;
	else return 0;
}



int main() { 
	CHJSolver So;
	cout << "P2PDISTtest: " << P2PDISTtest(&So) << endl;
	cout << "S2SANGLEtest: " << S2SAngletest(&So) << endl;

	cin.get();

	return 0;
}