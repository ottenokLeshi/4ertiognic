#ifndef MATRIX_H
#define MATRIX_H 
#include <iostream>
template < typename T > class Matrix{
public:
		Matrix(size_t nrows = 0, size_t ncols = 0); // T
		~Matrix(); // T
		size_t numrows() const{return R;}; // T
		size_t numcols() const{return C;}; // T
		T getElem(size_t nrow, size_t ncol); // T
		void setElem(size_t nrow, size_t ncol, T var); // T
		static Matrix Matrix_eye(size_t nrows, size_t ncols); // T
		Matrix transpose(); // T
		// Matrix
			Matrix operator +(const Matrix &m); // T
			Matrix operator *(const Matrix &m);
			Matrix operator -(const Matrix &m); // T
		// Scalar
			Matrix operator *(const double K); // T
		T det() const;
		 Matrix inv();
	private:
	size_t R;
	size_t C;
	T **Matrix;
};

Matrix:: ~ Matrix(){
	for(size_t i =0; i < R;++i) delete[] Matrix[i];
	delete[] Matrix;
}

Matrix(size_t nrows = 0, size_t ncols = 0){
		**Matrix = new T *[nrows]
		for (size_t i =0; i< nrows) Matrix = new int [ncols];
		R = nrows;
		C = ncols;
		}
Matrix Matrix::operator +(const Matrix &m){
	Matrix varM(R,C);
	for (size_t i = 0; i< R;++i)
		for (size_t j =0; j< C; ++j){
			varM.Matrix[i][j] = m.Matrix[i][j]+Matrix[i][j];
		}
		return varM;
}
Matrix Matrix::operator *(const Matrix &m){ // Hadamard multiplication
	Matrix varM(R,C);
	for (size_t i = 0; i< R;++i)
		for (size_t j =0; j< C; ++j){
			varM.Matrix[i][j] = m.Matrix[i][j]*Matrix[i][j];
		}
		return varM;
}
Matrix Matrix::operator -(const Matrix &m){
	Matrix varM(R,C);
	for (size_t i = 0; i< R;++i)
		for (size_t j =0; j< C; ++j){
			varM.Matrix[i][j] = m.Matrix[i][j]-Matrix[i][j];
		}
		return varM;
}

Matrix Matrix:: operator *(const double K){
	Matrix varM(R,C);
	for (size_t i = 0; i< R;++i)
		for (size_t j =0; j< C; ++j){
			Matrix[i][j] = K*Matrix[i][j];
		}
		return varM;
}
T Matrix::getElem(size_t nrow, size_t ncol){
	return Matrix[nrow][ncol];
}
void Matrix::setElem(size_t nrow, size_t ncol, T var){
	Matrix[nrow][ncol] = var;
}

static Matrix Matrix:: Matrix_eye(size_t nrows, size_t ncols){
	Matrix EYE(nrows,ncols);
	for (size_t i = 0; i< nrows;++i)
		for (size_t j =0; j< ncols; ++j){
			if(i == j) EYE[i][j] = 1;
			else EYE[i][j] = 0;
		}
		return EYE;
}
Matrix Matrix::transpose(){
	T var;
	for(size_t i =0; i< R; ++i)
		for(size_t j =0; j< C; ++j){
			var = Matrix[i][j];
			Matrix[i][j]=Matrix[j][i];
			Matrix[j][i] = var;
		}
			
}

#endif

