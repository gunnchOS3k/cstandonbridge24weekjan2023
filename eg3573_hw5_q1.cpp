#include <iostream>
 
using namespace std;
 
int main() {

    //declare user input variable
    int numEntered;

    //get user input
    cout << "Enter a positive integer: " << endl;
    cin >> numEntered;
 
    //outer for-loop print each new line
    //inner for-loop print product for times table
    for(int i = 1; i <= numEntered; i++){
        for (int j = 1; j <= numEntered; j++){
            cout << i*j << "\t";
        }
        cout << endl;
    }
 
    return 0;
}