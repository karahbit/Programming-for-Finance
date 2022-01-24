// Name: George Koubbe
// Date of Submission: 3/19/2018
// Course: 16:332:503, Programming for Finance
// Homework 7


#include "Polynomial_GeorgeKoubbe.h"

int main()
{
    int termNum_1;   //declare a integer to store the number of terms
    int termNum_2;
    cout << "How many terms does your first polynomial have?" << endl;   //get the number of terms
    cin >> termNum_1;
    Polynomial Poly_1(termNum_1);   //create and initialize the first polynomial object
    cout << "How many terms does your second polynomial have?" << endl;   //get the number of terms
    cin >> termNum_2;
    Polynomial Poly_2(termNum_2);   //create and initialize the second polynomial object
    Polynomial Poly_3(Poly_1);
    
    cout << "First Polynomial is :";
    cout << Poly_1 << endl;            //cout<<Polynomial invokes operator<< by implicitly issuing the non-member function call operator<<(cout,Polynomial)
    cout << "Second Polynomial is :";
    cout << Poly_2 << endl;
    
    cout << "Adding polynomial yields : ";
    cout << (Poly_1 + Poly_2) << endl;    // invoke the overloaded operator + to add two polynomials
    
    cout << "+= the polynomial yields : ";
    cout << (Poly_3 += Poly_2) << endl;   //invoke the overloaded operator += function to yield result
    
    Poly_3 = Poly_1;    //invoke the overloaded operator + to assign one polynomial to another one
    
    cout << "Subtracting the polynomial yield : ";
    cout << (Poly_1 - Poly_2) << endl;          //invoke the overloaded - operator
    
    
    cout << "-= the polynomials yields : ";
    cout << (Poly_3 -= Poly_2) << endl;        //invoke the overloaded -= operator
    
    Poly_3 = Poly_1;
    
    cout << "Multiplying the polynomials yields : ";
    cout << (Poly_1*Poly_2) << endl;           //invoke the overloaded * operator
    
    cout << "*= the polynomial yields : ";
    cout << (Poly_3 *= Poly_2) << endl;        //invoke the overloaded *= operator
    
    cout << "\n";
    return 0;
}
