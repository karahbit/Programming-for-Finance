// Name: George Koubbe
// Date of Submission: 4/2/2018
// Course: 16:332:503, Programming for Finance
// Homework 9

// USER INCLUDES
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

#include <iomanip>

using std::fixed;
using std:: setprecision;

#include <vector>

using std::vector;

// FUNCTION PROTOTYPES
void viaPointer(Package *);


// MAIN PROGRAM EXECUTION
int main() {

    double costperounce = 0.5;          // assume cost for per ounce
    // assume additional cost for two day package
    double twodaysaddition = 2.00;
    // assume additional cost for overnight package
    double overnightaddition = 5.00;
    double total = 0;                   // total cost

    // output some information of program
    cout << "\nPackage delivery services program" << endl;
    cout << endl;
    cout << fixed << setprecision(2);
    cout << "Cost per ounce for a package: $" << costperounce << "/ounce" << endl;
    cout << "Additional cost for two day delivery: $" << twodaysaddition << "/ounce" << endl;
    cout << "Additional cost for overnight delivery: $" << overnightaddition << "/ounce" << endl;
    cout << endl;

    // a 3 elements vector, which have 3 pointers point to Package class
    vector<Package *> packageVector(3);

    // create a Customer as sender
    Customer S1("John Smith", "1 Davidson Road", "Piscataway", "NJ", "08854");
    // create a Customer as receipent
    Customer R1("Tom Smith", "2 Davidson Road", "Piscataway", "NJ", "08854");

    // invoke constructor to create a regular package
    Package package(S1, R1, 10, costperounce);

    Customer S2("Mary Smith", "3 Davidson Road", "Piscataway", "NJ", "08854");
    Customer R2("Jennifer Smith", "4 Davidson Road", "Piscataway", "NJ", "08854");

    // invoke constructor to create a twoday package
    TwoDayPackage twodaypackage(S2, R2, 5.0, costperounce, twodaysaddition);

    Customer S3("John Smith", "1 Davidson Road", "Piscataway", "NJ", "08854");
    Customer R3("Mary Smith", "3 Davidson Road", "Piscataway", "NJ", "08854");

    // invoke constructor to create a overnight package
    OvernightPackage overnightpackage(S3, R3, 2.0, costperounce, overnightaddition);

    // assign each class's address to pointers vector
    packageVector[0] = &package;
    packageVector[1] = &twodaypackage;
    packageVector[2] = &overnightpackage;

    // Loop through the vector to process packages polymorphically
    for (int i = 0; i < 3; i++) {
        cout << "Package " << i + 1 << ":" << endl;
        cout << endl;
        // invoke process function to display information and calc the cost
        viaPointer(packageVector[i]);
        // invoke function polymorphically to calculate the cost
        total += packageVector[i]->calculateCost();
    }
    cout << "Total cost of all the packages: $" << total << endl;

    cout << "\n";
    return 0;
}


// FUNCTION DEFINITIONS

// the process function, input a pointer of Package, but invoke function polymorphically
void viaPointer(Package *Ptr)
{
    Customer sender;
    Customer recipient;
    sender = Ptr->getSender();          // get sender's information
    recipient = Ptr->getRecipient();    // get receipient's information

    // print the information of sender and receipient
    cout << "Sender:" << endl;
    cout << sender.getName() << endl;
    cout << sender.getAddress() << endl;
    cout << sender.getCity() << ", " << sender.getState() << " " << sender.getZip() << endl;
    cout << endl;
    cout << "Recipent:" << endl;
    cout << recipient.getName() << endl;
    cout << recipient.getAddress() << endl;
    cout << recipient.getCity() << ", " << recipient.getState() << " " << recipient.getZip() << endl;
    cout << endl;

    cout << "Weight of package: " << Ptr->getWeight() << " ounces" << endl;
    cout << "Type of delivery: " << Ptr->getType() << endl;
    // invoke funtion polymorphically, which is determined by what type the pointer points to
    cout << "Cost of Package: $" << Ptr->calculateCost() << endl;
    cout << endl;
}
