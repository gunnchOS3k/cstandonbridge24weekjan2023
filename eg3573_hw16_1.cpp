/*
Author: Edmund Gunn Jr
Course: NYU Tandon Bridge Extended J term
Assignment: Hw16 Problem 1
*/
#include <iostream>
#include <fstream>
#include <stack>
#include <string>

// Function to check if the opening and closing symbols match
bool isMatchingPair(const std::string& open, const std::string& close) {
    return (open == "begin" && close == "end") ||
           (open == "{" && close == "}") ||
           (open == "[" && close == "]") ||
           (open == "(" && close == ")");
}

// Function to check if the Pascal symbols in the file are balanced
bool isPascalSymbolBalanced(std::ifstream& file) {
    std::stack<std::string> symbolStack; // Stack to store the opening symbols
    std::string word; // String to store the words read from the file

    // Read words from the file
    while (file >> word) {
        // Check if the word is an opening symbol and push it onto the stack
        if (word == "begin" || word == "{" || word == "[" || word == "(") {
            symbolStack.push(word);
        } else if (word == "end" || word == "}" || word == "]" || word == ")") {
            // Check if the stack is empty or the symbols do not match
            if (symbolStack.empty() || !isMatchingPair(symbolStack.top(), word)) {
                return false;
            }
            // Pop the matching opening symbol from the stack
            symbolStack.pop();
        }
    }

    // If the stack is empty, the symbols are balanced
    return symbolStack.empty();
}

int main() {
    std::string filename;
    std::cout << "Enter the file name: ";
    std::cin >> filename;

    std::ifstream file(filename); // Open the input file

    // Check if the file is open
    if (file.is_open()) {
        // Check if the Pascal symbols are balanced
        if (isPascalSymbolBalanced(file)) {
            std::cout << "The symbols are balanced." << std::endl;
        } else {
            std::cout << "The symbols are not balanced." << std::endl;
        }
        file.close(); // Close the input file
    } else {
        std::cout << "Unable to open the file." << std::endl;
    }

    return 0;
}
