// Name: George Koubbe
// Date of Submission: 3/26/2018
// Course: 16:332:503, Programming for Finance
// Homework 8

#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

#include <iostream>
#include "ThreeDimensionalShape.h"

class Tetrahedron: public ThreeDimensionalShape
{
    
public:
    
    Tetrahedron(double = 0, double = 0, double = 0, double = 0); // constructor
    ~Tetrahedron();                                              // default destructor
    
    // virtual functions that set the coordinates and radius
    virtual void setx(double);
    virtual void sety(double);
    virtual void setz(double);
    virtual void setr(double);
    
    // virtual functions that get the coordinates and radius
    virtual double getx() const;
    virtual double gety() const;
    virtual double getz() const;
    virtual double getr() const;
    
    // virtual function that calculates the area and volume
    virtual double getArea() const;
    virtual double getVolume() const;
    
    // virtual function that prints the result
    virtual void print() const;
    
private:
    
    double x, y, z, r;
};

#endif /* TETRAHEDRON_H */
