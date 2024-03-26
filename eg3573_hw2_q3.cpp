/*
Author: Edmund Gunn Jr
Assignment: hw2 NYU Tandon Bridge J Extened
*/
#include <iostream>
using namespace std;

int main()
{
    //varible declaration
    int minsJohnInput;
    int minsJohnCalculated;
    int hoursJohnInput;
    int hoursJohnCalculated;
    int daysJohnInput;
    int daysJohnCalculated;

    int minsBillInput;
    int minsBillCalculated;
    int hoursBillInput;
    int hoursBillCalculated;
    int daysBillInput;
    int daysBillCalculated;

    int minsTotal;
    int minsRemaining;
    int hoursTotal;
    int daysTotal;
    int minsTotalCalculated;
    int hoursTotalCalculated;
    int daysTotalCalculated;

    //get user input
    cout<<"Please enter the	number	of days John has worked:";
    cin>>daysJohnInput;
    cout<<endl;
    cout<<"Please enter	the	number of hours	John has worked: ";
    cin>>hoursJohnInput;
    cout<<endl;
    cout<<"Please enter the	number of minutes John has worked: ";
    cin>>minsJohnInput;
    cout<<endl;

    cout<<"Please enter the	number	of days Bill has worked:";
    cin>>daysBillInput;
    cout<<endl;
    cout<<"Please enter	the	number of hours	Bill has worked: ";
    cin>>hoursBillInput;
    cout<<endl;
    cout<<"Please enter the	number of minutes Bill has worked: ";
    cin>>minsBillInput;
    cout<<endl;
    
    // stanardize units
    daysTotal = daysJohnInput + daysBillInput;
    hoursTotal = hoursJohnInput + hoursBillInput;
    minsTotal = minsJohnInput + minsBillInput + (hoursTotal * 60) + (daysTotal * 1440);

    //calculate time
    daysTotalCalculated = minsTotal / 1440;
    minsRemaining = minsTotal - (daysTotalCalculated * 1440);

    hoursTotalCalculated = minsRemaining / 60;
    minsRemaining = minsRemaining - (hoursTotalCalculated * 60);

    minsTotalCalculated = minsRemaining / 1;
    minsRemaining = minsRemaining - (minsTotalCalculated * 1);

    //display results
    cout<<"The total time both of them worked together is: "<<daysTotalCalculated<<endl<<"  days,  "<<hoursTotalCalculated<<" hours and "<<minsTotalCalculated<<" minutes."<<endl;


    return 0;
}