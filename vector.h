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
    // Constructor receives how many dimensions the vector will have
    Vector(size_t dimensions);

    // Rule of three methods
    Vector(const Vector&);
    ~Vector();
    Vector& operator=(const Vector& rhs);

    // Constructor to add values
    Vector(size_t dimensions, const double* data);

    // Accessor and Mutators for Vector elements
    const double& operator[](size_t index)const; // Accessor, Read Only
    double& operator[](size_t index); // Mutator, Writable

    // Our operations, there could be more!
    // Like Dot and Cross product!
    string ToString()const;
    double EuclidianDistance(const Vector& rhs)const;
    bool operator==(const Vector& rhs)const;
    bool operator!=(const Vector& rhs)const;

    Vector operator+(const Vector&)const;
    Vector operator-(const Vector&)const;

    bool IsValid()const; // returns true if the vector is valid, false if it is invalid (dimension == 0)
    size_t Dimensions()const; // returns the dimension space of the vector

    ostream& Write(ostream&)const; // Can we overload this <<
    istream& Read(istream&); // Can we overload this >>
};

#endif //VECTOR_VECTOR_H
