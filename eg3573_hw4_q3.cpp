#include <iostream>
#include <string>
using namespace std;

int main(){
     //varible declaration
    int decimal; 
    int input;
    int remain;
    int binary_count = 0;
    int bin;

    string binary = "", bit = "";
    // get user input
    cout << "Enter decimal number:" << endl;
    cin >> input;

    decimal = input;

    remain = 1;

    //while loop to calculate results
    while(decimal > 0){
        bin = decimal % 2;
        decimal = decimal / 2;
        bit = to_string(bin);
        binary = to_string(bin) + binary;
    }


    //to_string(1) = "1"

    //display results
    cout << "The binary representation of " << input << " is " << binary << endl;


    return 0;
}