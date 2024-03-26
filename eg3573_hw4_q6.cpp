#include <iostream>
using namespace std;

int main (){
    //varible declaration
    const int start = 1;
    int n;
    int digit;
    int remain;
    int num;
    int integer;
    int evenc;
    int oddc;
    int test;

    
    //get user input
    cout << "Please enter a positive integer." << endl;
    cin >> n;


    evenc = 0;
    oddc = 0;
    
    //nested loop to display results 
    for(num=1; num <= n; num++){
        integer = num;
        remain = 1;
        while(remain != 0){
            digit = integer % 10;
            remain = integer / 10;
            test = digit % 2;
            integer = remain;
            if(test == 0){
                evenc++;
            }
            else{
                oddc++;
            }
        }
        if(evenc>oddc){
            cout << num << endl;
        }
        evenc = 0;
        oddc = 0;

    }

    return 0;
}