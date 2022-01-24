// Name: George Koubbe
// Date of Submission: 1/30/2018
// Course: 16:332:503, Programming Finance
// In Class Assignment 2

/*
 Instructions
 
 Write a program that uses "for" structures to print the following triangular
 shape. You need to ask the user how many lines he/she wants in the
 shape (for example, the lines for the shape below is 8). Maximize your use of
 repetition (using nested 'for' structures) and minimize the number of output
 statements (cout).
 
 Shape:
 
 *
 **
 ***
 ****
 *****
 ******
 *******
 ********
 
 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    // insert code here...
    
    // Variable declaration
    int lines;
    
    // Request user input
    cout << "How many lines would you like the triangular shape to have?" << endl;
    cin >> lines;
    cout << "\n";
    
    // Print triangular shape
    for (int i=0; i<lines; i++){
        for (int j=0; j<=i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    
    cout << "\n";
    return 0;
}
