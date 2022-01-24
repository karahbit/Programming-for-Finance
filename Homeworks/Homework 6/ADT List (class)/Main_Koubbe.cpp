// Name: George Koubbe
// Date of Submission: 3/5/2018
// Course: 16:332:503, Programming for Finance
// Homework 6

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include "Booklist_Koubbe.h"


// MAIN PROGRAM EXECUTION
int main() {
    
    // variable declaration
    Booklist book_list;
    int choice;
    int element;                // ISBN number entered by user
    int position;               // position in the list
    int found;                  // position on which the element is found
    
    // initial welcome
    cout << "\nWelcome to the Book list program" << endl;
    
    // while loop to keep the program running until choice 0 selected
    while(1) {
        // output the menu
        cout << "What would you like to do?" << endl;
        cout << "\t1.  add an element to end of list" << endl;
        cout << "\t2.  add an element at a location" << endl;
        cout << "\t3.  find an element by ISBN number (linear search)" << endl;
        cout << "\t4.  find an element by ISBN number (binary search)" << endl;
        cout << "\t5.  delete an element at position" << endl;
        cout << "\t6.  delete an element by ISBN number" << endl;
        cout << "\t7.  sort the list (using selection sort)" << endl;
        cout << "\t8.  sort the list (using bubble sort)" << endl;
        cout << "\t9.  print the list" << endl;
        cout << "\t0.  exit" << endl;
        cout << "your choice ---" << endl;
        
        // user input
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Please type in the element" << endl;
                cin >> element;
                book_list.insert(element);
                cout << "Your list is now" << endl;
                book_list.print();
                break;
                
            case 2:
                cout << "Please type in the element" << endl;
                cin >> element;
                cout << "At what position?" << endl;
                cin >> position;
                book_list.insert_at(position, element);
                cout << "Your list is now" << endl;
                book_list.print();
                break;
                
            case 3:
                cout << "Please type in the element" << endl;
                cin >> element;
                found = book_list.find_linear(element);
                if (found == -1)
                    cout << "The element is not on the list" << endl;
                else
                    cout << "The element is at position " << found << endl;
                break;
                
            case 4:
                cout << "Please type in the element" << endl;
                cin >> element;
                found = book_list.find_binary(element);
                if (found == -2)
                    cout << "The list needs to be sorted first" << endl;
                else {
                    if (found == -1)
                        cout << "The element is not on the list" << endl;
                    else
                        cout << "The element is at position " << found << endl;
                }
                break;
                
            case 5:
                cout << "Please type in the element position" << endl;
                cin >> position;
                book_list.delete_item_position(position);
                cout << "Your list is now" << endl;
                book_list.print();
                break;
                
            case 6:
                cout << "Please type in the element" << endl;
                cin >> element;
                book_list.delete_item_isbn(element);
                book_list.print();
                break;
                
            case 7:
                book_list.sort_list_selection();
                cout << "Your sorted list is now" << endl;
                book_list.print();
                break;
                
            case 8:
                book_list.sort_list_bubble();
                cout << "Your sorted list is now" << endl;
                book_list.print();
                break;
                
            case 9:
                if (book_list.numberBooks > 0)
                    cout << "Your list is" << endl;
                book_list.print();
                break;
                
            case 0:
                cout << "\n";
                return 0;
                
            default:
                cout << "Select a choice from the menu" << endl;
                return main();
        }
    }
    
    return 0;
}
