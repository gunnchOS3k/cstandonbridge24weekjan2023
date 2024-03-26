/*
Author: Edmund Gunn Jr
Assignment: hw9 NYU Tandon Bridge J Extened
*/
#include <iostream>
using namespace std;


void oddsKeepEvensFlip(int arr[], int arrSize) {
    // initialize two pointers: i for odd numbers, j for even numbers
    int i = 0, j = arrSize - 1; 
    // while there are still numbers to swap
    while (i < j) { 
        // find the first even number from the left skip odd numbers, which are already in place
        while (i < arrSize && arr[i] % 2 != 0) {
            
            i++;
        }
        // find the first odd number from the right skip even numbers, which are already in place in reverse order
        while (j >= 0 && arr[j] % 2 == 0) {
            j--;
        }
        if (i < j) {
            // if we found an even number before an odd number,swap them and advance both pointers
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    // start index of even numbers
    int start = i;
    // end index of array
    int end = arrSize - 1;
    // reverse the even numbers swap the first and last even numbers, then move inward
    while (start < end) { 
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main() {
    // initialize the array
    int arr[] = {5, 2, 11, 7, 6, 4};
    // compute array size
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    cout << "Before: ";
    for (int i = 0; i < arrSize; i++) {
        // print the array before calling oddsKeepEvensFlip
        cout << arr[i] << " "; 
    }
    cout << endl;
    // call the function to reorder the array
    oddsKeepEvensFlip(arr, arrSize); 
    cout << "After: ";
    for (int i = 0; i < arrSize; i++) {
        // print the array after calling oddsKeepEvensFlip
        cout << arr[i] << " "; 
    }
    cout << endl;
    return 0; 
}