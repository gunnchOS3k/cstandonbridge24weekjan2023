/*
Author: Edmund Gunn Jr
Assignment: hw9 NYU Tandon Bridge J Extened
*/
#include <iostream>
 
using namespace std;
 
//Method 1 returns the base address of the array (containing the positive numbers), and updates the output parameter outPosArrSize with the array’s logical size.
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);

//Method 2 returns the base address of the array (containing the positive numbers), and uses the pointer outPosArrSizePtr to update the array’s logical size.
void getPosNums2(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);

//Method 3 updates the output parameter outPosArr with the base address of the array (containing the positive numbers), and the output parameter outPosArrSize with the array’s logical size.
int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr);

//Method 4 use the pointer outPosArrPtr to update the base address of the array (containing the positive numbers), and the pointer outPosArrSizePtr to update the array’s logical size.
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);

// Function to print an array
void printArray(int * arr, int arraySize);
 
int main() {
    
    // Define variables
    int size = 7;
    int arr[] = {3,-1,-3,-4,10,9,4};
    int posNum1NewSize;
 
    // Method 1
    int* posNum1;
    posNum1 = getPosNums1(arr, size, posNum1NewSize);

    // Display output
    cout << "getPosNums1 new arr address:  " << posNum1 << " - New Size: " << posNum1NewSize << endl;
    printArray(posNum1, posNum1NewSize);
 
    // Method 2
    int* outPosArr;
    int posNum2NewSize;
    getPosNums2(arr, size, outPosArr, posNum2NewSize);

    // Display output
    cout << "getPosNums2 new array address: " << outPosArr << endl;
    cout << "getPosNums2 function new array size: " << posNum2NewSize << endl;
    printArray(outPosArr, posNum2NewSize);
 
    // Method 3
    int* outPosArrSizePtr = &posNum2NewSize;
    int* posNum3;
    posNum3 = getPosNums3(arr, size, outPosArrSizePtr);
    
    // Display output
    cout << "getPosNums3 new array address: " << posNum3 << endl;
    cout << "getPosNums3 function new array size: " << *outPosArrSizePtr << endl;
    printArray(posNum3, *outPosArrSizePtr);
 
    // Method 4
    getPosNums4(arr, size, &posNum3, outPosArrSizePtr);
   
    // Display output
    cout << "getPosNums4 new array address: " << posNum3 << endl;
    cout << "getPosNums4 function new array size: " << *outPosArrSizePtr << endl;
    printArray(posNum3, *outPosArrSizePtr);
 
    // Free up memory
    delete [] posNum1;
    delete [] outPosArr;
    delete [] posNum3;
 
    return 0;
}

//Method 1 returns the base address of the array (containing the positive numbers), and updates the output parameter outPosArrSize with the array’s logical size.
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){
 
    // Create a new array of size equal to the input array size
    int* newPosArr = new int [arrSize];
    // Counter to keep track of the number of positive elements
    int counter = 0;
 
    // Iterate over the input array
    for(int i=0; i < arrSize; i++){
        // If the element is positive, add it to the new array and increment the counter
        if(arr[i] > 0){
            newPosArr[counter] = arr[i];
            counter++;
        }
    }
 
    // Update the output size parameter to be the number of positive elements
    outPosArrSize = counter;

    // Return the new array
    return newPosArr;
}

//Method 2 returns the base address of the array (containing the positive numbers), and uses the pointer outPosArrSizePtr to update the array’s logical size.
void getPosNums2 (int* arr, int arrSize, int*& outPosArr, int& outPosArrSize){
 
    // Call method 1 to get the positive numbers and their size
    outPosArr = getPosNums1(arr, arrSize,outPosArrSize);
 
}
 
//Method 3 updates the output parameter outPosArr with the base address of the array (containing the positive numbers), and the output parameter outPosArrSize with the array’s logical size.
int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr){

    // Create a new array of size equal to the output size parameter
    int* newArr = new int[(* outPosArrSizePtr)];
    // Counter to keep track of the number of positive elements
    int newArrPos = 0;
    // Iterate over the input array
    for(int i=0; i < arrSize; i++){
        // If the element is positive, add it to the new array and increment the counter
        if(arr[i] > 0){
            newArr[newArrPos] = arr[i];
            newArrPos++;
        }
    }
    // Return the new array
    return newArr;
}

//Method 4 use the pointer outPosArrPtr to update the base address of the array (containing the positive numbers), and the pointer outPosArrSizePtr to update the array’s logical size.
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr){
    // Create a new array of size equal to the output size parameter
    *outPosArrPtr = new int[*outPosArrSizePtr];
    // Counter to keep track of the number of positive elements
    int newArrPos = 0;

    // Iterate over the input array
    for(int i=0; i < arrSize; i++){
        if(arr[i] > 0){
            (*outPosArrPtr)[newArrPos] = arr[i];
            newArrPos++;
        }
    }
}

// Function to print an array
void printArray(int * arr, int arraySize){
    cout <<"Positive Values: ";
    for(int i=0; i < arraySize; i++){
        cout << arr[i] << " ";
    }
    cout << endl<<endl;
}