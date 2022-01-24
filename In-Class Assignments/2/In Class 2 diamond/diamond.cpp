// Name: George Koubbe
// Date of Submission: 1/30/2018
// Course: 16:332:503, Programming for Finance
// In Class Assignment 2

/*
 Instructions
 
 Write a program to print out the diamond shape. You need to ask the
 user to input a maximum number of stars in each line (for example, in the shape
 below, the maximum number is 9, the line in which has the most stars has 9
 stars). In the diamond shape, the input maximum number should be odd. If the
 user doesn't enter an odd number, tell him/her to enter an odd number.
 
 Shape:
 
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
 
 */

#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

int main() {
    // insert code here...
    
    // Variable declaration
    int maxStars;
    
    // Request user input
    cout << "What is the maximum number of stars going to be?" << endl;
    cin >> maxStars;
    cout << "\n";
    
    // Requirement for odd number
    while ((maxStars % 2) == 0) {
        cout << "Please, enter an odd number instead" << endl;
        cin >> maxStars;
    }
    
    // Print upper diamond shape, including middle line
    for (int whites=maxStars/2; whites>=0; whites--){
        cout << setw(whites+1);
        for (int j=0; j<(maxStars-whites*2); j++) {
            cout << "*";
        }
        cout << "\n";
    }
    
    // Print lower diamond shape
    for (int whites = 1; whites<=maxStars/2; whites++){
        cout << setw(whites+1);
        for (int j=0; j<(maxStars-whites*2); j++) {
            cout << "*";
        }
        cout << "\n";
    }
    
    cout << "\n";
    return 0;
}
