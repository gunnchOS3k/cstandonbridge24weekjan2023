/*
Author: Edmund Gunn Jr
Assignment: hw8 NYU Tandon Bridge J Extened
*/
#include<iostream>

using namespace std;

void reverseArray(int arr[], int arrSize);

void printArray(int arr[], int arrSize);

void splitParity(int arr[], int arrSize);

void removeOdd(int arr[], int & arrSize);

int main()
{
    // Declare three arrays
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;
    
    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;
    
    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;
    
    // Reverse arr1 and print the result
    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);
    
    // Remove odd numbers from arr2 and print the result
    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);
    
    // Split arr3 by parity and print the result
    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);

    return 0;
}

// Implementation of reverseArray method
void reverseArray(int arr[], int arrSize)
{
    int tempValue;
    int i = 0;
    
    // Iterate through the first half of the array and swap values with their mirror on the second half
    while(i < arrSize / 2){
        tempValue = arr[i];
        arr[i] = arr[arrSize - i - 1];
        arr[arrSize - i - 1] = tempValue;
        i++;
    }
}

// Implementation of printArray method
void printArray(int arr[], int arrSize)
{
    // Iterate through the array and print each value followed by a space
    for (int i = 0; i < arrSize; i++){
        cout << arr[i] << ' ';
    }
    
    cout << endl;
}

// Implementation of splitParity method
void splitParity(int arr[], int arrSize)
{
    int left = 0; // Left pointer
    int right = arrSize - 1; // Right pointer
    
    while(left < right)
    {
        // Find the first even number from the left side
        while(left < right && arr[left] % 2 != 0){
            left++;
        }
        
        // Find the first odd number from the right side
        while(left < right && arr[right] % 2 == 0){
            right--;
        }
        
        // Swap the two numbers
        if(left < right){
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

// Implementation of removeOdd method
void removeOdd(int arr[], int& arrSize)
{
    int i = 0;
    int count = 0; // Counter for the number of odd numbers
    
    // Iterate through the array
    while(i < arrSize)
    {
        // If the number is even, move it to the left side of the array and increment i
        if(arr[i] % 2 == 0){
            arr[count] = arr[i];
            count++;
            i++;
        }
        // If the number is odd, skip it and decrement arrSize
        else{
            arrSize--;
            i++;
        }
    }
}