// Name: George Koubbe
// Date of Submission: 3/6/2018
// Course: 16:332:503, Programming Finance
// In Class Assignment 5

#ifndef INTEGER_SET_H
#define INTEGER_SET_H

class IntegerSet
{
public:
    IntegerSet( ); // constructor
    
    IntegerSet unionOfSets(IntegerSet*);        
    IntegerSet intersectionOfSets(IntegerSet*);
    
    void inputSet(); // read values from user
    
    void printSet() const;
    
private:
    int set[ 101 ]; // range of 0 - 100
    
    // determines a valid entry to the set
    int validEntry( int x) const
    {
        return ( x >= 0 && x <= 100 );
    } // end function validEntry
};
#endif
