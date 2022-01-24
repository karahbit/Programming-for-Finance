// Name: George Koubbe
// Date of Submission: 3/26/2018
// Course: 16:332:503, Programming for Finance
// Homework 8

// USER INCLUDES
#include "Shape.h"
#include "TwoDimensionalShape.h"
#include "ThreeDimensionalShape.h"
#include "Circle.h"
#include "Triangle.h"
#include "Sphere.h"
#include "Tetrahedron.h"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// FUNCTION PROTOTYPES
double getNum();

// MAIN PROGRAM EXECUTION
int main() {
    Shape *p_Shape;    // declare a pointer of type shape
    int choice;         // declare a integer to store the choice
    double x, y, z, r;  // coordinates and radius/length
    
    while (1)
    {
        // display a menu
        cout << "Please choose a shape or 0 to exit:" << endl << "1. Circle"
        << endl << "2. Triangle" << endl << "3. Sphere" << endl
        << "4. Regular Tetrahedron" << endl << "0. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;  // get the user's choice
        
        switch (choice) {
            case 0:
                cout << "\n";
                return 0;
                
            case 1:
                cout << "\nYou have choosen the circle.\n" << endl
                << "Please enter the center of the circle (x-coordinate and then y-coordinate):" << endl;
                cin >> x >> y;       // get coordinates
                cout << endl << "Please enter the radius of the circle:" << endl;
                r = getNum();        // get radius
                cout << "\n";
                p_Shape = new Circle(x, y, r);   // create and initialize a Circle object
                p_Shape->print();                // print the calculation result
                delete p_Shape;                  // free memory
                cout << "\n";
                break;
                
            case 2:
                cout << "\nYou have choosen the triangle.\n" << endl
                << "Please enter the center of the triangle (x-coordinate and then y-coordinate):" << endl;
                cin >> x >> y;       // get coordinates
                cout << endl << "Please enter the side length of the triangle:" << endl;
                r = getNum();        // get side length
                cout << "\n";
                p_Shape = new Triangle(x, y, r);  // create and initialize a Triangle object
                p_Shape->print();                 // print the calculation result
                delete p_Shape;                   // free memory
                cout << "\n";
                break;
                
            case 3:
                cout << "\nYou have choosen the sphere.\n" << endl
                << "Please enter the center of the sphere (x-coordinate, y-coordinate and then z-coordinate):" << endl;
                cin >> x >> y >> z;       // get coordinates
                cout << endl << "Please enter the radius of the sphere:" << endl;
                r = getNum();             // get radius
                cout << "\n";
                p_Shape = new Sphere(x, y, z, r);   // create and initialize a Sphere object
                p_Shape->print();                   // print the calculation result
                delete p_Shape;                     // free memory
                cout << "\n";
                break;
                
            case 4:
                cout << "\nYou have choosen the regular tetrahedron.\n" << endl
                << "Please enter the center of the regular tetrahedron (x-coordinate, y-coordinate and then z-coordinate):" << endl;
                cin >> x >> y >> z;       // get coordinates
                cout << endl << "Please enter the edge length of the regular tetrahedron:" << endl;
                r = getNum();             // get edge length
                cout << "\n";
                p_Shape = new Tetrahedron(x, y, z, r);   // create and initialize a Tetrahedron object
                p_Shape->print();                        // print the calculation result
                delete p_Shape;                          // free memory
                cout << "\n";
                break;
                
            default:
                cout << "Error! Enter again!" << endl;
        }
    }
}

// FUNCTION DEFINITIONS
double getNum()
{
    double num;
    cin >> num;
    while (num<0) {
        cout << "Invalid input! Please type in again!" << endl;
        cin >> num;
    }
    return num;
}
