#ifndef MY_SIMPLEX_H 
#define MY_SIMPLEX_H
#include <iostream>
#include "Array.h" 
#include "Solver.h"
#include <cmath>
//>>>>>>>> Nelder-Mead method Russ wiki
const int DIM = 2;
const double _EPS = 1e-3;
const double A= 1;
const double B = 0.5;
const double G = 2;

template<class T>void Swap(T &A, T&B) {
	T C;
	C = A;
	A = B;
	B = C;
}
class Vertex {
public: 
	double x, y;
	Vertex(): x(0),y(0) {}
	Vertex(double _x, double _y) : x(_x), y(_y) {}
	// Operators
	
	friend Vertex operator + (Vertex _x, Vertex _y) { return *(new Vertex(_x.x + _y.y, _x.y + _y.y)); }
	friend Vertex operator - (Vertex _x, Vertex _y) { return *(new Vertex(_x.x - _y.y, _x.y - _y.y)); }
	friend Vertex operator* (Vertex _x, Vertex _y) { return *(new Vertex(_x.x*_y.x, _x.y*_y.y)); }
	friend Vertex operator* (Vertex _x, double D) { return *(new Vertex(_x.x*D, _x.y*D)); }
	Vertex operator= ( const Vertex &_x) { x = _x.x; y = _x.y; return *this; }
	friend Vertex operator/ (Vertex _x, Vertex _y) { return *(new Vertex(_x.x/_y.x, _x.y/_y.y)); }
	friend Vertex operator/ (Vertex _x, double D) { return *(new Vertex(_x.x/D, _x.y/D)); }
 //	friend std::ostream& operator<< (std::ostream& oS, Vertex Ver) {oS << "x = " << x << endl << "y = " << endl; return oS;}
	friend double dist(Vertex X, Vertex Y) { return sqrt((X.x - Y.x)*(X.x - Y.x) + (X.y - Y.y)*(X.y - Y.y)); }
};
class Simplex {
public:
	Vertex V[DIM + 1]; // Array of Vertexs 
	Simplex(Vertex F[])	{for (int i = 0; i < DIM; ++i) V[i] = F[i];}
	bool Case(Simplex *A) {
		for (int i = 0; i < DIM; ++i)
			for (int j = 0; j < DIM; ++j)
				if (dist(A->V[i], A->V[j])>_EPS)
					return 0;
		return 1;
	}
	Array<double>& V_prep_sort(Simplex *S, functi *f) { // Preparation and Sorting 
		Array<double> *v_vect;
		for (int i = 0; i <= DIM; ++i) v_vect->add_elem((*f)(S->V[i]));
		for (int i = 1; i <= DIM; ++i) {
			for (int j = i; j >= 1; --j) {
				if ((*v_vect)[j-1] > (*v_vect)[j]){
					Swap(S->V[j - 1], S->V[j]);
					Swap(v_vect[j - 1], v_vect[j]);
				}
				}
			return *v_vect;
		}
		}
	double Solver_Nelder_Mead(functi *f){
			Vertex v1(1, 1), v2(4, 4), v3(7, 7);
			Vertex v_A[3];	v_A[0] = v1;	v_A[1] = v2;	v_A[2] = v3;
			Simplex *S = new Simplex(v_A);
			double func[DIM + 1]; // Array of function values
			double f_h = 0.0, f_g = 0.0, f_l = 0.0, f_r = 0.0, f_e = 0.0, f_s = 0.0, _hV=0;
			Vertex P_h, P_g, P_l, P_r, P_e, P_s, P_cen;
			bool _bF=0;
				while (!Case(S)) { 
					// Step 1
					for (int i = 0; i < DIM + 1;++i) func[i] = V_prep_sort(S, f)[i];
					f_h = func[DIM]; f_g = func[DIM - 1]; f_l = func[DIM - DIM];
					P_h = S->V[DIM]; P_g = S->V[DIM-1]; P_l = S->V[DIM-DIM];
					// Step 2: Center of Mass
					for (int i = 0; i < DIM; ++i) P_cen = P_cen + S->V[i]/DIM;
					// Step 3: Reflection
					P_r = P_cen*(1 + A) - P_h*A;
					f_r = (*f)(P_r);
					// Step 4: Ñomparison 					
					if (f_r < f_l) { // Extention
						P_e = P_r*G+P_cen*(1-G);
						f_e = (*f)(P_e);
						if (f_e >= f_r) P_h = P_r; 
						if (f_e < f_r) P_h = P_e; 
						break;
					}
					if ((f_l < f_r)& (f_r < f_g)) { P_h = P_r; break; }
						if ((f_g < f_r)& (f_r < f_h)) {
							Swap(P_h, P_r);	Swap(f_r,f_h);
							_bF = 1;
						}
				if (f_h < f_r) _bF = 1;
				if (_bF) {
						P_s = P_h*B + P_cen*(1 - B);
						f_s = (*f)(P_s);
						if (f_s < f_h) { P_h = P_s; break; }
						if (f_s > f_h) for (int i = 0; i <= DIM; ++i) S->V[i] = P_l + (S->V[i] - P_l) / 2;
						}
								}
				return f_l;
	}
};

#endif