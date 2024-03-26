#include <iostream>
#include <cmath>
using namespace std;

int main (){
     //varible declaration
    float length;
    float c;
    float power;
    float result;
    float geo;
    float seq;

//part a
    std::cout.precision(5); 
    cout << "Please enter the length of your sequence.";
    cin >> length;
    geo = 1;
    power = 1/length;
    cout << "Please enter your sequence:" << endl;
    for(c=length; c>0; c--){
        cin >> seq;
        geo = geo * seq;
    }
    result = pow(geo, power);

    cout << "The geometric mean is: " << result << endl;
    //resetting variables
    geo = 1;
    length = 0;
//part b

    cout << "Please enter a non-empty sequence of positive integers, each one in a separate line. End your"<< endl;
    cout << "sequence by typing -1:" << endl;
    while(seq != -1){
        cin >> seq;
        if(seq != - 1){
            geo = geo * seq;
            length++;
        }
    }
    power = 1/length;
    result = pow(geo, power);

    cout << "The gemoetric mean is: " << result << endl;

    return 0;
}