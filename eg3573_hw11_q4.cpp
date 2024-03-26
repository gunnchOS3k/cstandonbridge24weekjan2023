/*
Author: Edmund Gunn Jr
Course: NYU Tandon Bridge Extended J term
Assignment: Hw11 Q4
*/

#include <iostream> 
using namespace std; 
// declare function 
int jumpIt(int arr[], int index, int length); 
int main() { 
   int arr[] = {0, 3, 80, 6, 57, 10}; 
   int length = sizeof(arr)/sizeof(arr[0]); 
   // call recursive function to find lowest cost 
   int cost = jumpIt(arr, 0, length); 
   // print the result 
   cout << "Lowest Cost : " << cost; 
   return 0;
}  
// define function 
int jumpIt(int arr[], int index, int length) { 
   // if index is last then we reached the destination 
   if(index == length-1){
      return arr[index];
   }
   // if index is second last then we can jump only 1 block else 
   if(index == length-2){
      return arr[index] + arr[index+1];
      }
   // call function recursively to find minimum cost 
   else{
      return arr[index] + min(jumpIt(arr, index+1, length), jumpIt(arr, index+2, length));
      }   
}