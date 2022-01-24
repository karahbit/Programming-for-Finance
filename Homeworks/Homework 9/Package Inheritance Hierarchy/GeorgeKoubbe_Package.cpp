// Name: George Koubbe
// Date of Submission: 4/2/2018
// Course: 16:332:503, Programming for Finance
// Homework 9

#include "Package.h"

// Implementation of helper class Customer

// default constructor
Customer::Customer(string n, string a, string c, string s, string z)
{
    name = n;
    address = a;
    city = c;
    state = s;
    zip = z;
}

// destructor
Customer::~Customer(){
    // empty body
}

// function to get name
string Customer::getName() const
{
    return name;
}

// function to get address
string Customer::getAddress() const
{
    return address;
}

// function to get city
string Customer::getCity() const
{
    return city;
}

// function to get state
string Customer::getState() const
{
    return state;
}

// function to get zip code
string Customer::getZip() const
{
    return zip;
}

// Implementation of class Package

// default constructor
Package::Package(Customer sen, Customer rec, double w, double c)
{
    // set the information of sender
    setSender(sen);

    // set the information of receipient
    setRecipient(rec);

    // set the information of cost and weight
    costPerOunce = c;
    weight = w;
}

// function to set sender
void Package::setSender(Customer person)
{
    sender = person;
    return;
}

// function to set receipient
void Package::setRecipient(Customer person)
{
    recipient = person;
    return;
}

// function to set the weight
void Package::setWeight(double w)
{
    // perform validity check
    if (w >= 0){
        weight = w;
    }
    else cout << "Error! the weight must be positive." << endl;
    return;
}

// function to set the cost per ounce
void Package::setCostPerOunce(double c)
{
    // perform validity check
    if (c >= 0){
        costPerOunce = c;
    }
    else cout << "Error! the cost per ounce must be positive." << endl;
    return;
}

// function to get sender's information
Customer Package::getSender() const
{
    return sender;
}

// function to get recipient's information
Customer Package::getRecipient() const
{
    return recipient;
}

// function to get the weight
double Package::getWeight() const
{
    return weight;
}

//function to get the cost per ounce
double Package::getCostPerOunce() const
{
    return costPerOunce;
}

// function to calculate the total cost of each package
double Package::calculateCost()
{
    return weight*costPerOunce;
}

// function to get the type of delivery
string Package::getType() const
{
    return "Regular Delivery";
}
