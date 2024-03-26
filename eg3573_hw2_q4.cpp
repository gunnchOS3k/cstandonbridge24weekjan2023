#include <iostream>
using namespace std;

int main()
{
     //varible declaration
    int numOne;
    int numTwo;
    float numOneF;
    float numTwoF;
    int sum;
    int differnce;
    int product;
    float quoitentWithRem;
    int quoitentNoRem;
    int mod;

    //get user input
    cout<<"Please enter the	number	of days John has worked:";
    cin>>numOne>>numTwo;

    ////calculate results
    numOneF = numOne;
    numTwoF = numTwo;
    sum = numOne + numTwo ;
    differnce = numOne - numTwo;
    product = numOne * numTwo;
    quoitentNoRem = numOne / numTwo;
    quoitentWithRem = numOneF / numTwoF;
    mod = numOne % numTwo;

    //display results
    cout<<"Please enter the	number	of days Bill has worked:"<<sum<<endl;
    cout<<"Please enter the	number	of days Bill has worked:"<<differnce<<endl;
    cout<<"Please enter the	number	of days Bill has worked:"<<product<<endl;
    cout<<"Please enter the	number	of days Bill has worked:"<<quoitentNoRem<<endl;
    cout<<"Please enter the	number	of days Bill has worked:"<<quoitentWithRem<<endl;
    cout<<"Please enter the	number	of days Bill has worked:"<<mod<<endl;

    return 0;
}