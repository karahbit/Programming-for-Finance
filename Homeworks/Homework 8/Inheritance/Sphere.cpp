// Name: George Koubbe
// Date of Submission: 3/26/2018
// Course: 16:332:503, Programming for Finance
// Homework 8

#include "Sphere.h"
#include <iostream>

using std::cout;
using std::endl;

const double PI  = 3.141592653589793238463;

// constructor
Sphere::Sphere(double xValue, double yValue, double zValue, double rValue)
{
    setx(xValue);
    sety(yValue);
    setz(zValue);
    setr(rValue);
}

// destructor
Sphere::~Sphere()
{
    // empty body
}


// virtual functions to set the coordinates
void Sphere::setx(double xValue)
{
    x = xValue;
}

void Sphere::sety(double yValue)
{
    y = yValue;
}

void Sphere::setz(double zValue)
{
    z = zValue;
}

void Sphere::setr(double rValue)
{
    r = rValue;
}

// virtual functions to get the coordinates
double Sphere::getx() const
{
    return x;
}

double Sphere::gety() const
{
    return y;
}

double Sphere::getz() const
{
    return z;
}

double Sphere::getr() const
{
    return r;
}

// virtual functions that calculate the area and volume
double Sphere::getArea() const
{
    return (r * r * 3.1415*4);
}

double Sphere::getVolume() const
{
    return (r * r *r * PI * 4 /3);
}

// virtual function that prints the result
void Sphere::print() const
{
    cout << "The circle with radius " << getr() << " that is located at ("
    << getx() << "," << gety() << "," << getz() << ") has:" << endl;
    cout << "A surface area of " << getArea() << endl;
    cout << "A volume of " << getVolume() << endl;
}
