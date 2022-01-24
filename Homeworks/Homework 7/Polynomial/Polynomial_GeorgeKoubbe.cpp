// Name: George Koubbe
// Date of Submission: 3/19/2018
// Course: 16:332:503, Programming for Finance
// Homework 7

#include "Polynomial_GeorgeKoubbe.h"

ostream & operator<<(ostream & output, const Polynomial & object)  //to overload <<operator as a non-member function.
{
    bool first = true;   //set the first term signal to true
    
    if (object.Pol[0] != 0)   //check whether the the term which is degree 0 exist
    {
        output << object.Pol[0];   //display the x^0 term in the form of " coefficient "
        first = false;   //set the first term signal to false to reveal that the first term has been outputed
    }
    
    if (object.Pol[1] != 0)   //check whether the term which is degree 1 exist
    {
        if (first)   //check whether it is the first term to be displayed
        {
            output << object.Pol[1] << "x";  //display the  x^1 term in the form of " coefficient x".
            first = false;   //set the first term signal to false which reveals that the first term has been outputed
        }
        else if (object.Pol[1]>0)
        {
            output << "+" << object.Pol[1] << "x";   //deal with the situation that the coefficient is positive
            first = false;   //set the first term signal to false which reveals that the first term has been outputed
        }
        else
        {
            output << "-" << -object.Pol[1] << "x";   //deal with the situation that the coefficient is positive
            first = false;   //set the first term signal to false which reveals that the first term has been outputed
        }
    }
    
    for (int i = 2; i < 13; i++)
    {
        if (object.Pol[i] == 0)   //check whether term whichc is degree i exist
        {
            continue;
        }
        else if (first)    //check whether it is the first term to be displayed
        {
            output << object.Pol[i] << "x^" << i;   //display x^i term in the form of " coefficient x^exponent"
            first = false;   //set the first term signal to false which reveals that the first term has been outputed
        }
        else if (object.Pol[i]>0)
        {
            output << "+" << object.Pol[i] << "x^" << i;   //deal with the situation that the coefficient is positive
            first = false;   //set the first term signal to false which reveals that the first term has been outputed
        }
        else
        {
            output << "-" << -object.Pol[i] << "x^" << i;   //deal with the situation that the coefficient is positive
            first = false;   //set the first term signal to false which reveals that the first term has been outputedc
        }
    }
    
    return output;
}

Polynomial::Polynomial(int termNum)  //default constructor
{
    for (int i = 0; i < termNum; i++)
    {
        setPoly();
    }
}

Polynomial::Polynomial(Polynomial &poly)//copy constructor
{
    for (int i = 0; i <= 12; i++)
        this->Pol[i] = poly.Pol[i];
}

Polynomial::~Polynomial()   //default destructor
{
    //empty body
}

void Polynomial::setPoly()
{
    double c;
    int e;
    
    cout << "Please type in your coefficient and exponent(the exponent must be an integer) : ";
    cin >> c >> e;
    while (e > 6 || e<0)  //check whether the coefficient and exponent are valid .
    {
        cout << "Error! The input exponent is invalid.The exponent must be within 0-6 " << endl;
        cout << "Please input coefficient and exponent again:";
        cin >> c >> e;
    }
    Pol[e] = c;//store the term
}

double* Polynomial::getPoly()
{
    return Pol;
}

void Polynomial::operator=(const Polynomial &poly) //overloaded = operator
{
    for (int i = 0; i <= 12; i++)
        this->Pol[i] = poly.Pol[i];  //memberise assignment
}

Polynomial  Polynomial::operator+(Polynomial &poly)//overload + operator
{
    Polynomial sum;
    for (int i = 0; i < 13; i++)
    {
        sum.Pol[i] = Pol[i] + poly.Pol[i]; //for terms have same exponent, add their coefficient,and assign to the sum polynomial.
    }
    
    return sum; //return the new one which is the sum of *this and poly
}

Polynomial  Polynomial::operator-(Polynomial &poly)//overload - operator
{
    Polynomial diff;
    for (int i = 0; i < 13; i++)
    {
        diff.Pol[i] = Pol[i] - poly.Pol[i]; //for terms have same exponent, subtract the coefficient of poly from that of *this,and assign to the diff polynomial.
    }
    
    return diff; //return the new one which is the sum of *this and poly
}

Polynomial  Polynomial::operator*(Polynomial &poly)
{
    Polynomial prod;
    
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            prod.Pol[i + j] += Pol[i] * poly.Pol[j];  //the product is (coefficient1*coefficient2) x^ (exponent1+exponent2),so store the result in the prod.
        }
    }
    
    return prod;
}

Polynomial & Polynomial::operator+=(Polynomial &poly)//overload += operator
{
    *this = *this + poly;   //use + operator to get the sum of *this and poly and assign it to *this
    return *this; //return the new one whihch is the sum of *this and poly
}

Polynomial & Polynomial::operator-=(Polynomial &poly)//overload -= operator
{
    *this = *this - poly;   //use - operator to get the difference of *this and poly and assign it to *this
    return *this; //return the new one whihch is the difference of *this and poly
}

Polynomial & Polynomial::operator *= (Polynomial & poly)
{
    *this = (*this) * poly;   //use * operator to get the product of *this and poly and assign it to *this
    return *this;   //return the new one whihch is the product of *this and poly
}
