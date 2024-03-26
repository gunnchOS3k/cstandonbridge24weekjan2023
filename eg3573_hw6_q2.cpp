/*
Author: Edmund Gunn Jr
Assignment: hw6 NYU Tandon Bridge J Extened
*/
#include <iostream>
using namespace std;

//declare functions
void printShiftedTriangle (int n, int m, char symbol);
void printPineTree (int n, char symbol);
 
int main() {
 
    int numberOfLines, numberOfSpaces, numberOfTriangles;
    char characterToPrint;
 
    cout << "Enter the number of lines for the triangle (positive integer): ";
    cin >> numberOfLines;
 
    cout << "Enter the number of spaces to the left: ";
    cin >> numberOfSpaces;
 
    cout << "Enter the character to use (e.g. *, +, $): ";
    cin >> characterToPrint;
 
    cout << endl;
 
    
    //call the main function
    printShiftedTriangle(numberOfLines,numberOfSpaces,characterToPrint);
 
    cout << endl;
    cout << endl;
 
    cout << "Enter the number of triangles: ";
    cin >> numberOfTriangles;
 
    cout << "Enter the character to use (e.g. *, +, $): ";
    cin >> characterToPrint;
 
    printPineTree(numberOfTriangles,characterToPrint);
 
    return 0;
}

//triangle shape
void printShiftedTriangle (int n, int m, char symbol){
 
    //n = total # of rows
    //m = total # of left spaces
 
   //nested for loop to diaply proper output
    for(int row = 1; row <= n; row++){
 
        // print spaces
        for(int colSpaces = 1; colSpaces <= (n-row) + m; colSpaces++){
            cout << " ";
        }
        //print symbols
        for(int colStars = 1; colStars <= (2*row) - 1; colStars++){
            cout << symbol;
        }
 
        cout <<endl;
 
    }
 
}

//pine tree functions
void printPineTree (int n, char symbol){
    for(int i = 1; i <= n; i++){
        printShiftedTriangle(i+1,n-i,symbol);
    }
}