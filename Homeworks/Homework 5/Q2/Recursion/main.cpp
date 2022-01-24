// Name: George Koubbe
// Date of Submission: 2/26/2018
// Course: 16:332:503, Programming for Finance
// Homework 5. Q2.

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// FUNCTION PROTOTYPES
bool jump(int arr[], int index);


// MAIN PROGRAM EXECUTION
int main() {
    
    // variable declaration
    int n;
    int *array;
    
    // initial welcome
    cout << "\nWelcome to the Jump puzzle" << endl;
    
    // while loop to keep the program running until choice 0 selected
    while(1) {
        // user input request
        cout << "\nPlease, type in the maximum number of positive integers (-1 to exit):"
        << endl;
        cin >> n;
        if (n == -1) break;
        array = new int[n];
        
        // fill the input row
        cout << "\nPlease, type in the positive integers (the last one needs to be 0):"
        << endl;
        for (int i = 0; i < n; i++) {
            cin >> array[i];
            if (array[i] < 0) {
                cout << "Please type in a positive integer" << endl;
                cin >> array[i];
            }
        }
        
        // main function operation
        if (jump(array, 0))
            cout << "It can be solved";
        else
            cout << "It cannot be solved";

        cout << "\n";
    }
    
    cout << "\n";
    return 0;
}

// FUNCTION DEFINITIONS

bool jump(int arr[], int index) {
    int r = 1;
    int step;
    
    while (arr[r-1] != 0) r++;      // calculate lenght of array
    
    if (index >= r || index < 0) return false;  // the peg is out of the range
    
    if (arr[index] == -1) return false;         // the place has been visited before
    
    if (arr[index] == 0) return true;          // the peg reached the goal
    
    step = arr[index];      // getting current jump value
    
    arr[index] = -1;        // visiting current place
    
    return (jump(arr, index - step) || jump(arr, index + step));
}
