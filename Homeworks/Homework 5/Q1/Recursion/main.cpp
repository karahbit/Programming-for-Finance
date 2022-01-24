// Name: George Koubbe
// Date of Submission: 2/26/2018
// Course: 16:332:503, Programming for Finance
// Homework 5. Q1.

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// FUNCTION PROTOTYPES
void squares(int n);


// MAIN PROGRAM EXECUTION
int main() {

    // variable declaration
    int n;
    
    // initial welcome
    cout << "\nWelcome to the Squares program" << endl;
    
    // while loop to keep the program running until choice 0 selected
    while(1) {
        // input request
        cout << "\nPlease, type in a positive integer (0 to exit): " << endl;
        
        // user input
        cin >> n;
        
        if (n < 0) continue;
        if (n == 0) break;
        
        // main function operation
        squares(n);
        cout << "\n";
    }
    
    cout << "\n";
    return 0;
}

// FUNCTION DEFINITIONS

void squares(int n) {
    // print the square of odd numbers in descending order
    if (n % 2 != 0){
        if (n == 1) {
            cout << n*n;
            return;             // base case
        }
        cout << n*n << ", ";
    }
    
    squares(n-1);               // recursion
    
    // print the square of even numbers in ascending order
    if (n % 2 == 0) cout << ", " << n*n;
}
