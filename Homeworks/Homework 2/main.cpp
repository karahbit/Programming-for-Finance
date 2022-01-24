// Name: George Koubbe
// Date of Submission: 1/31/2018
// Course: 16:332:503, Programming for Finance
// Homework 2

#include <iostream>
#include <fstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h>
#include <iomanip>      // parameterized stream manipulators

using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::fixed;
using std::setprecision;

int main() {
    // insert code here...
    
    ofstream file;                  // Output stream class to operate on files
    file.open("outputXY.txt");      // Open new txt file
    
    // Seed for generating random numbers relative to the current time
    srand(static_cast<unsigned int>(time(0)));
    
    // Variable declaration
    int totalDarts;
    int insideDarts = 0;
    double r = 1.0;                 // Radius of the circle
    const double Pi = 3.14159265;
    double calculatedPi = 0.0;
    
    // Request user input
    cout << "How many iterations would you like?" << endl;
    cin >> totalDarts;
    
    // Main loop for calculation of Pi
    for (int i=0; i<totalDarts; i++){
        
        // Generation and normalization of random numbers
        double x = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
        double y = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
        
        file << x << "," << y << "\n";  // Write coordinates to file
        
        // Calculating if the coordinates are inside the circle
        if (x*x + y*y <= r) {
            insideDarts++;
            
            // Equation for calculating Pi
            calculatedPi = 4.0 * (static_cast<double>(insideDarts)/totalDarts);
            
            /* If the error between the calculated Pi and the actual Pi is small
               enough, stop the iterations */
            if ((abs(calculatedPi - Pi)) < 0.0001) break;
        }
    }
    
    // Print calculated value of Pi
    cout << "\n" << "The estimated value of Pi is: " << setprecision(8) << fixed
         << calculatedPi << endl;
    
    file.close();                           // Close the current file
    
    cout << "\n";
    return 0;
}
