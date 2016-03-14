#ifndef _MATRIX_H
#define _MATRIX_H
template<typename T> class Matrix{
public:
	Matrix(size_t nrows=0, size_t ncols=0);
	~Matrix();
	size_t numrows()const;
	size_t numcols()const;
	T getElem(size_t nrow,size_t ncol);
	void setElem(size_t nrow,size_t ncol,const T& );
	Matrix transpose();
	
	Matrix operator+(const Matrix &m);
	Matrix operator-(const Matrix &m);
	Matrix operator*(const Matrix &m);
	Matrix operator+(const T&);
	Matrix operator-(const T&);
	Matrix operator*(const T&);
	T det()const;
	Matrix inv();
	


	static Matrix eye(size_t nrows, size_t ncols);
private:

};

#endif