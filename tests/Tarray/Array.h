#ifndef _ARRAY_H
#define _ARRAY_H

template <typename T> class IntArray {
public:
	explicit IntArray(size_t size)
		: size_(size), data_(new int[size]) { // конструктор
		for (size_t i = 0; i != size_; i++)
			data_[i] = 0;
	}

	IntArray(IntArray const &a)
		: size_(a.size_), data_(new int[size_]) { // копирование
		for (size_t i = 0;i != size_; i++)
			data_[i] = a.data_[i];
	}

	T size() const //возвращение значений
	{
		return size_;
	}

    T get(size_t i) const {
		return data_[i]; // получение ячейки с индексом i
	}

	~IntArray() {  // деструктор
		delete[] data_;
	}
	void add_elem(T a) {
		T *newdata_ = new T[size_ + 1];
		for (size_t i = 0; i != size_;i++)
			newdata_[i] = data_[i];
		newdata_[size_] = a;
		data_ = &newdata_[0];
	}

	void delete_elem(size_t k) {
		T *newdata_ = new T[size_ - 1];
		for (size_t i = 0; i != k;i++)
			newdata_[i] = data_[i];
		for (size_t i = k; i != size_ - 1;i++)
			newdata_[i] = data_[i + 1];
		data_ = &newdata_[0];
	}

	

private:
	size_t size_;
	T * data_;
};

template <typename T> void Array<T>::add_elem(T a){}
#endif _ARRAY_H