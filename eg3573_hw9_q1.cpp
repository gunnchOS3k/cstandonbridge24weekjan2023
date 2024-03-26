/*
Author: Edmund Gunn Jr
Assignment: hw9 NYU Tandon Bridge J Extened
*/
#include <iostream>
#include <string>

using namespace std;

// Function to analyze the given sentence
void analyzeSentence(string enteredText);

int main() {

    string enteredSentence;

    // Prompt the user to enter a sentence
    cout << "Please enter a line of text: " << endl;
    getline(cin,enteredSentence);

    // Call the function to analyze the entered sentence
    analyzeSentence(enteredSentence);

    return 0;
}

// Function to analyze the given sentence
void analyzeSentence(string enteredText){

    int wordCounter = 1; // Variable to store the word count, initialized to 1 since the first word is not preceded by a space
    int letters[26] = {0}; // Array to store the count of each letter in the sentence, initialized to 0
    int c; // Variable to store the index of the current letter being analyzed

    // Loop through each character in the entered sentence
    for(int i=0; i < enteredText.length(); i++){

        // If the current character is a space, increment the word count
        if(enteredText[i] == ' '){
            wordCounter++;
        }

        // If the current character is an alphabetic letter and not a space, increment the count for that letter in the letters array
        if(tolower(enteredText[i]) >= 'a' && tolower(enteredText[i]) <= 'z' && enteredText[i] != ' '){
            c = tolower(enteredText[i]) - 'a'; // Calculate the index of the current letter in the letters array
            letters[c]++; // Increment the count for the current letter
        }
    }

    // Output the word count
    cout << wordCounter << "\t" << "word(s)"<<endl;

    // Loop through each letter and output its count if it appears in the sentence
    for(int i=0 ; i < 26; i++){
        if(letters[i] > 0){
            cout << letters[i] << "\t" << char(i+'a') << endl;
        }
    }

}