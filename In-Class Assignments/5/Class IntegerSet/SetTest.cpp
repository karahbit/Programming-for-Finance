// Name: George Koubbe
// Date of Submission: 3/6/2018
// Course: 16:332:503, Programming Finance
// In Class Assignment 5

#include <iostream>
using namespace std;

#include "IntegerSet.h" // IntegerSet class definition

int main()
{
    IntegerSet a;
    IntegerSet b;
    IntegerSet c;
    IntegerSet d;
    
    cout << "Enter set A:\n";
    a.inputSet();
    cout << "\nSet A is:\n";
    a.printSet();
    
    cout << "\nEnter set B:\n";
    b.inputSet();
    cout << "\nSet B is:\n";
    b.printSet();
    
    c = a.unionOfSets(&b);
    cout << "\nUnion of A and B is:\n";
    c.printSet();
    
    d = a.intersectionOfSets(&b);
    cout << "\nIntersection of A and B is:\n";
    d.printSet();
    
    cout << "\n";
    return 0;
}
