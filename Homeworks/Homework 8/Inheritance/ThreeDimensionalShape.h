// Name: George Koubbe
// Date of Submission: 3/26/2018
// Course: 16:332:503, Programming for Finance
// Homework 8

#ifndef THREEDIMENSIONALSHAPE_H
#define THREEDIMENSIONALSHAPE_H

#include <iostream>
#include "Shape.h"

class ThreeDimensionalShape: public Shape
{
    
public:
    
    ThreeDimensionalShape();  // default constructor
    ~ThreeDimensionalShape(); // default destructor
    
    virtual void setx(double) = 0;  // pure virtual function that sets coordinate x
    virtual void sety(double) = 0;  // pure virtual function that sets coordinate y
    virtual void setz(double);      // virtual function that sets coordinate z
    virtual void setr(double) = 0;  // pure virtual function that sets radius/length of a shape
    
    virtual double getx() const = 0;  // pure virtual function that gets coordinate x
    virtual double gety() const = 0;  // pure virtual function that gets coordinate y
    virtual double getz() const;      // virtual function that gets coordinate z
    virtual double getr() const = 0;  // pure virtual function that gets radius/length of a shape
    
    virtual double getArea() const = 0;   // pure virtual function that returns shape area
    virtual double getVolume() const;     // virtual function that returns shape volume
    virtual void print() const = 0;       // pure virtual function that prints the caculation result
    
}; // end class ThreeDimensionalShape

#endif /* THREEDIMENSIONALSHAPE_H */
