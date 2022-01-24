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

#include <vector>
using std::vector;

// function prototypes
void input(vector<vector<double>> &);
void display(vector<vector<double>>);
bool add(vector<vector<double>>, vector<vector<double>>, vector<vector<double>> &);
bool sub(vector<vector<double>>, vector<vector<double>>, vector<vector<double>> &);
bool mult(vector<vector<double>>, vector<vector<double>>, vector<vector<double>> &);
void trans(vector<vector<double>>, vector<vector<double>> &);
bool det(vector<vector<double>>, double &);
bool inv(vector<vector<double>>, vector<vector<double>> &);

// main program execution
int main() {
    
    // variable declarations
    int choice;
    double determinant;
    vector<vector<double>> array1, array2, result;
    
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
                input(array1);
                cout << "Your input is:\n";
                display(array1);
                
                input(array2);
                cout << "Your input is:\n";
                display(array2);
                
                if (add(array1, array2, result)) {
                    cout << "The result is:" << endl;
                    display(result);
                }
                return main();
                
            case 2:
                input(array1);
                cout << "Your input is:\n";
                display(array1);
                
                input(array2);
                cout << "Your input is:\n";
                display(array2);
                
                if (sub(array1, array2, result)) {
                    cout << "The result is:" << endl;
                    display(result);
                }
                return main();
                
            case 3:
                input(array1);
                cout << "Your input is:\n";
                display(array1);
                
                input(array2);
                cout << "Your input is:\n";
                display(array2);
                
                if (mult(array1, array2, result)) {
                    cout << "The result is:" << endl;
                    display(result);
                }
                return main();
                
            case 4:
                input(array1);
                cout << "Your input is:\n";
                display(array1);
                
                trans(array1, result);
                cout << "The result is:" << endl;
                display(result);
                return main();
                
            case 5:
                input(array1);
                cout << "Your input is:\n";
                display(array1);
                
                if (det(array1, determinant)) {
                    cout << "The result is: " << determinant << endl;
                }
                return main();
                
            case 6:
                input(array1);
                cout << "Your input is:\n";
                display(array1);
                
                if (inv(array1, result)) {
                    cout << "The result is:" << endl;
                    display(result);
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
void input(vector<vector<double>> &arr){
    int r, c;
    double element;
    bool valid = 0;
    
    cout << "Minimum dimension must be 1 and maximum 10" << endl;
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
    for (int i = 0; i < r; i++) {
        arr.push_back(vector<double>());
        for (int j = 0; j < c; j++) {
            cin >> element;
            arr[i].push_back(element);
        }
    }
}

void display(vector<vector<double>> arr) {
    for (int i=0; i<arr.size(); i++) {
        for (int j=0; j<arr[0].size(); j++)
            cout << setw(13) << setprecision(2) << fixed << arr[i][j];
        cout << endl;
    }
}

bool add(vector<vector<double>> arr1, vector<vector<double>> arr2, vector<vector<double>> &sum) {
    // for addition, dimensions of rows and columns must be the same
    if (arr1.size()!=arr2.size() || arr1[0].size()!=arr2[0].size()) {
        cout << "Operation not supported" << endl;
        return 0;
    }
    
    for (int i=0; i<arr1.size(); i++) {
        sum.push_back(vector<double>());
        for (int j=0; j<arr1[0].size(); j++)
            sum[i].push_back(arr1[i][j] + arr2[i][j]);
    }
    return 1;
}

bool sub(vector<vector<double>> arr1, vector<vector<double>> arr2, vector<vector<double>> &sub) {
    // for substraction, dimensions of rows and columns must be the same
    if (arr1.size()!=arr2.size() || arr1[0].size()!=arr2[0].size()) {
        cout << "Operation not supported" << endl;
        return 0;
    }
    
    for (int i=0; i<arr1.size(); i++) {
        sub.push_back(vector<double>());
        for (int j=0; j<arr1[0].size(); j++)
            sub[i].push_back(arr1[i][j] - arr2[i][j]);
    }
    return 1;
}

bool mult(vector<vector<double>> arr1, vector<vector<double>> arr2, vector<vector<double>> &mult) {
    if (arr1[0].size() != arr2.size()) {
        cout << "Multiplication of those matrices is impossible" << endl;
        return 0;
    }
    
    // initializing elements of mult matrix to 0
    for (int i=0; i<arr1.size(); i++) {
        mult.push_back(vector<double>());
        for (int j=0; j<arr2[0].size(); j++)
            mult[i].push_back(0);
    }
    
    for(int i=0; i<arr1.size(); ++i)
        for(int j=0; j<arr2[0].size(); ++j)
            for(int k=0; k<arr1[0].size(); ++k)
                mult[i][j] += arr1[i][k] * arr2[k][j];
    return 1;
}

void trans(vector<vector<double>> arr1, vector<vector<double>> &trans) {
    for (int i = 0; i < arr1.size(); i++) {
        trans.push_back(vector<double>());
        for (int j=0; j < arr1[0].size(); j++)
            trans[i].push_back(arr1[j][i]);
    }
}

bool det(vector<vector<double>> arr1, double &det) {
    if (arr1.size()==3 && arr1[0].size()==3) {
        det = arr1[0][0] * ((arr1[1][1] * arr1[2][2]) - (arr1[2][1] * arr1[1][2]))
        - arr1[0][1] * (arr1[1][0] * arr1[2][2] - arr1[2][0] * arr1[1][2])
        + arr1[0][2] * (arr1[1][0] * arr1[2][1] - arr1[2][0] * arr1[1][1]);
        return 1;
    }
    cout << "Operation not supported" << endl;
    return 0;
}

bool inv(vector<vector<double>> arr1, vector<vector<double>> &result) {
    if (arr1.size()==3 && arr1[0].size()==3) {
        double det;
        det = arr1[0][0] * ((arr1[1][1] * arr1[2][2]) - (arr1[2][1] * arr1[1][2]))
        - arr1[0][1] * (arr1[1][0] * arr1[2][2] - arr1[2][0] * arr1[1][2])
        + arr1[0][2] * (arr1[1][0] * arr1[2][1] - arr1[2][0] * arr1[1][1]);
        
        if (det == 0) {
            cout << "Det = 0. Inverse impossible to calculate" << endl;
            return 0;
        }
        
        // initializing elements of result matrix to 0
        for (int i=0; i<arr1.size(); i++) {
            result.push_back(vector<double>());
            for (int j=0; j<arr1[0].size(); j++)
                result[i].push_back(0);
        }
        
        result[0][0] = (arr1[1][1] * arr1[2][2] - arr1[2][1] * arr1[1][2]) / det;
        result[0][1] = (-(arr1[1][1] * arr1[2][2] - arr1[2][1] * arr1[0][2])) / det;
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
