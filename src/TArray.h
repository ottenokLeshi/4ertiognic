#ifndef _TARRAY_H
#define _TARRAY_H

template<typename T> class TArray{
public:
	TArray(){_ptr = 0;_size = 0;}
	void add_elem(T a);
	unsigned size() const {return _size;}
	T getElem(unsigned pos){

	};
private:
	T* _ptr;
	unsigned _size;
	///.....
};

template<typename T> void TArray<T>::add_elem(T a){

}




#endif