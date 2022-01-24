// Name: George Koubbe
// Date of Submission: 4/2/2018
// Course: 16:332:503, Programming for Finance
// Homework 9

#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

// helper class Customer
class Customer
{

public:

    Customer(string = " ", string = " ", string = " ", string = " ", string = " ");
    ~Customer();
    string getName() const;
    string getAddress() const;
    string getCity() const;
    string getState() const;
    string getZip() const;

private:

    string name, address, city, state, zip;

};

// class Package
class Package
{

public:

    // constructor
    Package(Customer, Customer, double = 0, double = 0);

    void setSender(Customer);       // set the information of sender
    void setRecipient(Customer);    // set the information of recipient
    void setWeight(double);         // set weight (in ounces)
    void setCostPerOunce(double);   // set cost per ounce

    Customer getSender() const;     // get the sender information
    Customer getRecipient() const;  // get the recipient information
    double getWeight() const;
    double getCostPerOunce() const;

    virtual string getType() const; // get the type of shipping
    virtual double calculateCost(); // calculate the total cost of each package

private:

    Customer sender;
    Customer recipient;
    double weight, costPerOunce;

};

#endif /* PACKAGE_H */
