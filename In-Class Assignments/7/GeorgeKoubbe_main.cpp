// Name: George Koubbe
// Date of Submission: 4/16/2018
// Course: 16:332:503, Programming Finance
// Last in-class assignment

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <deque>
using std::deque;

#include <algorithm>
using std::copy;
using std::remove;
using std::replace_if;
using std::for_each;
using std::count_if;
using std::sort;
using std::find;
using std::distance;

bool greaterThan6(int x) { return (x > 6); }

auto printHalf = [](const int& n) { cout << " " << n/2; };

struct myclass {
    bool operator() (int i,int j) { return (i<j);}
} myobject;


int main() {

    // Q1. Insert the numbers 3, 4, 6, 2, 9, 1, 5, 0, 7, 8 by inserting the
    // numbers in that order, one at a time, to the end of the deque.  
    
    deque<int> values;      // create a deque
    std::ostream_iterator<double> output(cout, " ");
    std::ostream_iterator<double> output2(cout, ",");
    
    // insert values
    values.push_back(3);
    values.push_back(4);
    values.push_back(6);
    values.push_back(2);
    values.push_back(9);
    values.push_back(1);
    values.push_back(5);
    values.push_back(0);
    values.push_back(7);
    values.push_back(8);
    
    
    // Q2. Use STL algorithms to remove the value of 7 from the deque.
    // (hint: you will need to use both the remove algorithm and erase function
    // of the container)
    
    // removes all elements with the value 7
    values.erase(remove(values.begin(), values.end(), 7), values.end());
    
    
    // Q3. Use STL algorithms to replace values greater than 6 in the deque with 10.
    
    replace_if(values.begin(), values.end(), greaterThan6, 10);
    
    
    // Q4. Use STL algorithms to return the sum of all the elements in the deque
    // and print out the sum. Then insert that sum to be a new element at the
    // beginning of the deque.
    
    int sum_of_elems = 0;
    for_each(values.begin(), values.end(), [&] (int n) {
        sum_of_elems += n;
    });
    
    // print sum
    cout << "The sum of the numbers 0 to 9 after removing 7 and replacing"
         << " values greater than 6 with 10 is: " << sum_of_elems << endl;
    
    values.push_front(sum_of_elems);
    
    
    // Q5. Use STL algorithms to count the number of elements in the deque that
    // are greater than 6 and print out the count.
    
    double mycount = count_if(values.begin(), values.end(), greaterThan6);
    cout << "\nNow the number of elements greater than 6 is: " << mycount << endl;
    
    
    // Q6. Use STL algorithms to output the half (integer division) of every
    // element in the deque. (Do not modify the elements in the deque.)
    
    cout << "\nThe half of every element in the deque is:";
    for_each(values.begin(), values.end(), printHalf);
    cout << endl;
    
    // Q7. Use STL algorithms to sort the deque.
    
    sort(values.begin(), values.end(), myobject);
    
    
    // Q8. Use the STL algorithms to find the location of 6 in the deque and
    // print out the location. 
    
    deque<int>::iterator it;
    
    it = find (values.begin(), values.end(), 6);
    if (it != values.end())
        cout << "\nAfter sorting, the location of 6 is at index: "
             << distance(values.begin(), it) << '\n';
    else
        cout << "Element not found in values\n";
    
    
    // Q9. Use the ostream_iterator and the copy algorithm to print out the
    // deque elements with a comma in between the numbers. The last element can
    // also have a comma after it. Make sure you make use of STL algorithms.
    // Please don't use loops or access the deque elements by using the
    // subscript operator (such as using values[1]).
    
    // print deque
    cout << "\nThe items in the deque are: ";
    copy( values.begin(), values.end(), output2 );
    cout << endl;
    
    
    cout << "\n";
    return 0;
}
