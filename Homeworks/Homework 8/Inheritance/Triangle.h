// Name: George Koubbe
// Date of Submission: 3/26/2018
// Course: 16:332:503, Programming for Finance
// Homework 8

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include "TwoDimensionalShape.h"

class Triangle: public TwoDimensionalShape
{
    
public:
    
    Triangle(double = 0, double = 0, double = 0); // constructor
    ~Triangle();                                  // default destructor
    
    // virtual functions that set the coordinates and radius
    virtual void setx(double);
    virtual void sety(double);
    virtual void setr(double);
    
    // virtual functions that get the coordinates and radius
    virtual double getx() const;
    virtual double gety() const;
    virtual double getr() const;
    
    // virtual function that calculates the area
    virtual double getArea() const;
    
    // virtual function that prints the result
    virtual void print() const;
    
private:
    
    double x, y, r;
};

#endif /* TRIANGLE_H */
