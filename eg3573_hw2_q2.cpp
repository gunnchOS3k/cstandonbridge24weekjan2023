/*
Author: Edmund Gunn Jr
Assignment: hw2 NYU Tandon Bridge J Extened
*/
#include <iostream>
using namespace std;

int main()
{
    //varible declaration
    int penniesInput;
    int penniesCalculated;
    int nicklesInput;
    int nicklesCalculated;
    int dimesInput;
    int dimesCalculated;
    int quatersInput;
    int quatersCalculated;
    int dollarsInput;
    int dollarsCalculated;
    int coinsInput;
    int coinsCalculated;
    int coinsRemaining;
    int moneySum;
    int totDollars;
    int totCoins;
    
    


    // get user input
    cout<<"Please enter your amount in the format of dollars and cents separated by	a space: "<<endl;
    cin>>dollarsInput>>coinsInput;
    dollarsCalculated = dollarsInput * 100;
    coinsCalculated = dollarsCalculated + coinsInput;

    // covert units and sort change
    quatersCalculated = coinsCalculated / 25;
    coinsRemaining = coinsCalculated - (quatersCalculated * 25);

    dimesCalculated = coinsRemaining / 10;
    coinsRemaining = coinsRemaining - (dimesCalculated * 10);

    nicklesCalculated = coinsRemaining / 5;
    coinsRemaining = coinsRemaining - (nicklesCalculated * 5);

    penniesCalculated = coinsRemaining / 1;
    coinsRemaining = coinsRemaining - (penniesCalculated * 1);

    // display results
    cout<<dollarsInput<<" dollars, "<<coinsInput<<" cents are:"<<endl;
    cout<<quatersCalculated<<" quarters, "<<dimesCalculated<<" dimes, "<<nicklesCalculated<<" nickles and "<<penniesCalculated<<" pennies"<<endl;



    return 0;
}