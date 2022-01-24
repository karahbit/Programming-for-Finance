// Name: George Koubbe
// Date of Submission: 2/19/2018
// Course: 16:332:503, Programming for Finance
// Homework 4

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// FUNCTION PROTOTYPES
void insert(int mylist[], int &, int);
void insert_at(int mylist[], int &, int, int);
int find_linear(int mylist[], int, int);
int find_binary(int mylist[], int, int, bool);
void delete_item_position(int mylist[], int &, int );
void delete_item_isbn(int mylist[], int &, int);
void sort_list_selection(int mylist[], int, bool &);
void sort_list_bubble(int mylist[], int, bool &);
void print (int mylist[], int);

// MAIN PROGRAM EXECUTION
int main() {

    // variable declaration
    int choice;
    int array[20];              // the list won't contain more than 20 books
    int numberBooks = 0;        // the number of books the list currently has
    int element;                // ISBN number entered by user
    int position;               // position in the list
    int found;                  // position on which the element is found
    bool isSorted = 0;          // indicates whether the list is sorted or not
    
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
                insert(array, numberBooks, element);
                cout << "Your list is now" << endl;
                print(array, numberBooks);
                isSorted = 0;
                break;

            case 2:
                cout << "Please type in the element" << endl;
                cin >> element;
                cout << "At what position?" << endl;
                cin >> position;
                insert_at(array, numberBooks, position, element);
                cout << "Your list is now" << endl;
                print(array, numberBooks);
                isSorted = 0;
                break;
                
            case 3:
                cout << "Please type in the element" << endl;
                cin >> element;
                found = find_linear(array, numberBooks, element);
                if (found == -1)
                    cout << "The element is not on the list" << endl;
                else
                    cout << "The element is at position " << found << endl;
                break;
                
            case 4:
                cout << "Please type in the element" << endl;
                cin >> element;
                found = find_binary(array, numberBooks, element, isSorted);
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
                delete_item_position(array, numberBooks, position);
                cout << "Your list is now" << endl;
                print(array, numberBooks);
                break;
                
            case 6:
                cout << "Please type in the element" << endl;
                cin >> element;
                delete_item_isbn(array, numberBooks, element);
                print(array, numberBooks);
                break;
                
            case 7:
                sort_list_selection(array, numberBooks, isSorted);
                cout << "Your sorted list is now" << endl;
                print(array, numberBooks);
                break;
                
            case 8:
                sort_list_bubble(array, numberBooks, isSorted);
                cout << "Your sorted list is now" << endl;
                print(array, numberBooks);
                break;
                
            case 9:
                if (numberBooks > 0)
                    cout << "Your list is" << endl;
                print(array, numberBooks);
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

// FUNCTION DEFINITIONS

// insert an element at the end of the list
void insert(int mylist[ ], int &num_in_list, int new_element) {
    // check if the list is full
    if (num_in_list < 20){
        mylist[num_in_list] = new_element;
        num_in_list++;
    }
    else
        cout << "The list is full" << endl;
}

// insert new element at a certain position
void insert_at(int mylist[], int &num_in_list, int at_position, int new_element) {
    // check if the list is full
    if (num_in_list < 20) {
        // check if position is within range
        if (at_position <= num_in_list) {
            // shift elements to the right
            for (int i = num_in_list-1; i >= at_position-1; i--) {
                mylist[i+1] = mylist[i];
            }
            mylist[at_position-1] = new_element;
            num_in_list++;
        }
        else
            cout << "The list does not even have that many books" << endl;
    }
    else
        cout << "The list is full" << endl;
}

// find an element (with its ISBN number and list its position) using linear search
int find_linear(int mylist[], int num_in_list, int element) {
    for (int i = 0; i < num_in_list; i++)
        if (mylist[i] == element) return i+1;
    return -1;
}

// find an element (with its ISBN number and list its position) of a sorted list using binary search
int find_binary(int mylist[], int num_in_list, int element, bool sorted) {
    if (sorted == 0)
        return -2;
    else {
        int l = 0;
        int r = num_in_list;
        int m;
        
        while (l <= r) {
            m = l + (r-l)/2;
            
            // Check if x is present at mid
            if (mylist[m] == element)
                return m;
            
            // If x greater, ignore left half. Else, ignore right half
            if (mylist[m] < element)
                l = m + 1;
            else
                r = m - 1;
        }
    }
    return -1;
}

// delete an element that is at a certain position
void delete_item_position(int mylist[], int &num_in_list, int position) {
    // check if the list is empty
    if (num_in_list > 0) {
        // check that the element to be deleted is within range
        if (position <= num_in_list) {
            // shift elements to the left
            for (int i = position-1; i < num_in_list; i++) {
                mylist[i] = mylist[i+1];
            }
            num_in_list--;
        }
        else
            cout << "The list does not even have that many books" << endl;
    }
    else
        cout << "The list is already empy" << endl;
}

// delete an element by using its ISBN number
void delete_item_isbn(int mylist[], int &num_in_list, int element) {
    int position = -1;
    // check if the list is empty
    if (num_in_list > 0) {
        // linear find for the element
        for (int i = 0; i < num_in_list; i++)
            if (mylist[i] == element)
                position = i+1;
        if (position == -1)
            cout << "The element is not on the list" << endl;
        else {
            // shift elements to the left
            for (int j = position-1; j < num_in_list; j++) {
                mylist[j] = mylist[j+1];
            }
            num_in_list--;
        }
    }
}

// sort the list by the ISBN numbers (using selection sort)
void sort_list_selection(int mylist[], int num_in_list, bool &sorted) {
    if (sorted == 0) {
        int i, j, min_idx;
    
        // One by one move boundary of unsorted subarray
        for (i = 0; i < num_in_list-1; i++) {
            // Find the minimum element in unsorted array
            min_idx = i;
            for (j = i+1; j < num_in_list; j++)
                if (*(mylist+j) < *(mylist+min_idx))
                    min_idx = j;
        
            // Swap the found minimum element with the first element
            int temp = *(mylist+min_idx);
            *(mylist+min_idx) = *(mylist+i);
            *(mylist+i) = temp;
        }
        sorted = 1;
    }
}

// sort the list by the ISBN numbers (using bubble sort)
void sort_list_bubble(int mylist[], int num_in_list, bool &sorted) {
    if (sorted == 0) {
        for (int i = 0; i < num_in_list-1; i++)
            // Last i elements are already in place
            for (int j = 0; j < num_in_list-i-1; j++)
                if (*(mylist+j) > *(mylist+j+1)) {
                    // Swap
                    int temp = *(mylist+j);
                    *(mylist+j) = *(mylist+j+1);
                    *(mylist+j+1) = temp;
                }
        sorted = 1;
    }
}

// print the list
void print(int mylist[], int num_in_list) {
    if (num_in_list == 0)
        cout << "The list is empty" << endl;
    else
        for (int i = 0; i < num_in_list; i++)
            cout << i+1 << ".\t" << mylist[i] << endl;
}
