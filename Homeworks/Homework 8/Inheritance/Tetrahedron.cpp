// Name: George Koubbe
// Date of Submission: 3/26/2018
// Course: 16:332:503, Programming for Finance
// Homework 8

#include "Tetrahedron.h"
#include <iostream>
#include <math.h>

using std::cout;
using std::endl;

// constructor
Tetrahedron::Tetrahedron(double xValue, double yValue, double zValue, double rValue)
{
    setx(xValue);
    sety(yValue);
    setz(zValue);
    setr(rValue);
}

// destructor
Tetrahedron::~Tetrahedron()
{
    // empty body
}

// virtual functions to set the coordinates
void Tetrahedron::setx(double xValue)
{
    x = xValue;
}

void Tetrahedron::sety(double yValue)
{
    y = yValue;
}

void Tetrahedron::setz(double zValue)
{
    z = zValue;
}

void Tetrahedron::setr(double rValue)
{
    r = rValue;
}

// virtual functions to get the coordinates
double Tetrahedron::getx() const
{
    return x;
}

double Tetrahedron::gety() const
{
    return y;
}

double Tetrahedron::getz() const
{
    return z;
}

double Tetrahedron::getr() const
{
    return r;
}

// virtual functions that calculate the area and volume
double Tetrahedron::getArea() const
{
    return (r * r * sqrt(3));
}

double Tetrahedron::getVolume() const
{
    return (r * r * r * sqrt(2)/12);
}

// virtual function that prints the result
void Tetrahedron::print() const
{
    cout << "The tetrahedron with regular edge length " << getr()
    << " that is located at (" << getx() << "," << gety() << "," << getz()
    << ") has:" << endl;
    cout << "A surface area of " << getArea() << endl;
    cout << "A volume of " << getVolume() << endl;
}
