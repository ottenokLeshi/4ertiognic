#ifndef _BASE_RESTRICTIONS_H_
#define _BASE_RESTRICTIONS_H_
#include "objects.h"

class restriction {
public:
	void Point_fix(Point P) {
		if (P.isFixed() != 1) P.fix(1);
	}

	void Point_connection(Point P1, Point P2) {
		Segment(P1, P2);
	}

	void Segment_fix(Segment S) {
		if (S.isFixed() != 1) S.fix(1);
	}

	void Segment_equal(Segment S1, Segment S2) {
		if (S1.getLength() != S2.getLength()) {
			//add calculation of the S2(t2) location
		}
	}

	void Segment_parall(Segment S1, Segment S2) {
		if () {
			//add calculation of the S2(t2) location
			//angel return (1) if true
		}
	}

	void Segment_perpen(Segment S1, Segment S2) {
		if () {
			//add calculation of the S2(t2) location
			//angel return () if true
		}
	}

	void Segment_intersect(Segment S1, Segment S2) {//how to choose the common point??

	}

	void Segment_intersect(Segment S1, Segment S2, Point P) {//common point is P

	}

	void Segment_angel(Segment S1, Segment S2, double a) {
		if (Angle(S1, S2) - a < eps) {
			//add calculation of the S2(t2) location
		}
	}
	void Point_distance_Segment(Segment S, Point P) {

	}
};
#endif _BASE_RESTRICTIONS_H_

