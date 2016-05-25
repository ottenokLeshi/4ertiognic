#include <iostream>
#include <algorithm>
#include "MArray.h"
using namespace std;
/*struct COMPONENT {
	static int index;
	size_t Csize;
	Array < Array < double > > AMatrix;
};*/
template <class T> struct CELL {
	T _data;
	bool cnct;
};
template <class A> class MGraph { // unoriented graph 
private:
	size_t size;
	Array< Array < CELL < A > > > AMatrix; // Adjacency matrix
	Array < bool > used;
	//COMPONENT components;
	Array < double > comp;

public:

	MGraph(size_t SIZE) {
		size = SIZE;
		for (int i = 0; i < SIZE; ++i)
			used.push_back(0);
		for (int i = 0; i < SIZE; ++i)
			AMatrix.push_back(Array< CELL < A > >(SIZE));
	}
	void AddEgde(int from, int to) {
		if (AMatrix[from][to].cnct == 0) {
			AMatrix[from][to].cnct = 1;
			AMatrix[to][from].cnct = 1;
		}
	}

	void AddVert(size_t num) {
		CELL VAR;
		VAR._data = 0;
		VAR.cnct = 0;
		for (size_t i = 0; i <num; ++i) {
			AMatrix.push_back(Array < CELL < A > >(size + num));
			for (size_t j = 0; j <size; ++j)	AMatrix[j].push_back(VAR);
		}
	}

	bool _returnEdge(int from, int to) {
		if ((from >= size || from < 0) || (to<0 || to >= size)) return -1;
		return AMatrix[from][to].cnct;
	}

	size_t _returnSize() const { return size; }

	void const _showGRAPH() {
		std::cout << "Number of vertexes: " << size << std::endl;

		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j)
				if (_returnEdge(i, j))
					std::cout << i << " to " << j << " = " << _returnEdge(i, j) << std::endl;
	}
	void DFS(int V) { // DEPTH FIRST SEARCH
		used[V] = true;
		comp.push_back(V);
		int to = 0;
		for (size_t i = 0; i<size; ++i) {
			if (AMatrix[V][i].cnct) {
				to = i;
				if (!used[to])	DFS(to);
			}
		}
	}

	Array < double > Find_Next_Component() {
			while(comp.size() !=0)	comp.erase(0);
		int i = 0;
		while (used[i] && i<size) { ++i; }
		i -= 1;
		do {
			++i;
			if (!used[i])	DFS(i);

		} while (!used[i]);
			return comp;
	}
	~MGraph() {}
};
// TEST
/*int main() {
	size_t SIZE_V;
		cout << "SIZE: ";
	cin >> SIZE_V;
	MGraph < CELL<double> > Graph1(SIZE_V);
	Graph1.AddEgde(1, 3);
	Graph1.AddEgde(2, 4);
	Array < double > comp1 = Graph1.Find_Next_Component();
	Array < double > comp2 = Graph1.Find_Next_Component();
	Array < double > comp3 = Graph1.Find_Next_Component();

	for (int i = 0; i < comp1.size(); ++i) cout << comp1[i] << " ";
	cout << " First comp\n";
	for (int i = 0; i < comp2.size(); ++i) cout << comp2[i] << " ";
	cout << " Second comp\n";
	for (int i = 0; i < comp3.size(); ++i) cout << comp3[i] << " ";
	cout << " Third comp\n";

	Graph1._showGRAPH();
	system("pause");
	return 0;
}*/
