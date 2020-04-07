//
// Created by Arias Arevalo, Carlos on 4/6/20.
//

#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::ostream;

class Vector{
    double* _data;
    size_t _size;
public:
    Vector(size_t dimensions);

    Vector(const Vector&);
    ~Vector();
    Vector& operator=(const Vector& rhs);

    string ToString()const;
    double EuclidianDistance(const Vector& rhs)const;
    bool operator==(const Vector& rhs)const;
    bool operator!=(const Vector& rhs)const;

    Vector operator+(const Vector&)const;
    Vector operator-(const Vector&)const;

    bool IsValid()const; // returns true if the vector is valid, false if it is invalid (dimension == 0)
};

#endif //VECTOR_VECTOR_H
