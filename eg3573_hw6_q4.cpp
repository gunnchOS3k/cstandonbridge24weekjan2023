/*
Author: Edmund Gunn Jr
Assignment: hw6 NYU Tandon Bridge J Extened
*/
#include <iostream>
#include <cmath>
 
using namespace std;
 
//declare functions
void printDivisors(int num);


//main function
int main() {
 
    //delcare vvaribles
    int userInput;
    cout << "Please enter a positive integer >= 2: ";
    cin >> userInput;
    //if statment to display results
    if(userInput > 1){
        printDivisors(userInput);
    }else{
        cout << "Invalid input, please try again!";
    }
 
    cout << endl;
 
    return 0;
}

//divisor function
void printDivisors(int num){
 
    //display output
    for(int i=1; i <= sqrt(num); i++){
        if(num % i == 0){
 
            cout << i << " ";
 
        }
    }

    //display output
    for(int i=sqrt(num); i >= 1; i--){
 
        if(num % i == 0){
 
            if(num / i != i){
                cout << num / i << " ";
            }
 
        }
 
    }
}