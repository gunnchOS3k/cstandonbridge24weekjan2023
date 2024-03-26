/*
Author: Edmund Gunn Jr
Assignment: hw8 NYU Tandon Bridge J Extened
*/
#include <iostream>
#include <string>
using namespace std;

// Declare the function isPalindrome that accepts a string parameter and returns a boolean
bool isPalindrome(string str);

int main() {
    string word;

    // Prompt the user to enter a word and store it in the variable
    cout << "Please enter a word: ";
    cin >> word;

    // Check if the entered word is a palindrome using the isPalindrome function
    if (isPalindrome(word)) {
        cout << word << " is a palindrome" << endl;
    } else {
        cout << word << " is not a palindrome" << endl;
    }

    return 0;
}

// The isPalindrome function takes a string parameter and checks if it's a palindrome
bool isPalindrome(string str) {
    // Get the length of the string
    int len = str.length();
    // Loop through half of the string's length
    for (int i = 0; i < len/2; i++) {
        // Check if the characters at the beginning and end of the string are the same
        if (str[i] != str[len-1-i]) {
            // If they're not the same, return false
            return false;
        }
    }
    // If the loop completes without returning false, the string is a palindrome so return true
    return true;
}