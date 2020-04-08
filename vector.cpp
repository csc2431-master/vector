//
// Created by Arias Arevalo, Carlos on 4/6/20.
//

#include "vector.h"

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using std::ostream;
using std::istream;
using std::string;
using std::stringstream;

Vector::Vector(size_t dimensions) {
    _size = dimensions;
    if (dimensions == 0){
        _data = nullptr;
    }else{
        _data = new double[_size];
        for (size_t i = 0; i < _size; i++) {
            _data[i] = 0.0;
        }
    }
}
Vector::Vector(size_t dimensions, const double *data) {
    _size = dimensions;
    if (_size == 0){
        _data = nullptr;
    }else{
        _data = new double[_size];
        for (size_t i = 0; i < _size; i++)
            _data[i] = data[i];
    }
}

Vector::Vector(const Vector &other) {
    _size = other._size;
    if (_size == 0){
        _data = nullptr;
    }else{
        _data = new double[_size];
        for (size_t i = 0; i < _size; ++i) {
            _data[i] = other._data[i];
        }
    }
}

Vector::~Vector() {
    if (_data != nullptr)
        delete[] _data;
}

Vector &Vector::operator=(const Vector &rhs) {
    // Check if it is a self assignment
    if (&rhs == this)
        return *this;
    // Check if they don't have the same size
    if (_size != rhs._size){
        if (_data != nullptr)
            delete[] _data;
        _size = rhs._size;
        _data = new double[_size];
    }
    for (size_t i = 0; i < _size; ++i) {
        _data[i] = rhs._data[i];
    }
    return *this;
}


const double &Vector::operator[](size_t index) const {
    return _data[index];
}

double &Vector::operator[](size_t index) {
    return _data[index];
}

string Vector::ToString() const {
    stringstream ss;
    ss << "[";
    for (int i = 0; i < _size; ++i) {
        if (i != _size - 1){
            ss << _data[i] << ", ";
        }else{
            ss << _data[i];
        }
    }
    ss << "]";
    return ss.str();
}

double Vector::EuclidianDistance(const Vector &rhs) const {
    if (_size != rhs._size)
        return -1; // Impossible distance!

    double sum = 0.0;
    for (int i = 0; i < _size; ++i) {
        sum += pow(_data[i] - rhs._data[i], 2.0);
    }
    return sqrt(sum);
}

bool Vector::operator==(const Vector &rhs) const {
    if (_size != rhs._size)
        return false;
    for (int i = 0; i < _size; ++i) {
        if (_data[i] != rhs._data[i])
            return false;
    }
    return true;
}

bool Vector::operator!=(const Vector &rhs) const {
    return !(*this == rhs);
}

Vector Vector::operator+(const Vector &rhs) const {
    if (_size != rhs._size)
        return Vector(0);
    Vector retVal(_size);
    for (size_t i = 0; i < _size; ++i) {
        retVal._data[i] = _data[i] + rhs._data[i];
    }
    return retVal;
}

Vector Vector::operator-(const Vector &rhs) const {
    if (_size != rhs._size)
        return Vector(0);
    Vector retVal(_size);
    for (size_t i = 0; i < _size; ++i) {
        retVal._data[i] = _data[i] - rhs._data[i];
    }
    return retVal;
}

bool Vector::IsValid() const {
    return _size != 0;
}

size_t Vector::Dimensions() const {
    return _size;
}

ostream &Vector::Write(ostream &output) const {
    output << _size << " ";
    for (int i = 0; i < _size; ++i) {
        if (i != _size - 1){
            output << _data[i] << " ";
        }else{
            output << _data[i];
        }
    }
    return output;
}

istream &Vector::Read(istream &input) {
    size_t dimension;
    input >> dimension;
    if (input.fail()){
        return input;
    }
    if (dimension == 0){
        if (_data){
            delete[] _data;
            _size = 0;
        }
        return input;
    }
    double* elements = new double[dimension];
    for (size_t i = 0; i < dimension; i++) {
        input >> elements[i];
        if (input.fail()){
            delete[] elements;
            return input;
        }
    }

    if (dimension != _size){
        if (_data){
            delete[] _data;
        }
        _size = dimension;
        _data = elements;
    }else{
        for (size_t i = 0; i < dimension; i++) {
            _data[i] = elements[i];
        }
        delete[] elements;
    }
    return input;
}

