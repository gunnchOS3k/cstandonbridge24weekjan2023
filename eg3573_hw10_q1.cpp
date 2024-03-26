/*
Author: Edmund Gunn Jr
Course: NYU Tandon Bridge Extended J term
Assignment: Hw10 Q1
*/
 
#include <iostream>
#include <string>
using namespace std;

// declare function to create an array of words
string* createWordsArray(string sentence, int& outWordsArrSize); 
// declare function to print elements of an array
void printArrElem(string* arr, int arrSize); 
 
int main() {
    string sentenceEntered;
    int outWordsArrSize;
    string* stringArr;
 
    cout << "Enter a sentence: ";
    getline(cin, sentenceEntered); 

    // call function to create array of words
    stringArr = createWordsArray(sentenceEntered, outWordsArrSize); 
    
    // call function to print elements of the array
    printArrElem(stringArr, outWordsArrSize); 
    
    // deallocate the memory used for the array
    delete [] stringArr; 
}
 
string* createWordsArray(string sentence, int& outWordsArrSize){
    // dynamically allocate memory for an array of strings with size 1
    string* wordsArray = new string [1]; 
    
    // initialize physical size of the array
    int arrPhysicalSize = 1;
    // initialize the index of the sentence
    int i = 0; 
    // initialize a string to store each word temporarily
    string word; 
 
     // initialize the counter for the number of words found
    int wordCounter = 0;
    // get the length of the sentence
    int sentenceLength = sentence.length(); 

    // loop through each character in the sentence
    while(sentenceLength >= 0){ 
    // if a space or end of string is encountered
        if(sentence[i] == ' ' || sentence[i] == '\0'){ 
            // if a word has been found
            if(wordCounter > 0){ 
                // dynamically allocate memory for a new array of strings
                string* newLinesArr; 
                // double the physical size of the new array
                newLinesArr = new string[arrPhysicalSize*2]; 
                 // copy the old array to the new array
                for(int i = 0; i < wordCounter; i++)
                    newLinesArr[i] = wordsArray[i];
                // deallocate memory used by the old array
                delete []wordsArray; 
                // update pointer to the new array
                wordsArray = newLinesArr; 
                 // update the physical size of the array
                arrPhysicalSize *= 2;
            }
            // store the current word in the array
            wordsArray[wordCounter] = word; 
            // increment the word counter
            wordCounter++; 
            // reset the word string to an empty string
            word = ""; 
        } else {
            // add the current character to the temporary word string
            word += sentence[i]; 
        }
        // move to the next character in the sentence
        i++;
        // decrement the length of the sentence
        sentenceLength--; 
    }

    // set the size of the output array
    outWordsArrSize = wordCounter; 
    
    // return the pointer to the array of words
    return wordsArray; 
}
 
void printArrElem(string* arr, int arrSize){
    // print the size of the array
    cout << "New Size: " << arrSize << endl; 
     // start printing the elements of the array
    cout << "[";
    // loop through each element of the array
    for(int i=0; i < arrSize; i++){ 
        // print the element in single quotes
        cout << "'" << arr[i] << "'"; 
        // if not the last element, add a comma separator
        if(i != arrSize - 1){ 
            cout << ",";
        }
    }
    // finish printing the array elements
    cout << "]"; 
}
