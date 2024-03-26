/*
Author: Edmund Gunn Jr
Assignment: hw8 NYU Tandon Bridge J Extened
*/
#include <iostream>
#include <string>

using namespace std;

// function to check if a character is a digit
bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

// function to replace digits in a given string with 'x'
string replaceDigits(string str) {
    for (int i = 0; i < str.length(); i++) {
        // if the current character is a digit and it's not part of a word
        if (isDigit(str[i]) && (i == 0 || !isalnum(str[i-1]))) {
            str[i] = 'x'; // replace the digit with 'x'
        }
    }
    return str;
}

int main() {
    string text;
    cout << "Please enter a line of text: ";
    getline(cin, text); // read in the entire line of text
    
    string result = replaceDigits(text); // replace digits with 'x'
    
    cout << result << endl; // print the modified text
    
    return 0;
}