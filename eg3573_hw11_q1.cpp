/*
Author: Edmund Gunn Jr
Course: NYU Tandon Bridge Extended J term
Assignment: Hw11 Q1
*/
#include <iostream>
using namespace std;
 
// Function declarations
void printTriangle(int n);
void printOpositeTriangles(int n);
void printRuler(int n);
 
int main() {
  // Call printTriangle() function with argument of 4
  printTriangle(4);
  // Print a newline character
  cout << endl;
  // Call printOpositeTriangles() function with argument of 4
  printOpositeTriangles(4);
  // Print a newline character
  cout << endl;
  // Call printRuler() function with argument of 4
  printRuler(4);
}
 
// Function definition for printTriangle()
void printTriangle(int n){
  // Base case: if n <= 0, return from the function
  if(n <= 0){
    return;
  }
   
  // Recursive call to printTriangle() with argument n-1
  printTriangle(n-1);
 
  // Loop to print n '*' characters
  for(int i = 0; i < n; i++){
    cout << "*";
  }
 
  // Print a newline character after printing the n '*' characters
  cout << endl;
}
 
// Function definition for printOpositeTriangles()
void printOpositeTriangles(int n){
  // Base case: if n <= 0, return from the function
  if(n <= 0){
    return;
  }
 
  // Loop to print n '*' characters
  for(int i = 0; i < n; i++){
    cout << "*";
  }
  // Print a newline character after printing the n '*' characters
  cout << endl;
 
  // Recursive call to printOpositeTriangles() with argument n-1
  printOpositeTriangles(n-1); 
 
  // Loop to print n '*' characters
  for(int i = 0; i < n; i++){
    cout << "*";
  }
 
  // Print a newline character after printing the n '*' characters
  cout << endl;
}
 
// Function definition for printRuler()
void printRuler(int n){
  // Base case: if n <= 0, return from the function
  if(n <= 0){
    return;
  }
 
  // Recursive call to printRuler() with argument n-1
  printRuler(n-1);
 
  // Loop to print n '-' characters
  for(int i = 0; i < n; i++){
    cout << "-";
  }
 
  // Print a newline character after printing the n '-' characters
  cout << "\n";
 
  // Recursive call to printRuler() with argument n-1
  printRuler(n-1);
}
