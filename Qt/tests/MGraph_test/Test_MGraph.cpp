#include <iostream>
#include "MGraph.h"
using namespace std;
int main() {
	int N, NEg = 0;
	bool K = 0;
	cout << "Enter the number of (Vertex / Orient) *Orient(0 or 1): "; 	cin >> N; cin >> K;
	cout << "Enter the number of edges less than  N*(N-1)/2 : "; cin >> NEg;
		MGraph  t_Graph(N, K);
		t_Graph.AddEges(NEg);
		t_Graph.showGr();
		system("pause");
}