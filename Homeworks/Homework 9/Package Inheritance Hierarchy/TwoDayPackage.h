// Name: George Koubbe
// Date of Submission: 4/2/2018
// Course: 16:332:503, Programming for Finance
// Homework 9

#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "Package.h"

class TwoDayPackage: public Package
{

public:
    // default constructor
    TwoDayPackage(Customer, Customer, double = 0, double = 0, double = 0);

    // function to set the additional fee for two day delivery
    void setFlatFee(double);

    // function to get the additional fee for two day delivery
    double getFlatFee() const;

    // function to calculate the total cost of each package
    virtual double calculateCost();
    // function to get the type of delivery
    virtual string getType() const;

private:
    double flatFee;
};

#endif /* TWODAYPACKAGE_H */
