// Name: George Koubbe
// Date of Submission: 2/16/2018
// Course: 16:332:503, Programming for Finance
// Homework 3

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::fixed;

#include <iomanip>
using std::setprecision;
using std::setw;

// function prototypes
void input(double arr[][10], int &, int &);
void display(double arr[][10], int, int);
bool add(double arr1[][10], double arr2[][10], double sum[][10], int, int, int, int);
bool sub(double arr1[][10], double arr2[][10], double sub[][10], int, int, int, int);
bool mult(double arr1[][10], double arr2[][10], double mult[][10], int, int, int, int);
void trans(double arr1[][10], double trans[][10], int, int);
bool det(double arr1[][10], double &, int, int);
bool inv(double arr1[][10], double result[][10], int, int);

// main program execution
int main() {

    // variable declarations
    int choice;
    int r1 = 0, r2 = 0, r3 = 0, c1 = 0, c2 = 0, c3 = 0;
    double determinant;
    double array1[10][10], array2[10][10], result[10][10];
    
    // output the menu
    cout << "\nMenu" << endl;
    cout << " Choice 1: Addition" << endl;
    cout << " Choice 2: Substraction" << endl;
    cout << " Choice 3: Multiplication" << endl;
    cout << " Choice 4: Transpose" << endl;
    cout << " Choice 5: Determinant (3x3 matrix only)" << endl;
    cout << " Choice 6: Inverse (3x3 matrix only)" << endl;
    cout << " Choice 7: Quit" << endl;
    cout << " Enter your Choice" << endl;
    
    // user input
    cin >> choice;
    
    // while loop to keep the program running until choice 7 selected
    while(1) {
        switch(choice) {
            case 1:
                input(array1, r1, c1);
                cout << "Your input is:\n";
                display(array1, r1, c1);
                
                input(array2, r2, c2);
                cout << "Your input is:\n";
                display(array2, r2, c2);
                
                if (add(array1, array2, result, r1, c1, r2, c2)) {
                    cout << "The result is:" << endl;
                    display(result, r1, c1);
                }
                return main();

            case 2:
                input(array1, r1, c1);
                cout << "Your input is:\n";
                display(array1, r1, c1);
                
                input(array2, r2, c2);
                cout << "Your input is:\n";
                display(array2, r2, c2);
                
                if (sub(array1, array2, result, r1, c1, r2, c2)) {
                    cout << "The result is:" << endl;
                    display(result, r1, c1);
                }
                return main();
                
            case 3:
                input(array1, r1, c1);
                cout << "Your input is:\n";
                display(array1, r1, c1);
                
                input(array2, r2, c2);
                cout << "Your input is:\n";
                display(array2, r2, c2);
                
                if (mult(array1, array2, result, r1, c1, r2, c2)) {
                    cout << "The result is:" << endl;
                    display(result, r1, c1);
                }
                return main();
                
            case 4:
                input(array1, r1, c1);
                cout << "Your input is:\n";
                display(array1, r1, c1);
                
                trans(array1, result, r1, c1);
                cout << "The result is:" << endl;
                display(result, r1, c1);
                return main();
                
            case 5:
                input(array1, r1, c1);
                cout << "Your input is:\n";
                display(array1, r1, c1);
                
                if (det(array1, determinant, r1, c1)) {
                    cout << "The result is: " << determinant << endl;
                }
                return main();
                
            case 6:
                input(array1, r1, c1);
                cout << "Your input is:\n";
                display(array1, r1, c1);
                
                if (inv(array1, result, r1, c1)) {
                    cout << "The result is:" << endl;
                    display(result, r1, c1);
                }
                return main();
                
            case 7:
                cout << "\n";
                return 0;
                
            default:
                cout << "Select a choice from the menu" << endl;
                return main();
        }
    }
}

// function definitions
void input(double arr[][10], int &r, int &c){
    cout << "Minimum dimension must be 1 and maximum 10" << endl;
    bool valid = 0;
    
    do {
        cout << "Please enter the number of rows: ";
        cin >> r;
        if (r>=1 && r<=10) valid = 1;
    } while (valid == 0);
    
    valid = 0;
    
    do {
        cout << "Please enter the number of columns: ";
        cin >> c;
        if (c>=1 && c<=10) valid = 1;
    } while (valid == 0);
    
    // Fill the matrix
    cout << "Please enter the value of elements:\n";
    for (int i=0; i<r; i++)
        for (int j=0; j<c; j++)
            cin >> arr[i][j];
}

void display(double arr[][10], int r, int c) {
    for (int i=0; i<r; i++) {
        for (int j = 0; j<c; j++)
            cout << setw(13) << setprecision(2) << fixed << arr[i][j];
        cout << endl;
    }
}

bool add(double arr1[][10], double arr2[][10], double sum[][10], int r1, int c1, int r2, int c2) {
    // for addition, dimensions of rows and columns must be the same
    if (r1!=r2 || c1!=c2) {
        cout << "Operation not supported" << endl;
        return 0;
    }

    for (int i=0; i<r1; i++)
        for (int j=0; j<c1; j++)
            sum[i][j] = arr1[i][j] + arr2[i][j];
    return 1;
}

bool sub(double arr1[][10], double arr2[][10], double sub[][10], int r1, int c1, int r2, int c2) {
    // for substraction, dimensions of rows and columns must be the same
    if (r1!=r2 || c1!=c2) {
        cout << "Operation not supported" << endl;
        return 0;
    }
    
    for (int i=0; i<r1; i++)
        for (int j=0; j<c1; j++)
            sub[i][j] = arr1[i][j] - arr2[i][j];
    return 1;
}

bool mult(double arr1[][10], double arr2[][10], double mult[][10], int r1, int c1, int r2, int c2) {
    if (c1 != r2) {
        cout << "Multiplication of those matrices is impossible" << endl;
        return 0;
    }

    // initializing elements of mult matrix to 0
    for(int i=0; i<r1; ++i)
        for(int j=0; j<c2; ++j)
            mult[i][j] = 0;
    
    for(int i=0; i<r1; ++i)
        for(int j=0; j<c2; ++j)
            for(int k=0; k<c1; ++k)
                mult[i][j] += arr1[i][k] * arr2[k][j];
    return 1;
}

void trans(double arr1[][10], double trans[][10], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j=0; j < c; j++)
            trans[j][i] = arr1[i][j];
}

bool det(double arr1[][10], double &det, int r, int c) {
    if (r==3 && c==3) {
        det = arr1[0][0] * ((arr1[1][1] * arr1[2][2]) - (arr1[2][1] * arr1[1][2]))
              - arr1[0][1] * (arr1[1][0] * arr1[2][2] - arr1[2][0] * arr1[1][2])
              + arr1[0][2] * (arr1[1][0] * arr1[2][1] - arr1[2][0] * arr1[1][1]);
        return 1;
    }
    cout << "Operation not supported" << endl;
    return 0;
}

bool inv(double arr1[][10], double result[][10], int r, int c) {
    if (r==3 && c==3) {
        double det;
        det = arr1[0][0] * ((arr1[1][1] * arr1[2][2]) - (arr1[2][1] * arr1[1][2]))
              - arr1[0][1] * (arr1[1][0] * arr1[2][2] - arr1[2][0] * arr1[1][2])
              + arr1[0][2] * (arr1[1][0] * arr1[2][1] - arr1[2][0] * arr1[1][1]);
        
        if (det == 0) {
            cout << "Det = 0. Inverse impossible to calculate" << endl;
            return 0;
        }
        
        result[0][0] = (arr1[1][1] * arr1[2][2] - arr1[2][1] * arr1[1][2]) / det;
        result[0][1] = (-(arr1[0][1] * arr1[2][2] - arr1[2][1] * arr1[0][2])) / det;
        result[0][2] = (arr1[0][1] * arr1[1][2] - arr1[1][1] * arr1[0][2]) / det;
        result[1][0] = (-(arr1[1][0] * arr1[2][2] - arr1[2][0] * arr1[1][2])) / det;
        result[1][1] = (arr1[0][0] * arr1[2][2] - arr1[2][0] * arr1[0][2]) / det;
        result[1][2] = (-(arr1[0][0] * arr1[1][2] - arr1[1][0] * arr1[0][2])) / det;
        result[2][0] = (arr1[1][0] * arr1[2][1] - arr1[1][1] * arr1[2][0]) / det;
        result[2][1] = (-(arr1[0][0] * arr1[2][1] - arr1[2][0] * arr1[0][1])) / det;
        result[2][2] = (arr1[0][0] * arr1[1][1] - arr1[1][0] * arr1[0][1]) / det;
        
        return 1;
    }
    cout << "Operation not supported" << endl;
    return 0;
}
