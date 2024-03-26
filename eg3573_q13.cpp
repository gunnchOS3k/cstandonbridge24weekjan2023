#include <iostream>
using namespace std;

int main(){

    //declare varibles
    int space;
    int rows;

    //get user input
    cout<<"Please enter a positive integer"<<endl;
    cin>>rows;

    // print pyramid with a nested for loop that prints the correct amount of space and asterics per row
    for(int i=1, k = 0 ; i <= rows ; ++i , k = 0){

        for(space=1; space <=2*rows-i; ++space){
            cout<<" ";
    

        }
        while(k != 2*i-1){
            cout<<"*";
            ++k;

        }
        cout<<endl;

    }


    return 0;
}