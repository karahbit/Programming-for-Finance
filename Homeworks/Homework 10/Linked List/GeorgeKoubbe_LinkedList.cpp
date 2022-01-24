// Name: George Koubbe
// Date of Submission: 4/9/2018
// Course: 16:332:503, Programming for Finance
// Homework 10

#include "LinkedList.h"

// constructor
LinkedList::LinkedList()
{
    myHead = NULL;
    myTail = NULL;
    mySize = 0;
}

// destructor
LinkedList::~LinkedList()
{
    // empty body
}

// function to get the size of the list
int LinkedList::size() const
{
    return mySize;
}

// function to add a new node at the beginning
void LinkedList::addToStart(Node * newPtr)
{

    if (myHead == NULL)
        myHead = myTail = newPtr;
    else if (myHead != NULL)    // check whether the list is empty
    {
        newPtr->next = myHead;
        myHead = newPtr;
    }
    mySize++;
    printList();
    return;
}

// function to add a new node at the end
void LinkedList::addToEnd(Node * newPtr)
{

    if (myHead == NULL)
        myHead = myTail = newPtr;
    else if (myHead != NULL)    // check whether the list is empty
    {
        myTail->next = newPtr;
        newPtr->next = NULL;
        myTail = newPtr;
    }
    mySize++;
    printList();
    return;
}

// function to print out the list
void LinkedList::printList()
{
    Node * currentPtr;
    if (myHead == NULL) // check whether the list is empty
    {
        cout << "\nList Is Empty!\n" << endl;
        return;
    }
    else
    {
        currentPtr = myHead;    // begin from the first item
        cout << "\nList" << endl;
        cout << "Item No      Item Name" << endl;
        for (int i = 0; i < size(); i++)
        {
            cout << currentPtr->itemNo << "            " << currentPtr->itemName << endl;
            currentPtr = currentPtr->next;
        }
        cout << endl;
        return;
    }
}

// function to remove the beginning node
bool LinkedList::removeFromStart()
{
    Node * tempPtr;
    tempPtr = myHead;
    if (myHead != NULL) // check whether the list is empty
    {
        if (myHead == myTail)   // if there is only one item in the list
        {
            myHead = myTail = NULL;
            delete tempPtr;
            mySize--;
            cout << "Success!" << endl; // successful delete
            printList();
        }
        else
        {
            myHead = myHead->next;
            delete tempPtr;
            mySize--;
            cout << "Success!" << endl; // successful delete
            printList();
        }
        return true;
    }
    else
    {
        cout << "\nFailed! List Is Empty!\n" << endl;   // unsuccessful delete
        return false;
    }
}

// function to remove the end node
bool LinkedList::removeFromEnd()
{
    Node * tempPtr, *currentPtr;
    currentPtr = myHead;

    if (myHead != NULL) // check whether the list is empty
    {
        if (myHead == myTail)   // if there is only one item in the list
        {
            myHead = myTail = NULL;
            delete currentPtr;
            mySize--;
            cout << "Success!" << endl; // successful delete
            printList();
        }
        else
        {
            tempPtr = myTail;
            while (currentPtr->next != myTail)
            {
                currentPtr = currentPtr->next;
            }
            myTail = currentPtr;
            delete tempPtr;
            mySize--;
            cout << "Success!" << endl; // delete successful
            printList();
        }
        return true;

    }
    else
    {
        cout << "\nFailed! List Is Empty!\n" << endl;   // delete unsuccessful
        return false;
    }
}

// function to remove a node from the list by entering an item number
void LinkedList::removeNodeFromList(int Num)
{
    Node * tempPtr, *currentPtr;
    currentPtr = myHead;
    tempPtr = currentPtr;

    if (myHead == NULL) // check whether the list is empty
    {
        cout << "\nFailed! List Is Empty!\n" << endl;   // unsuccessful delete
        return;
    }

    while (currentPtr->itemNo != Num)
    {
        tempPtr = currentPtr;
        currentPtr = currentPtr->next;
        if (currentPtr == NULL)
        {
            cout << "Item Not Found!" << endl;  // unsuccessful delete
            printList();
            return;
        }
    }
    // if there is only one item in the list
    if ((myHead == currentPtr) && (myTail == currentPtr))
    {
        myHead = myTail = NULL;
        delete tempPtr;
        mySize--;
        cout << "Success!" << endl; // successful delete
        printList();
    }
    else
    {
        tempPtr->next = currentPtr->next;
        tempPtr = currentPtr;
        if (myHead == tempPtr)
        {
            myHead = tempPtr->next;
        }
        delete tempPtr;
        mySize--;
        cout << "Success!" << endl; // successful delete
        printList();
    }
    return;
}

// function to remove a node from the list by entering an item name
void LinkedList::removeNodeFromList(string Name)
{
    Node * tempPtr, *currentPtr;
    currentPtr = myHead;
    tempPtr = currentPtr;

    if (myHead == NULL) // check whether the list is empty
    {
        cout << "\nFailed! List Is Empty!\n" << endl;   // unsuccessful delete
        return;
    }
    while (currentPtr->itemName != Name)
    {
        tempPtr = currentPtr;
        currentPtr = currentPtr->next;
        if (currentPtr == NULL)
        {
            cout << "Item Not Found!" << endl;  // unsuccessful delete
            printList();
            return;
        }
    }
    // if there is only one item in the list
    if ((myHead == currentPtr) && (myTail == currentPtr))
    {
        myHead = myTail = NULL;
        delete tempPtr;
        mySize--;
        cout << "Success!" << endl; // successful delete
        printList();
    }
    else
    {
        tempPtr->next = currentPtr->next;
        tempPtr = currentPtr;
        if (myHead == tempPtr)
        {
            myHead = tempPtr->next;
        }
        delete tempPtr;
        mySize--;
        cout << "Success!" << endl; // successful delete
        printList();
    }
    return;
}
