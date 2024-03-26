/*
Author: Edmund Gunn Jr
Assignment: hw6 NYU Tandon Bridge J Extened
*/
#include <iostream>
using namespace std;
 
//declare functions
double eApprox( int n );


//main function
int main() {
 
    cout.precision(30);
 
    for(int n=1; n <= 15; n++){
        cout << "n = " << n << "\t" << eApprox(n) << endl;
    }
 
    return 0;
}

// factorial function
double eApprox( int n ){
    double result = 1.0;
    double currentFactorial = 1.0;
    //display results
    for(int i = 1; i <= n; i++){
        currentFactorial *= i;
        result += (1/currentFactorial);
    }
    return result;
}