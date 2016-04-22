#include <iostream>
#include "Debug\Solver.h"
using namespace std;

int main(){  

	CSol Apolo;
	
	// >>>>>>>>>> S2S ANGLE
	double sparams[8];
		Point _S1p1(&sparams[0], &sparams[1]), _S1p2(&sparams[2], &sparams[3]);
		Point _S2p1(&sparams[4], &sparams[5]), _S2p2(&sparams[6], &sparams[7]);
		Segment S1(&_S1p1, &_S1p2);
		Segment S2(&_S2p1, &_S2p2);
		S1.fix(true); // FIXED
		double angle = 3.1415926535;
		cout << "Angle of segments: 180 " << endl <<"An angle of 180 degrees" << endl;
		RestrS2SANGLE S2S(&S1, &S2, &angle);

	Array<double*> spparam;	
		spparam.push_back(&sparams[0]);
		spparam.push_back(&sparams[1]);
		spparam.push_back(&sparams[2]);
		spparam.push_back(&sparams[3]);
		spparam.push_back(&sparams[4]);
		spparam.push_back(&sparams[5]);
		spparam.push_back(&sparams[6]);
		spparam.push_back(&sparams[7]);

	Array <double> snewpara;

	MyFunction f2(spparam);
		f2.addRestr(&S2S);
		snewpara.push_back(0);
		snewpara.push_back(-5);
		snewpara.push_back(5);
		snewpara.push_back(0);
		snewpara.push_back(0);
		snewpara.push_back(2);
		snewpara.push_back(2);
		snewpara.push_back(0);

		Apolo.GradDescent(&f2, snewpara);
	// >>>>>>> END S2S


	// >>>>>>>>>> P2P DISTANCE
		double params[4];
		Point p1(&params[0], &params[1]), p2(&params[2], &params[3]);
		double distance = 2;
		RestrP2PDIST r1(&p1, &p2, &distance);
		std::cout <<endl << "Point to Point" << endl <<"Distance: " << distance<< std::endl;

		Array<double*> pparam;
		pparam.push_back(&params[0]);
		pparam.push_back(&params[1]);
		pparam.push_back(&params[2]);
		pparam.push_back(&params[3]);

		MyFunction f1(pparam);
		f1.addRestr(&r1);
		Array<double> newpara;
		newpara.push_back(1);
		newpara.push_back(2);
		newpara.push_back(3);
		newpara.push_back(4);

		Apolo.GradDescent(&f1, newpara);
	// END P2P
	

	cin.get();
//	Apolo.GradDescent(&f1,newpara);

	return 0;
}
