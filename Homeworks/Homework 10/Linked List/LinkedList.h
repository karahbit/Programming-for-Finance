// Name: George Koubbe
// Date of Submission: 4/9/2018
// Course: 16:332:503, Programming for Finance
// Homework 10

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>

using std::cin;
using std::cout;
using std::endl;

#include<string>

using std::string;


class Node
{

    friend class LinkedList;

public:
    Node(string& name, int no)
        :itemName(name), itemNo(no)
    {
        this->next=NULL;
    }

private:
    string itemName;
    int itemNo;
    Node *next;

};

class LinkedList
{

public:
    LinkedList();
    ~LinkedList();
    int size() const;
    void addToStart(Node *);
    void addToEnd(Node *);
    void printList();
    bool removeFromStart();
    bool removeFromEnd();
    void removeNodeFromList(int);
    void removeNodeFromList(string);

private:
    Node *myHead;
    Node *myTail;
    int mySize;

 };

#endif
