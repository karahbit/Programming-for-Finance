// Name: George Koubbe
// Date of Submission: 2/20/2018
// Course: 16:332:503, Programming Finance
// In Class Assignment 4

#include <iostream>
using std::cout;
using std::cin;
using std::endl;


// FUNCTION PROTOTYPES

int countall(const char *ptr, char letter);


// MAIN PROGRAM EXECUTION
int main() {
    // variable declarations
    int n;
    char *s;
    char c;
    
    // request user input
    cout << "Enter maximum number of characters for the string: " << endl;
    cin >> n;
    
    // ignore all leftover chars by cin >> so cin.getline can read
    // ignore everything or until \n, whichever comes first
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //cin.ignore() ignores single character only. In our case, same thing.
    
    s = new char[n];        // dynamic allocation of memory
    
    cout << "Enter the string (yes, I can handle espaces): " << endl;
    cin.getline(s,n+1,'\n');
    cout << "Enter the character: " << endl;
    cin >> c;
    
    // output results
    
    cout << "\nThe character '" << c << "' appears in the string "
    << countall(s,c) << " times" << endl;

    cout << "\n";
    return 0;
}

// FUNCTION DEFINITIONS

int countall(const char *ptr, char letter) {
    if(!*ptr) return 0; //base case -> if points to NULL, is cause end of string
    return (*ptr == letter) + countall(ptr + 1, letter);
}
