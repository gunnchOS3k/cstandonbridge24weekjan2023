/*
Author: Edmund Gunn Jr
Assignment: hw9 NYU Tandon Bridge J Extened
*/
#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE_ARR = 52; //assuming strings contain english alphabet only

// Function to determine if two sentences are anagrams
bool areSentencesAnagram(char* sentence1, char* sentence2);

int main() {

    string firstSentenceEntered;
    string secondSentenceEntered;

    // Prompt the user to enter two sentences to compare
    cout << "Find out if two sentences are anagrams." << endl;
    cout << "Enter the first sentence: ";
    getline(cin, firstSentenceEntered);
    cout << "Enter the second sentence: ";
    getline(cin, secondSentenceEntered);

    // Convert the entered sentences to character arrays
    char * string1 = new char[firstSentenceEntered.length()];
    char * string2 = new char[secondSentenceEntered.length()];

    for(int i=0; i <= firstSentenceEntered.length(); i++){
        string1[i] = firstSentenceEntered[i];
    }

    for(int i=0; i <= secondSentenceEntered.length(); i++){
        string2[i] = secondSentenceEntered[i];
    }

    // Check if the two sentences are anagrams
    if(areSentencesAnagram(string1,string2)){
        cout << "The two strings are anagrams.";
    }else{
        cout << "The two strings are NOT anagrams.";
    }

    // Free the dynamically allocated memory
    delete [] string1;
    delete [] string2;

    return 0;
}

// Function to determine if two sentences are anagrams
bool areSentencesAnagram(char* sentence1, char* sentence2){

    int count[MAX_SIZE_ARR] = {0}; // Array to store the count of each character in the two sentences
    int i;

    // Loop through each character in both sentences and increment the count for that character in the count array
    for( i=0; sentence1[i] && sentence2[i]; i++){
        count[sentence1[i]]++; // Increment the count for the current character in the first sentence
        count[sentence2[i]]--; // Decrement the count for the current character in the second sentence
    }

    // Check if there are any remaining characters in either sentence
    if(sentence1[i] || sentence2[i]){
        return false;
    }

    // Loop through each character in the count array and check if its count is zero
    for(i=0; i < MAX_SIZE_ARR; i++){
        if(count[i])
            return false;
    }

    return true;
}