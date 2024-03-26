/*
Author: Edmund Gunn Jr
Course: NYU Tandon Bridge Extended J term
Assignment: Hw10 Q2
*/

#include <iostream>
 
using namespace std;
 
// function prototype to find missing numbers in an array
int* findMissing(int arr[], int n, int& resArrSize);
 
// function prototype to print an array
void printArray(int* arr, int arrSize);
 
// main function
int main() {
 
  // declare and initialize variables
  int arrSize = 6;
  int arr[] = {3,1,3,0,6,4};
  int *missingNumArr;
  int newArrSize;
 
  // call the findMissing function and save the returned array
  missingNumArr = findMissing(arr, arrSize ,newArrSize);
   
  // print the new array size and the missing numbers
  cout << "New Array Size: " << newArrSize << endl;
  printArray(missingNumArr, newArrSize);
   
  // free memory allocated to missingNumArr
  delete [] missingNumArr;
 
  // return 0 indicating successful program execution
  return 0;
 
}
 
// function definition to find missing numbers in an array
int* findMissing(int arr[], int n, int& resArrSize){
 
  // create a temporary array and initialize it with 0 to n-1
  int *tempArr = new int[n];
  for (int i = 0; i<n; i++){
      tempArr[i] = i;
  }
    
  // iterate through the given array and mark the indexes as -1 in tempArr 
  // if the number is within the range of 0 to n-1 and hasn't been marked yet
  int count = n;
  for (int i = 0; i<n; i++){
      if (arr[i] < n){
          if (tempArr[arr[i]] != -1){
            tempArr[arr[i]] = -1;
            count--;
          }
      }
  }
 
  // create an array to store the missing numbers
  int *missingArr = new int[count];
  int j = 0;
 
  // iterate through tempArr and add the non-marked indexes to missingArr
  for (int i = 0; i<n; i++){
      if (tempArr[i] != -1){
          missingArr[j] = tempArr[i];
          j++;
      }
  }
 
  // free memory allocated to tempArr
  delete [] tempArr;
    
  // set the resArrSize reference parameter to the size of missingArr
  resArrSize = count;
  // return the missing numbers array
  return missingArr;  
}
 
// function definition to print an array
void printArray(int* arr, int arrSize){
  for (int i=0; i < arrSize; i++){
    cout << arr[i] << " ";  
  } 
  cout << endl;
} 
