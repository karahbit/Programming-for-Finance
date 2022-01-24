// Name: George Koubbe
// Date of Submission: 4/2/2018
// Course: 16:332:503, Programming for Finance
// Homework 9

#include "OvernightPackage.h"

// default constructor
OvernightPackage::OvernightPackage(Customer sen, Customer rec, double w, double c, double f) :Package(sen, rec, w, c)
{
    flatFee = f;
}

// function to set the additional fee for overnight delivery
void OvernightPackage::setFlatFee(double fee)
{
    if (fee < 0) {
        cout << "Error! Additional cost should be positive." << endl;
    }
    else
        flatFee = fee;
}

// function to get the additional fee for overnight delivery
double OvernightPackage::getFlatFee() const
{
    return flatFee;
}

// function to calculate the total cost of each package
double OvernightPackage::calculateCost()
{
    return getWeight()*(getCostPerOunce() + flatFee);
}

// function to get the type of delivery
string OvernightPackage::getType() const
{
    return "Overnight Delivery";
}
