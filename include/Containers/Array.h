#ifndef _ARRAY_H
#define _ARRAY_H
template <typename T> class Array {
public:
	explicit Array(size_t size)
		: size_(size), data_(new T[size]) { // конструктор
		for (size_t i = 0; i != size_; i++)
			data_[i] = 0;
	}

	Array(Array const &a)
		: size_(a.size_), data_(new T[size_]) { // копирование
		for (size_t i = 0;i != size_; i++)
			data_[i] = a.data_[i];
	}

	unsigned int size() const //возвращение значений
	{
		return size_;
	}
	T operator[](size_t elem) const{
		return data_[elem];
	}
   /* T* get(size_t i) const {
		return *data_[i]; // получение ячейки с индексом i
	}*/

	~Array() {  // деструктор
		delete[] data_;
	}

	void add_elem(T a) {
		T *newdata_ = new T[size_ + 1];
		for (size_t i = 0; i != size_;i++)
			newdata_[i] = data_[i];
		newdata_[size_] = a;
		delete[] data_;
		data_ = &newdata_[0];
	}

	void delete_elem(size_t k) {
		T *newdata_ = new T[size_ - 1];
		for (size_t i = 0; i != k;i++)
			newdata_[i] = data_[i];
		for (size_t i = k; i != size_ - 1;i++)
			newdata_[i] = data_[i + 1];
		delete[] data_;
		data_ = &newdata_[0];
	}
	void set_el(size_t i, T A) {
		data_[i] = A;
	}
		Array<T> &operator=(const Array<T> &K) {
			
			delete[] data_;
			size_ = K.size_;
			data_ = new T[size_];
		for (size_t i = 0; i < size_; ++i) {
			data_[i] = K.data_[i];
		}
		return *this;
	}
		/*std::ostream &operator<< (std::ostream &s, const Array<double> *x0) {
			for (size_t i = 0; i < x0.size(); ++i) {
				s << a[i] << " ";
			}
			return s;
		}*/
		
private:
	T * data_;
	size_t size_;
	
};


#endif _ARRAY_H