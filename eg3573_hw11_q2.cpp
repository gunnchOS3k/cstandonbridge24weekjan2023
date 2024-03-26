/*
Author: Edmund Gunn Jr
Course: NYU Tandon Bridge Extended J term
Assignment: Hw11 Q2
*/
#include <iostream>
#include <math.h>
 
using namespace std;
 
// Function declarations
int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);
 
int main() {
  // Initialize an integer array with four elements
  int arr[] = {2, -1, 3, 10}; 

  // Call sumOfSquares() function with the integer array and its size as arguments
  int sum = sumOfSquares(arr, 4);
  // Print the sum of squares
  cout << "Sum = " << sum << endl; 
 
  // Call isSorted() function with the integer array and its size as arguments
  bool sorted = isSorted(arr, 4); 
 
  // Check if the array is sorted and print the appropriate message
  if(sorted){
    cout << "Array is sorted"<< endl;
  }else{
    cout << "Array is NOT sorted"<< endl;
  }
 
  // Return 0 to indicate successful completion of the program
  return 0;
}
 
// Function definition for sumOfSquares()
int sumOfSquares(int arr[], int arrSize){
  // Base case: if arrSize <= 0, return 0
  if(arrSize <= 0){ 
    return 0; 
  } 

  // Recursive call to sumOfSquares() with arrSize-1 as the new argument,
  // and adding the square of the last element in the array
  return (sumOfSquares(arr, arrSize-1) + pow(arr[arrSize-1], 2)); 
}
 
// Function definition for isSorted()
bool isSorted(int arr[],int arrSize){
  // Base cases: if arrSize is 0 or 1, return true
  if(arrSize == 1 || arrSize == 0){
    return true;
  }
     
  // If any unsorted pair is found, return false
  if(arr[arrSize-1] < arr[arrSize-2]){
    return false;
  }
 
  // Last pair was sorted
  // Move to next pair by recursively calling isSorted() with arrSize-1 as the new argument
  return isSorted(arr, arrSize-1);
}
