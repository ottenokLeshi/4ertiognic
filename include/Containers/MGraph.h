#ifndef MGRAPH_H
#define MGRAPH_H
#include <iostream>
// Matrix graph naive implementation
using namespace std;
class MGraph { 
private:
	double **Graph;
	int numVert;
	bool _isOr; // not orientated  = 0 ; orientated  = 1
public:

	MGraph(int VERTEX, bool or): numVert(VERTEX), Graph(new double *[VERTEX]), _isOr(or){
		for (int i = 0; i < VERTEX; ++i) Graph[i] = new double[VERTEX];
		for (int i = 0; i < numVert; ++i) 
			for (int j = 0; j < numVert; ++j) 	Graph[i][j] = 0;
	}

	~MGraph() {
		for (int i = 0; i < numVert; ++i){
			delete Graph[i];
		}
		delete Graph;
	}

	int CVert() const {	return numVert;	}

	// for test
	void AddEges(int NUM) {
		if (NUM > numVert*(numVert - 1) / 2) return;
		for (int i = 0; i < NUM; ++i) {
			int F, T;
			cout << "(FROM , TO): ";
			cin >> F >> T;
			AddEdge(F, T);
		}
	}
	//
	void AddEdge(int F, int T){
		if ((F >= numVert || F < 0) || (T<0 || T>=numVert)) return;
		if (_isOr)	cin >> Graph[F][T];
		else { cin >> Graph[F][T]; Graph[T][F] = Graph[F][T];}
	}

	double QEdge(int F, int T) {
		if ((F >= numVert || F < 0) || (T<0 || T>=numVert)) return -1;
		return Graph[F][T];
	}

	void const showGr() {
		cout << "Number of vertex: " << numVert << endl;
		cout << "Is orientated: ";
		if (_isOr) cout << "Yes" << endl;
		else cout << "No" << endl;
		for (int i = 0; i < numVert; ++i) 
			for (int j = 0; j < numVert; ++j )	if (QEdge(i,j)) cout << i << " to " << j  << " = "<< QEdge(i, j) << endl;
	}
};
#endif
