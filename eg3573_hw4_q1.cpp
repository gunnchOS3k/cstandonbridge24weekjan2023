#include <iostream>
using namespace std;

int main(){
    
     //varible declaration
    int n;
    int count;
    int num;

    //get user input
    cout << "Please enter a positive integer: ";

    cin >> n;
    count = n;
    num = 0;
    //while loop outcome
    while(count>0){
        num = num + 2;
        cout << num << endl;
        count--;
    }
    num = 0;
    //for loop outcome
    for(count=n; count>0, count--;){
        num = num + 2;
        cout << num << endl;
    }


    return 0;
}