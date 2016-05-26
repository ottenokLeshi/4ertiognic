#include "objects.h"
#include <iostream>
#include "HJSolver.h"
#include <algorithm> // min
const double EPS = 1e-7;
using namespace std;

extern "C" __declspec(dllexport) ISolver* getMethod() {
	return new CHJSolver;
}

double explore(MyFunction *f, Array <double> &x, Array <double> &h) {
	Array <double> curr = x;

	double minf = (*f)(curr);
	double ftmp;

	for (size_t i = 0; i < curr.size(); ++i) {
		curr[i] = x[i] + h[i];
		ftmp = (*f)(curr);
		if (ftmp < minf) {
			minf = ftmp;
		}
		else {
			h[i] = -h[i];
			curr[i] = x[i] + h[i];
			ftmp = (*f)(curr);
			if (ftmp < minf) {
				minf = ftmp;
			}
			else {
				curr[i] = x[i];
			}
		}
	}
	x = curr;
	return minf;
}

	
	//for (size_t i = 0; i < res.size(); ++i) {
	//	Array <double> v1, v2;
	//	double result = x[i];
	//	// search nearby minimum
	//	v1 = res;
	//	v1[i] = res[i] + h;
	//	v2 = res;
	//	v2[i] = res[i] - h;
	//	// if f(v1) < f(v2)
	//	if ((*f)(v1)<(*f)(v2)) {
	//		// if f(v1) < f(x)
	//		if ((*f)(v1) < (*f)(x)) {
	//			result = res[i] + h;
	//		}
	//	}
	//	else {
	//		if ((*f)(v2) < (*f)(x)) {
	//			result = res[i] - h;
	//		}
	//	}
	//	res[i] = result;
	//}
	//return res;
bool CHJSolver::solve(MyFunction *f, Array <double*> &x) {
	Array <double> xb;
	Array <double> oldx;
	Array <double> h0(x.size());
	Array <double> newx;
	double stepsize = 0.7; // parametr;
	double rpar = 0.7;
	double tmp;

	for (size_t i = 0; i < x.size(); ++i) {
		xb.push_back(*x[i]);
		oldx.push_back(*x[i]);
		newx.push_back(*x[i]);
	}
	for (size_t i = 0; i < x.size(); ++i) {
		if (abs(*x[i]) < EPS) {
			h0[i] = rpar;
		}
		else {
			h0[i] = rpar * abs(*x[i]);
		}
	}
	double oldf = (*f)(newx);
	double newf = oldf;
	int maxiter = 1000;
	int iters = 0;
	while (stepsize > EPS && newf > EPS)
	{
		newx = oldx;
		// cout << newx[0] << "-";
		newf = explore(f, newx, h0);
		// cout << newx[0] << endl;

		/*cout << "newf: " << newf << endl;
		for (size_t i = 0; i < x.size(); i++)
			cout << newx[i] << " ";
		cout << endl;
		system("pause");*/

		bool flag = 1;
		iters = 0;
		while (newf < oldf && newf > EPS && flag == 1 && iters < maxiter) {
			//cout << "im here" << endl;
			//cout << "newf: " << newf << endl;
			//cout << iters++ << endl;
			iters++;
			for (size_t i = 0; i < x.size(); ++i) {
				if (newx[i] <= oldx[i])
					h0[i] = -abs(h0[i]);
				else

					h0[i] = abs(h0[i]);

				tmp = oldx[i];
				oldx[i] = newx[i];
				newx[i] = 2 * newx[i] - tmp;
			}
			oldf = newf;
			newf = explore(f, newx, h0);

			if (oldf <= newf)
				break;

			flag = 0;
			for (size_t i = 0; i < x.size(); ++i) {
				if (0.5 * abs(h0[i]) < abs(newx[i] - oldx[i])) {
					//cout << "flag ((" << endl;
					flag = 1;
					break;
				}
			}
		}

		if (stepsize >= EPS && oldf <= newf) {
			stepsize *= rpar;
			for (size_t i = 0; i < x.size(); ++i)
				h0[i] *= rpar;
		}	
	}

	if ((*f)(oldx) > 0.1) {
		//std::cout << "..." << std::endl;
		//(*f)(xe);
		return 0;
	}
	for (size_t i = 0; i < x.size(); ++i)
		*x[i] = oldx[i];
	//cout << "Result f(x): " << (*f)(oldx) << endl;
	return 1;
}


//
//
//bool CHJSolver::solve(MyFunction *f, Array <double*> &x) {
//	Array <double> x0;
//	for (size_t i = 0; i < x.size(); ++i)
//		x0.push_back(*x[i]);
//	//Array <double> xe;
//	//for (size_t i = 0; i < x.size(); ++i)
//		//xe.push_back(*x[i]);
//	Array <double> x0new = x0;
//	Array <double> x1 = x0;
//	Array <double> cur = x0;
//	double h = 1;
//
//	bool flag = 1;
//
//	x0new = explore(f, x0, h);
//	while (flag) {
//		if (h < EPS || abs((*f)(x0)) < EPS) {
//			std::cout << "f < EPS!!!!" << std::endl;
//			system("pause");
//			flag = 0;
//			break;
//		}
//		std::cout << (*f)(x0new) << std::endl;
//		if ((*f)(x0new) < (*f)(x0)) {
//			// pattern search
//			std::cout << "f(x0new) < f(x0)" << std::endl;
//			if (abs((*f)(x0new) - (*f)(x0)) < EPS) {
//				h = 1;
//			}
//
//			for (size_t i = 0; i < x0new.size(); ++i) {
//				x1[i] = x0[i] + 2 * (x0new[i] - x0[i]);
//			}
//			cur = explore(f, x1, h);
//			if ((*f)(cur) < (*f)(x0new)) {
//				x0 = x0new;
//				x0new = cur;
//			}
//			else {
//				x0 = x0new;
//				x0new = explore(f, x0, h);
//			}
//		}
//		else {
//			if (h < EPS || abs((*f)(x0)) < EPS) {
//				//if (h < EPS) std::cout << "solve exit: h < EPS" << std::endl;
//				//if (abs((*f)(x0)) < EPS) std::cout << "solve exit: f < EPS" << std::endl;
//				//system("pause");
//				flag = 0;
//				break;
//			}
//			else {
//				h = h / 2;
//				//std::cout << "decreasing step.." << std::endl;
//				x0new = explore(f, x0, h);
//				//std::cout << "1" << std::endl;
//				//system("pause");
//			}
//		}
//	}
//
//	if ((*f)(x0) > 0.01) {
//		std::cout << "..." << std::endl;
//		//(*f)(xe);
//		return 0;
//	}
//
//	for (size_t i = 0; i < x.size(); ++i)	*x[i] = x0[i];
//	return 1;
//}


void CHJSolver::getSolution(Array<double*> &x, MyFunction *f) {solve(f, x);}

