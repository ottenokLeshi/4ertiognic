#ifndef MATRIX_H
#define MATRIX_H 
#include <iostream>
using namespace std;
template < typename T > class Matrix{
public:
		Matrix(size_t nrows, size_t ncols): R(nrows),C(ncols) // Constructor
		{
		Mat = new T *[nrows];
		for (size_t i =0; i< nrows; ++i) Mat[i] = new T [ncols];
		};
		~Matrix(){ // Destructor
			for(size_t i =0; i < R;++i) delete[] Mat[i];
			delete[] Mat;}; // T
		size_t numrows() const{return R;};
		size_t numcols() const{return C;}; 
		void setElem(size_t nrow, size_t ncol, T var); 
		void Matrix_eye(); 
		Matrix transpose(); 
		// Matrix
		Matrix operator +(const Matrix &m); 
		Matrix operator *(const Matrix<T> &m);			
		Matrix operator -(const Matrix &m); 
		// Scalar
		Matrix operator *(const double K); 
		void Show();
		Matrix& operator =(Matrix &m);
		T det() const;
		Matrix inv();
 
	T **Mat;
	private:	
	size_t R;
	size_t C;	
};
/////////////////////////
template <typename T> Matrix<T> Matrix<T>::inv() {
	for (int k = 0; k < R*C; ++k) {
			for (int i = 0; i < R; ++i)
				for (int j = 0; j < C; ++j) 
				{

				}
	}
}
template <typename T> void Matrix<T>::Matrix_eye() {
	size_t ncols = C;
	size_t nrows = R;
	for (size_t i = 0; i< nrows; ++i)
		for (size_t j = 0; j< ncols; ++j) {
			if (i == j) Mat[i][j] = 1;
			else Mat[i][j] = 0;
		}
}
template <typename T> void Matrix<T>::Show() {
	int K = static_cast<int>(R);
	int K1 = static_cast<int>(C);
	for (int i = 0; i < K; ++i) {
		for (int j = 0; j < K1; ++j) {
			cout << Mat[i][j];
		}
		cout << endl;
	}return;}
template <typename T> Matrix<T> Matrix<T>::operator +(const Matrix &m) {
	Matrix <T> varM;
	for (size_t i = 0; i< R; ++i)
		for (size_t j = 0; j< C; ++j) {
			varM.Mat[i][j] = m.Mat[i][j] + Mat[i][j];
		}
	return varM;
};
template <typename T> T Matrix<T>::det() const{ // PROBLEM
		Matrix<T> VarM(R,C);
		double sum = 0;
		int Sign = 1;
		int subi = 0, subj = 0;
		if (C == 2) return(Mat[0][0] * Mat[1][1] - Mat[0][1] * Mat[1][0]);
		else{ 
			for (size_t i = 0; i < C; ++i) { // String for divising
				subi = 0;
				for (size_t j = 1; j < C; ++j) { // string
					subj = 0;
					for (size_t k = 0; k < C; ++k) { // coloumn
						if (k == i)
						{
							continue;
						}
						VarM.Mat[subi][subj] = Mat[j][k];
						subj++;
					}
					subi++;
				}
				if (C % 2) Sign = -1;
				else Sign = 1;
				sum = sum + Sign*Mat[0][C]* VarM.det();
			}
		}
		return sum;
	}
template <typename T> Matrix<T>& Matrix<T>:: operator =(Matrix<T> &m){ 
	for(size_t i = 0; i< R;++i)
		for(size_t j = 0; j<C; ++j)
			Mat[i][j] = m.Mat[i][j];
	return *this;
} 
template <typename T> Matrix<T> Matrix<T>::operator -(const Matrix<T> &m){
	Matrix varM(R,C);
	for (size_t i = 0; i< R;++i)
		for (size_t j =0; j< C; ++j){
			varM.Mat[i][j] = m.Mat[i][j] - Mat[i][j];
		}
		return varM;
}
template <typename T> Matrix<T> Matrix<T>:: operator *(const double K){
	Matrix varM(R,C);
	for (size_t i = 0; i< R;++i)
		for (size_t j =0; j< C; ++j){
			Mat[i][j] = K*Mat[i][j];
		}
		return varM;
}
template <typename T> void Matrix<T>::setElem(size_t nrow, size_t ncol, T var){
	Mat[nrow][ncol] = var;
}
template <typename T> Matrix<T> Matrix<T>::transpose(){
	T var;
	for(size_t i =0; i< R; ++i)
		for(size_t j =0; j< C; ++j){
			var = Mat[i][j];
			Mat[i][j]=Mat[j][i];
			Mat[j][i] = var;
		}
}
template <typename T> Matrix<T> Matrix<T>::operator *(const Matrix &m){
	Matrix<T> var(R, m.C);
	for (size_t i = 0; i < R ;++i)
		for (size_t j = 0; j < m.C; ++j ){
			var.Mat[i][j];
			for (size_t k = 0; k< C; ++k )
				{
					var.Mat[i][j] = var.Mat[i][j] + Mat[i][k]*m.Mat[k][j];
				}}
	return var;
}
/*Matrix operator *(const Matrix<T> &m){ // Hadamard multiplication
Matrix varM(R,C);
for (size_t i = 0; i< R;++i)
for (size_t j =0; j< C; ++j){
varM.Mat[i][j] = m.Mat[i][j]*Mat[i][j];
}
return varM;
}*/

#endif


