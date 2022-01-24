// Name: George Koubbe
// Date of Submission: 3/6/2018
// Course: 16:332:503, Programming Finance
// In Class Assignment 5

#include <iostream>
#include <iomanip>
using namespace std;

#include "IntegerSet.h"

// constructor
IntegerSet::IntegerSet()
{
    for ( int i = 0; i < 101; i++ ) set[ i ] = 0;
} // end IntegerSet constructor

// input a set from the user
void IntegerSet::inputSet()
{
    int number;
    
    do
    {
        cout << "Enter an element (-1 to end): ";
        cin >> number;
        
        if ( validEntry( number ) )
            set[ number ] = 1;
        else if ( number != -1 )
            cout << "Invalid Element\n";
    } while ( number != -1 ); // end do...while
    
    cout << "Entry complete\n";
} // end function inputSet

// prints the set to the output stream
void IntegerSet::printSet() const
{
    cout << "{ ";
    
    for (int u = 0; u < 101; u++ )
        if ( set[ u ] ) cout << u << " ";
    
    cout << "}" << endl;
} // end function printSet

IntegerSet IntegerSet::unionOfSets(IntegerSet* A)
{
    IntegerSet result;
    for (int i = 0; i<101; i++) {
        result.set[i] = (this->set[i] || A->set[i]);
    }
    return result;
}

IntegerSet IntegerSet::intersectionOfSets(IntegerSet* A)
{
    IntegerSet result;
    for (int i = 0; i<101; i++) {
        result.set[i] = (this->set[i] && A->set[i]);
    }
    return result;
}
