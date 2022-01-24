// Name: George Koubbe
// Date of Submission: 3/5/2018
// Course: 16:332:503, Programming for Finance
// Homework 6

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include "Booklist_Koubbe.h"

// constructor
Booklist::Booklist()
{
    numberBooks = 0;
    for (int i = 0; i < 20; i++)
        array[i] = 0;
    isSorted = 0;
    
}

// insert an element at the end of the list
void Booklist::insert(int element)
{
    // check if the list is full
    if (numberBooks < 20){
        array[numberBooks] = element;
        numberBooks++;
        isSorted = 0;
    }
    else
        cout << "The list is full" << endl;
    
}

// insert new element at a certain position
void Booklist::insert_at(int position, int element)
{
    // check if the list is full
    if (numberBooks < 20) {
        // check if position is within range
        if (position <= numberBooks) {
            // shift elements to the right
            for (int i = numberBooks-1; i >= position-1; i--) {
                array[i+1] = array[i];
            }
            array[position-1] = element;
            numberBooks++;
            isSorted = 0;
        }
        else
            cout << "The list does not even have that many books" << endl;
    }
    else
        cout << "The list is full" << endl;
    
}

// find an element (with its ISBN number and list its position) using linear search
int Booklist::find_linear(int element)
{
    for (int i = 0; i < numberBooks; i++)
        if (array[i] == element) return i+1;
    return -1;
    
}

// find an element (with its ISBN number and list its position) of a sorted list using binary search
int Booklist::find_binary(int element)
{
    if (isSorted == 0)
        return -2;
    else {
        int l = 0;
        int r = numberBooks;
        int m;
        
        while (l <= r) {
            m = l + (r-l)/2;
            
            // Check if x is present at mid
            if (array[m] == element)
                return m;
            
            // If x greater, ignore left half. Else, ignore right half
            if (array[m] < element)
                l = m + 1;
            else
                r = m - 1;
        }
    }
    return -1;
    
}

// delete an element that is at a certain position
void Booklist::delete_item_position(int position)
{
    // check if the list is empty
    if (numberBooks > 0) {
        // check that the element to be deleted is within range
        if (position <= numberBooks) {
            // shift elements to the left
            for (int i = position-1; i < numberBooks; i++) {
                array[i] = array[i+1];
            }
            numberBooks--;
        }
        else
            cout << "The list does not even have that many books" << endl;
    }
    else
        cout << "The list is already empy" << endl;
    
}

// delete an element by using its ISBN number
void Booklist::delete_item_isbn(int element)
{
    int position = -1;
    // check if the list is empty
    if (numberBooks > 0) {
        // linear find for the element
        for (int i = 0; i < numberBooks; i++)
            if (array[i] == element)
                position = i+1;
        if (position == -1)
            cout << "The element is not on the list" << endl;
        else {
            // shift elements to the left
            for (int j = position-1; j < numberBooks; j++) {
                array[j] = array[j+1];
            }
            numberBooks--;
        }
    }
    
}

// sort the list by the ISBN numbers (using selection sort)
void Booklist::sort_list_selection()
{
    if (isSorted == 0) {
        int i, j, min_idx;
        
        // One by one move boundary of unsorted subarray
        for (i = 0; i < numberBooks-1; i++) {
            // Find the minimum element in unsorted array
            min_idx = i;
            for (j = i+1; j < numberBooks; j++)
                if (*(array+j) < *(array+min_idx))
                    min_idx = j;
            
            // Swap the found minimum element with the first element
            int temp = *(array+min_idx);
            *(array+min_idx) = *(array+i);
            *(array+i) = temp;
        }
        isSorted = 1;
    }
    
}

// sort the list by the ISBN numbers (using bubble sort)
void Booklist::sort_list_bubble()
{
    if (isSorted == 0) {
        for (int i = 0; i < numberBooks-1; i++)
            // Last i elements are already in place
            for (int j = 0; j < numberBooks-i-1; j++)
                if (*(array+j) > *(array+j+1)) {
                    // Swap
                    int temp = *(array+j);
                    *(array+j) = *(array+j+1);
                    *(array+j+1) = temp;
                }
        isSorted = 1;
    }
    
}

// print the list
void Booklist::print()
{
    if (numberBooks == 0)
        cout << "The list is empty" << endl;
    else
        for (int i = 0; i < numberBooks; i++)
            cout << i+1 << ".\t" << array[i] << endl;
    
}
