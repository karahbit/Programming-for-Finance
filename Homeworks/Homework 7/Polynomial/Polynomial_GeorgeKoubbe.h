// Name: George Koubbe
// Date of Submission: 3/19/2018
// Course: 16:332:503, Programming for Finance
// Homework 7

#ifndef Polynomial_H
#define Polynomial_H

#include<iostream>
using namespace std;


class Polynomial
{
    friend ostream&operator<<(ostream&, const Polynomial &);
    
public:
    Polynomial(int=0);//default constructor
    Polynomial(Polynomial &);//copy constructor
    ~Polynomial();//default destructor
    
    void setPoly();
    double* getPoly();
    void operator=(const Polynomial &);
    Polynomial operator +(Polynomial &);
    Polynomial operator -(Polynomial &);
    Polynomial operator *(Polynomial &);
    Polynomial & operator += (Polynomial &);   //overload += operator as member function
    Polynomial & operator -= (Polynomial &);   //overload -= operator as member function
    Polynomial & operator *= (Polynomial &);
    
private:
    double Pol[13] = {};
};

#endif

