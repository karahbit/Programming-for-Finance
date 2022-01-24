// Name: George Koubbe
// Date of Submission: 4/9/2018
// Course: 16:332:503, Programming for Finance
// Homework 10

#include "LinkedList.h"


int main()
{
    char choice;
    Node * newPtr;
    LinkedList list;
    int num;
    string name;

    cout << "\nWelcome to the shopping list program" << endl << endl;
    while (true)
    {
        // display the menu
        cout << "Please choose an option:" << endl;
        cout << "1.  Add a new node at the beginning" << endl << "2.  Add a new node at the end" << endl << "3.  Remove the beginning node" << endl << "4.  Remove the end node" << endl << "5.  Remove a node from the list by entering an item number" << endl << "6.  Remove a node from the list by entering an item name" << endl << "7.  Print out the list" << endl << "8.  Quit the program" << endl;
        cin >> choice;

        switch (choice)
        {
        case'1':
            cout << "Please enter product number to insert at beginning" << endl;
            cin >> num;
            cout << "Please enter the name for the product" << endl;
            cin >> name;
            newPtr = new Node(name, num);   // create a new Node object
            list.addToStart(newPtr);    // add to list
            break;
        case'2':
            cout << "Please enter product number to insert at end" << endl;
            cin >> num;
            cout << "Please enter the name for the product" << endl;
            cin >> name;
            newPtr = new Node(name, num);   // create a new Node object
            list.addToEnd(newPtr);  // add to list
            break;
        case'3':
            list.removeFromStart();
            break;
        case'4':
            list.removeFromEnd();
            break;
        case'5':
            cout << "Please enter product number to delete" << endl;
            cin >> num; // get the product name
            list.removeNodeFromList(num);
            break;
        case'6':
            cout << "Please enter product name to delete" << endl;
            cin >> name;    // get the product name
            list.removeNodeFromList(name);
            break;
        case'7':
            list.printList();
            break;
        case'8':
            return 0;   // end the program
        default:
            cout <<"There is no function for your choice. Please enter again.";
            break;
        }
    }

}
