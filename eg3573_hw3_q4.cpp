#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int main()
{
     //varible declaration
    const int FLOOR_ROUND = 1;
    const int CEILING_ROUND = 2;
    const int ROUND = 3;
    int operationVal;
    double realNumber;
    double roundedNumber;



    
    //get user input
    cout<<"Please enter a Real number: ";
    cin>>realNumber;
    cout<<endl;
    cout<<"Choose your rounding method: ";
    cout<<endl;
    cout<<"1. Floor round";
    cout<<endl;
    cout<<"2. Ceiling round";
    cout<<endl;
    cout<<"3. Round to the nearest whole number";
    cout<<endl;
    cin>>operationVal;
    cout<<endl;

    
    //switch statment make calculations based on option menu
    switch (operationVal)
    {
    case FLOOR_ROUND:
        roundedNumber = floor(realNumber);
        break;
    case CEILING_ROUND:
        roundedNumber = ceil(realNumber);
        break;
    case ROUND:
        roundedNumber = round(realNumber);
        break;
    }


    //display results
    cout<<roundedNumber;

    
    return 0;
}