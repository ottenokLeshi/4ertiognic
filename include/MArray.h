#ifndef MARRAY_H
#define MARRAY_H
#include <stdexcept>
template <typename T> class Array
{
private:
    T * _data;
    size_t _size;

public:
    friend class Marker;
    class Marker {
    private:
        T * _current;

    public:
        friend class Array<T>;

        Marker(const Array& A) {
            _current = A._data;
        }

        Marker(T *item) {
            _current = item;
        }

        ~Marker() {};

        T& get_data() {
            return *_current;
        }

        T& operator*() const {
            return *_current;
        }

        bool is_null() {
            return (_current) ? true : false;
        }

        Marker operator++() {
            // I don't know how to access to members of Array (_size and _data)
            //
            //if (_size == 0 || _current == _data[_size - 1])
            //    throw std::out_of_range("Index is out of range");
            return Marker(++_current);
        }

        Marker operator++(int) {
            //if (_size == 0 || _current == _data[_size - 1])
            //    throw std::out_of_range("Index is out of range");
            return Marker(_current++);
        }

        Marker operator--() {
            //if (_size == 0 || _current == _data[0])
            //    throw std::out_of_range("Index is out of range");
            return Marker(--_current);
        }

        Marker operator--(int) {
            //if (_size == 0 || _current == _data[0])
            //    throw std::out_of_range("Index is out of range");
            return Marker(_current--);
        }

        bool operator==(const Marker& mar) const{
            return (_current == mar._current);
        }

        bool operator!=(const Marker& mar) const{
            return (_current != mar._current);
        }

        void operator=(const Marker& mar) {
            _current = mar._current;
        }
    };


    Array() {
        _data = NULL;
        _size = 0;
    }

    Array(size_t size) {
        _size = size;
        _data = new T[size];
        for (size_t i = 0; i < size; i++)
            _data[i] = T();
    }

    Array(Array const &a) {
        _size = a._size;
        _data = new T[a._size];
        for (size_t i = 0; i < _size; i++)
            _data[i] = a._data[i];
    }

    size_t size() const {
        return _size;
    }

    void push_back(const T& newItem) {
        T *newData = new T[_size + 1];
        for (size_t i = 0; i < _size; i++)
            newData[i] = _data[i];
        newData[_size] = newItem;
        delete[] _data;
        _data = newData;
        _size++;
    }

    T operator[](size_t index) const {
        if (index >= _size)
            throw std::out_of_range("Index is out of range");
        return _data[index];
    }

    void erase(Marker mar) {
        if (!mar.is_null())
            throw std::out_of_range("Index is out of range");

        T *newData = new T[_size - 1];
        Marker m_new(newData);
        Marker m(_data);
        for ( ; m != this->end(); m++) {
            if (m != mar) {
                *(m_new) = *m;
                m_new++;
            }
        }

        delete[] _data;
        _data = newData;
        _size--;
        mar = NULL;
    }

    void erase(size_t index) {
        if (index >= _size)
            throw std::out_of_range("Index is out of range");

        T *newData = new T[_size - 1];
        for (size_t i = 0, j = 0; i < _size; i++) {
            if (i != index)
                newData[j++] = _data[i];
        }
        delete[] _data;
        _data = newData;
        _size--;
    }

    T front() const {
        if (_size == 0)
            throw std::out_of_range("Empty array");
        return _data[0];
    }

    T back() const {
        if (_size == 0)
            throw std::out_of_range("Empty array");
        return _data[_size - 1];
    }

    Marker begin() const {
        return Marker(_data);
    }

    Marker end() const {
        return Marker(_data + _size);
    }

    Marker search(const T& item) {
        for (Marker mar(_data); mar != this->end(); mar++) {
            if (*mar == item)
                return mar;
        }
        return this->end();
    }
};

#endif