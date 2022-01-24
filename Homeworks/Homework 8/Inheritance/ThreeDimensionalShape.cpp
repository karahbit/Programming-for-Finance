// Name: George Koubbe
// Date of Submission: 3/26/2018
// Course: 16:332:503, Programming for Finance
// Homework 8

#include "ThreeDimensionalShape.h"

ThreeDimensionalShape::ThreeDimensionalShape()
{
    // empty body
}

ThreeDimensionalShape::~ThreeDimensionalShape()
{
    // empty body
}

//set coordinate z; empty by default
void ThreeDimensionalShape::setz(double)
{
    //empty body
}

// return coordinate z of shape; 0.0 by default
double ThreeDimensionalShape::getz() const
{
    return 0.0;
}

// return volume of shape; 0.0 by default
double ThreeDimensionalShape::getVolume() const
{
    return 0.0;
}
