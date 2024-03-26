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
    int moneySum;
    int totDollars;
    int totCoins;
    
    // get user input
    cout<<"Please enter number of coins: "<<endl;
    cout<<"# of quaters: ";
    cin>>quatersInput;
    cout<<endl;
    cout<<"# of dimes: ";
    cin>>dimesInput;
    cout<<endl;
    cout<<"# of nickles: ";
    cin>>nicklesInput;
    cout<<endl;
    cout<<"# of pennies: ";
    cin>>penniesInput;
    cout<<endl;

    // calculating amount of money the amount of coins
    quatersCalculated = quatersInput * 25; 
    dimesCalculated = dimesInput * 10; 
    nicklesCalculated = nicklesInput * 5; 
    penniesCalculated = penniesInput * 1; 
    moneySum  =   quatersCalculated + dimesCalculated + nicklesCalculated + penniesCalculated;
    // find total
    totDollars =  moneySum/100;
    totCoins = moneySum%100;

    // display results
    cout<<"The total is "<<totDollars<<" dollars and "<<totCoins<<" cents"<<endl;

    return 0;
}