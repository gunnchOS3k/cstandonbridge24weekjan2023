/*
Author: Edmund Gunn Jr
Course: NYU Tandon Bridge Extended J term
Assignment: Hw10 Q3
*/
#include <iostream>
#include <vector>
using namespace std;
 
// Function prototypes
// Takes input from user to create an array of integers
int* createSequenceArr(int& sequenceArrSize);
// Takes input from user to create a vector of integers
vector<int> createSequenceVector(); 
// Searches for a given number in an array
void searchNumber(int* numArr, int numArrSize, int searchNum); 
// Searches for a given number in a vector
void searchNumberVector(vector<int> numsVector, int searchNum); 
// Function to run program using an array
int main1();
// Function to run program using a vector
int main2(); 


int main() {

    // Runs program using vector
  main2(); 

  return 0;
}

int main1(){

  int numberToSearch;

  int sequenceArrSize;
  // Creates array of integers based on user input
  int* numArr = createSequenceArr(sequenceArrSize); 

  cout << "Please enter a number you want to search: " << endl;
  cin >> numberToSearch;

    // Searches for user input in the array
  searchNumber(numArr, sequenceArrSize, numberToSearch); 
// Frees memory allocated for array
  delete [] numArr; 
  return 0;
}

int main2(){

  int numberToSearch;
  // Creates vector of integers based on user input
  vector<int> numsVector = createSequenceVector(); 

  cout << "Please enter a number you want to search: " << endl;
  cin >> numberToSearch;
  // Searches for user input in the vector
  searchNumberVector(numsVector, numberToSearch); 

  return 0;
}

// Function to create an array of integers based on user input
int* createSequenceArr(int& sequenceArrSize){
  int* numArr = new int[1];
  int numArrSize = 0;
  int numArrPhSize = 1;
   
  int currentEnteredNum;
 
  cout << "Please enter a sequence of positive integers, each in a separate line. End your input by typing -1." << endl;
 
  while(currentEnteredNum != -1){
    cin >> currentEnteredNum;
    if(numArrSize == numArrPhSize){
      int* newNumArr = new int[2*numArrPhSize];
      for(int i=0; i < numArrSize; i++){
        newNumArr[i] = numArr[i];
      }
      delete [] numArr;
      numArr = newNumArr;
      numArrPhSize *= 2;
    }
    numArr[numArrSize] = currentEnteredNum;
    numArrSize++;
  }
 
  sequenceArrSize = numArrSize;
  return numArr;
}
 
// Function to create a vector of integers based on user input
vector<int> createSequenceVector(){
  vector<int> numsVector;
  int currentEnteredNum;
 
  cout << "Please enter a sequence of positive integers, each in a separate line. End your input by typing -1." << endl;
 
  while(currentEnteredNum != -1){
    cin >> currentEnteredNum;
    numsVector.push_back(currentEnteredNum);
  }
 
  return numsVector;
}
 
void searchNumber(int* numArr, int numArrSize, int searchNum){
  cout << searchNum << " shows in line(s) ";
  for(int i = 0; i < numArrSize; i++){
    if(numArr[i] == searchNum){
      if(i == 0){
        cout << i+1;
      }else{
        cout << ", " << i+1;
      }
    }
  }
  cout << ".";
}

// Function to search for a given number in an array
void searchNumberVector(vector<int> numsVector, int searchNum){
  int it = 0;
  cout << searchNum << " shows in line(s) ";
  for(int i = 0; i < numsVector.size(); i++){
    if(numsVector[i] == searchNum){
      if(i == 0){
        cout << i+1;
      }else{
        cout << ", " << i+1;
      }
    }
  }
  cout << ".";
}