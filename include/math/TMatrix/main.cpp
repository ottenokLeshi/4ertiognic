#include <iostream>
using namespace std;
#include "matrix.h"
int main(){
	Matrix <double> A(2,2);
	A.Matrix_eye();
	A.Show();
	cout << A.det();
	return 0;
}
