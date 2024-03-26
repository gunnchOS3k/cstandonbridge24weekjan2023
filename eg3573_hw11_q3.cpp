/*
Author: Edmund Gunn Jr
Course: NYU Tandon Bridge Extended J term
Assignment: Hw11 Q3
*/
#include <iostream>
 
using namespace std;
 
// Function declaration for minInArray1()
int minInArray1(int arr[],int arrSize) {
   // Base case: if arrSize is 1, return the only element in the array
   if(arrSize == 1) {
      return arr[0];
   } else {
      // Recursive call to minInArray1() with arrSize-1 as the new argument
      int min = minInArray1(arr, arrSize-1);
      // Compare the last element in the array with the current minimum
      // If the last element is smaller, update the minimum
      if(arr[arrSize-1] < min) {
         min = arr[arrSize-1];
      }
      // Return the minimum value found in the array
      return min;
   }
}
 
// Function declaration for minInArray2()
int minInArray2(int arr[], int low, int high) {
   // Base case: if low and high are the same, return the element at that index
   if(low == high) {
      return arr[low];
   } else {
      // Recursive call to minInArray2() with low+1 as the new low index and the same high index
      int min = minInArray2(arr, low+1, high);
      // Compare the element at the low index with the current minimum
      // If the element at the low index is smaller, update the minimum
      if(arr[low] < min) {
         min = arr[low];
      }
      // Return the minimum value found in the array
      return min;
   }
}
 
int main()
{
    // Initialize an integer array with 10 elements
    int arr[10] = { 9, -2, 14, 12, 3, 6, 2, 1, -9, 15 };
    int res1, res2, res3, res4;
 
    // Call minInArray1() with the array and its size as arguments, and store the result in res1
    // Call minInArray2() with the array, the low index, and the high index as arguments, and store the result in res2
    res1 = minInArray1(arr, 10);
    res2 = minInArray2(arr, 0, 9);
    // Print the results of both functions
    cout << res1 << " " << res2 << endl;
 
    // Call minInArray2() with the array, the low index, and the high index as arguments, and store the result in res3
    // Call minInArray1() with a pointer to the element at index 2 of the array and the number of elements to check as arguments, and store the result in res4
    res3 = minInArray2(arr, 2, 5);
    res4 = minInArray1(arr + 2, 4); 
    // Print the results of both functions
    cout<<res3<< " " <<res4<<endl; 
 
    // Return 0 to indicate successful completion of the program
    return 0;
}
