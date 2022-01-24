// Name: George Koubbe
// Date of Submission: 2/6/2018
// Course: 16:332:503, Programming Finance
// In Class Assignment 3

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::fixed;

#include <iomanip>
using std::setprecision;
using std::setw;

void winnerByMode( int [], int [], int );

int counter = 0;

int main() {
    
    const int responseSize = 20;        // size of the array of students
    int frequency[5] = { 0 };           // initialize array frequency
    // initialize array responses (no equal frequency) winner = 2
    //int response[responseSize] = {2,5,1,2,3,3,4,5,5,4,1,2,2,2,5,2,3,5,1,1};
    // initialize array responses (no equal frequency) no winner
    int response[responseSize] = {2,5,1,2,3,3,4,5,5,4,5,2,2,2,5,2,3,5,1,1};
    
    winnerByMode(frequency, response, responseSize);
    
    cout << "\n";
    return 0;
}

// determine most frequent response (responses vary from 1 to 5)
void winnerByMode( int freq[], int answer[], int size ) {
    int largest = 0;    // represents largest frequency
    int modeValue = 0;  // represents most frequent response
    
    cout << "Rutgers Student Council(RSC) Elections\n" << endl;
    
    // initialize frequencies to 0
    for ( int i = 1; i <= 5; i++ )
        freq[i] = 0;
    
    // summarize frequencies
    for ( int j = 0; j < size; j++ )
        ++freq[ answer[ j ] ];
    
    // output headers for result columns
    cout << "Candidate" << setw(11) << "Votes"
    << setw(19) << "Histogram\n\n" << setw(55);
    
    // output results
    for ( int rating = 1; rating <= 5; rating++ ) {
        cout << setw( 8 ) << rating << setw( 11 )
        << freq[ rating ] << "          ";
        
        // keep track of mode value and largest fequency value
        if ( freq[ rating ] > largest ) {
            largest = freq[ rating ];
            modeValue = rating;
        } // end if
        
        // output histogram bar representing frequency value
        for ( int k = 1; k <= freq[ rating ]; k++ )
            cout << '*';
        
        cout << '\n';  // begin new line of output
        
    } // end outer for
    
    // calculate if there is more than one candidate with the highest # of votes
    for (int rating = 1; rating <= 5; rating++) {
        if ( freq[ rating ] == largest )
            counter++;
    }
    
    // print final veredict
    if (counter > 1) {
        cout << "\nThere was a tie between " << counter << " candidates with "
        << largest << " votes each" << endl;
    }
    else
        cout << "\nThe winner candidate is number " << modeValue
        << " with " << largest << " votes" << endl;

} // end function mode
