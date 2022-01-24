// Name: George Koubbe
// Date of Submission: 4/2/2018
// Course: 16:332:503, Programming for Finance
// Homework 9

#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "Package.h"

class OvernightPackage: public Package
{

public:
    // default constructor
    OvernightPackage(Customer, Customer, double = 0, double = 0, double = 0);

    // function to set the extra fee for overnight delivery
    void setFlatFee(double);

    // function to get the extra fee for overnight delivery
    double getFlatFee() const;

    // function to calculate the total cost of each package
    virtual double calculateCost();
    // function to get the type of delivery
    virtual string getType() const;

private:
    double flatFee;
};

#endif /* OVERNIGHTPACKAGE_H */
