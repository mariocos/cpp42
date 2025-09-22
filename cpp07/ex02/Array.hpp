#pragma once

#include <stdexcept>

template <typename T>
class Array {
private:
    T* _elements;
    unsigned int _size;

public:
    Array() : _elements(0), _size(0) {}

    Array(unsigned int n) : _size(n) {
        _elements = new T[n]();
    }

    Array(const Array& other) : _size(other._size) {
        _elements = new T[_size];
        for (unsigned int i = 0; i < _size; ++i) {
            _elements[i] = other._elements[i];
        }
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] _elements;
            _size = other._size;
            _elements = new T[_size];
            for (unsigned int i = 0; i < _size; ++i) {
                _elements[i] = other._elements[i];
            }
        }
        return *this;
    }

    ~Array() {
        delete[] _elements;
    }

    T& operator[](unsigned int index) {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return _elements[index];
    }

    const T& operator[](unsigned int index) const {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return _elements[index];
    }

    unsigned int size() const {
        return _size;
    }
};
