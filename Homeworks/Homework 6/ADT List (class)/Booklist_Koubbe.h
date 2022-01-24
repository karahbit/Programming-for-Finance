// Name: George Koubbe
// Date of Submission: 3/5/2018
// Course: 16:332:503, Programming for Finance
// Homework 6

#ifndef BOOKLIST_KOUBBE_H
#define BOOKLIST_KOUBBE_H

class Booklist {
    
    
public:
    Booklist();
    void insert(int);
    void insert_at(int, int);
    int find_linear(int);
    int find_binary(int);
    void delete_item_position(int);
    void delete_item_isbn(int);
    void sort_list_selection();
    void sort_list_bubble();
    void print();
    
    int numberBooks;
    
    
private:
    bool isSorted;
    int array[20];
    
    
};

#endif /* Booklist_Koubbe_h */

