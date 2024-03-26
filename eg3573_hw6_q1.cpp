/*
Author: Edmund Gunn Jr
Assignment: hw6 NYU Tandon Bridge J Extened
*/
#include <iostream>
using namespace std;
 
//declare functions
int fib(int n);

//main function
int main() {
 
    int userInput, fibonacciElement;
 
    cout << "Please enter a positive integer: ";
    cin >> userInput;
 
    fibonacciElement = fib(userInput);
    cout << fibonacciElement;
 
    return 0;
}


//initiate fibinacci
int fib(int n){

    //end if the input is 0
    if ( n == 0 ){
        return 0;
    }

    //strat the function if the numbr is gretaer than 3
    if (n < 3){
        return 1;
    }
 
    //Since position F1 = F2 = 1, then prevVal1 & 2 are default to 1
    int positionVal1 = 1, positionVal2 = 1, currentValue = 0;

    
    for(int position = 3; position <= n; position++){
 
        currentValue = positionVal1 + positionVal2;
        positionVal1 = positionVal2;
        positionVal2 = currentValue;
 
    }

    //display output
    return currentValue;
 
}