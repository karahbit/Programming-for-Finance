// Name: George Koubbe
// Date of Submission: 1/25/2018
// Course: 16:332:503, Programming Finance
// Homework 1

/*
Instructions

Write a program that does the followings:
1. Ask the user to enter five numbers.
2. Find the maximum and minimum of those numbers.
3. Display the maximum and minimum.

Please notice the following:
1. For comparison, use 'if' statements.
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {
    // insert code here...
    
    // Variable declaration
    float a, b, c, d, e;
    float max, min;
    
    // Request user input
    cout << "Enter 5 numbers. Separate each one with a space" << endl;
    cin >> a >> b >> c >> d >> e;
    
    // Comparison to get the maximun value
    if (a>b && a>c && a>d && a>e) max = a;
    else if (b>c && b>d && b>e) max = b;
    else if (c>d && c>e) max = c;
    else if (d>e) max = d;
    else max = e;
    
    // Comparison to get the minimum value
    if (a<b && a<c && a<d && a<e) min = a;
    else if (b<c && b<d && b<e) min = b;
    else if (c<d && c<e) min = c;
    else if (d<e) min = d;
    else min = e;
    
    // Display maximum and minimum value
    cout << "\nThe maximum is: " << max << endl;
    cout << "The minimum is: " << min << endl << "\n";
    
    return 0;
}
