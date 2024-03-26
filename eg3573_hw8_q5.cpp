/*
Author: Edmund Gunn Jr
Assignment: hw8 NYU Tandon Bridge J Extened
*/
#include <iostream>
#include <string>

using namespace std;

#include <iostream>
#include <string>

using namespace std;

int main() {
    string first_name, middle_name, last_name;

    // Read input in the given format
    cout << "Enter your name in the format First_Name, Middle_Name/Initial, Last_Name: ";
    cin >> first_name >> middle_name >> last_name;

    // Format the name and output it
    cout << last_name << ", " << first_name << " " << middle_name.at(0) << "." << endl;

    return 0;
}