/*
Author: Edmund Gunn Jr
Assignment: hw8 NYU Tandon Bridge J Extened
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int PIN_LENGTH = 5;
const int NUM_DIGITS = 10;

// Function prototypes
void generateRandomMapping(int mapping[]);
bool authenticatePIN(int pin, int mapping[]);

int main() {
    // Seed the random number generator
    srand(time(0));

    // Define the PIN number
    const int PIN = 12345;

    // Generate the random mapping
    int mapping[NUM_DIGITS];
    generateRandomMapping(mapping);

    // Display the mapping
    cout << "Please enter your PIN according to the following mapping:\n";
    cout << "PIN: 0123456789\nNUM: ";
    for (int i = 0; i < NUM_DIGITS; i++) {
        cout << mapping[i];
    }
    cout << endl;

    // Prompt the user for input
    int response;
    cin >> response;

    // Authenticate the PIN
    if (authenticatePIN(PIN, mapping)) {
        cout << "Your PIN is correct\n";
    } else {
        cout << "Your PIN is not correct\n";
    }

    return 0;
}

// Generates a random mapping of digits 0-9 to values 1-3
void generateRandomMapping(int mapping[]) {
    for (int i = 0; i < NUM_DIGITS; i++) {
        mapping[i] = rand() % 3 + 1;
    }
}

// Authenticates a PIN number using the specified mapping
bool authenticatePIN(int pin, int mapping[]) {
    // Convert the PIN number to an array of digits
    int pinArray[PIN_LENGTH];
    for (int i = PIN_LENGTH - 1; i >= 0; i--) {
        pinArray[i] = pin % 10;
        pin /= 10;
    }

    // Compare the PIN digits to the mapping digits
    for (int i = 0; i < PIN_LENGTH; i++) {
        if (mapping[pinArray[i]] != cin.get()) {
            return false;
        }
    }

    return true;
}
