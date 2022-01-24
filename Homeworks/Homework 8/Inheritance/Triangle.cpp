// Name: George Koubbe
// Date of Submission: 3/26/2018
// Course: 16:332:503, Programming for Finance
// Homework 8

#include "Triangle.h"
#include <iostream>
#include <math.h>

using std::cout;
using std::endl;

//constructor
Triangle::Triangle(double xValue, double yValue, double rValue)
{
    setx(xValue);
    sety(yValue);
    setr(rValue);
}

// destructor
Triangle::~Triangle()
{
    // empty body
}

// virtual functions to set the coordinates
void Triangle::setx(double xValue)
{
    x = xValue;
}

void Triangle::sety(double yValue)
{
    y = yValue;
}

void Triangle::setr(double rValue)
{
    r = rValue;
}

// virtual functions to get the coordinates
double Triangle::getx() const
{
    return x;
}

double Triangle::gety() const
{
    return y;
}

double Triangle::getr() const
{
    return r;
}

// virtual function that calculates the area
double Triangle::getArea() const
{
    return (r * r * sqrt(3)/4);
}


// virtual function that prints the result
void Triangle::print() const
{
    cout << "The triangle with lenghth " << getr() << " that is located at ("
    << getx() << "," << gety() << ") has:" << endl;
    cout << "An area of " << getArea() << endl;
}
