/*
Author: Edmund Gunn Jr
Assignment: hw8 NYU Tandon Bridge J Extened
*/
#include <iostream>
using namespace std;

int minInArray(int arr[], int arrSize);

int main() {
    const int ARRAY_SIZE = 20;
    int arr[ARRAY_SIZE];
    int minVal;

    // Read in 20 integers
    cout << "Please enter 20 integers separated by a space: ";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cin >> arr[i];
    }

    // Find the minimum value and its indices
    minVal = minInArray(arr, ARRAY_SIZE);
    cout << "The minimum value is " << minVal << ", and it is located in the following indices: ";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (arr[i] == minVal) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}

int minInArray(int arr[], int arrSize) {
    int minVal = arr[0];
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}
