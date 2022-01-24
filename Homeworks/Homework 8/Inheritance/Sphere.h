// Name: George Koubbe
// Date of Submission: 3/26/2018
// Course: 16:332:503, Programming for Finance
// Homework 8

#ifndef SPHERE_H
#define SPHERE_H

#include <iostream>
#include "ThreeDimensionalShape.h"

class Sphere: public ThreeDimensionalShape
{
    
public:
    
    Sphere(double = 0, double = 0, double = 0, double = 0); // constructor
    ~Sphere();                                              // default destructor
    
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
    
    // virtual functions that calculate the area and volume
    virtual double getArea() const;
    virtual double getVolume() const;
    
    // virtual function that prints the result
    virtual void print() const;
    
private:
    
    double x, y, z, r;
};

#endif /* SPHERE_H */
