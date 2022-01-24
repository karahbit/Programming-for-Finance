// Name: George Koubbe
// Date of Submission: 3/26/2018
// Course: 16:332:503, Programming for Finance
// Homework 8

#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape
{

public:
    
    Shape();            // default constructor
    virtual ~Shape();   // default virtual deconstructor
    
    virtual void setx(double) = 0;  // pure virtual function to set coordinate x
    virtual void sety(double) = 0;  // pure virtual function to set coordinate y
    virtual void setz(double) = 0;  // pure virtual function to set coordinate z
    
    // pure virtual function that sets the radius/length of a shape
    virtual void setr(double) = 0;
    
    virtual double getx() const = 0;  // pure virtual function to get coordinate x
    virtual double gety() const = 0;  // pure virtual function to get coordinate y
    virtual double getz() const = 0;  // pure virtual function to get coordinate z
    
    // pure virtual function that gets the radius/length of a shape
    virtual double getr() const = 0;
    
    virtual double getArea() const = 0;   // pure virtual function that returns shape's area
    virtual double getVolume() const = 0; // pure virtual function that returns shape's volume
    virtual void print() const = 0;       // pure virtual function that prints the caculation result
    
};  // end class Shape

#endif /* SHAPE_H */
