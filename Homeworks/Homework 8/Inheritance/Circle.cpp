// Name: George Koubbe
// Date of Submission: 3/26/2018
// Course: 16:332:503, Programming for Finance
// Homework 8

#include "Circle.h"
#include <iostream>

using std::cout;
using std::endl;

const double PI  = 3.141592653589793238463;

// constructor
Circle::Circle(double xValue, double yValue, double rValue)
{
    setx(xValue);
    sety(yValue);
    setr(rValue);
}

// destructor
Circle::~Circle()
{
    // empty body
}

// virtual functions to set the coordinates
void Circle::setx(double xValue)
{
    x = xValue;
}

void Circle::sety(double yValue)
{
    y = yValue;
}

void Circle::setr(double rValue)
{
    r = rValue;
}

// virtual functions to get the coordinates
double Circle::getx() const
{
    return x;
}

double Circle::gety() const
{
    return y;
}

double Circle::getr() const
{
    return r;
}

// virtual function that calculates the area
double Circle::getArea() const
{
    return (r * r * PI);
}

// virtual function that prints the result
void Circle::print() const
{
    cout << "The circle with radius " << getr() << " that is located at ("
    << getx() << "," << gety() << ") has:" << endl;
    cout << "An area of " << getArea() << endl;
}
