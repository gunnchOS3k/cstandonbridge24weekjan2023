#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int main()
{
    //varible declaration
    const int Underweight = 1;
    const int Normal = 2;
    const int Overweight = 3;
    const int Obese = 4;
    int weight;
    int height;
    int bmiClassfifcation;
    float bmiValue;
    float weightKilo;
    float heightMeter;

    
    //get user input
    cout<<"Please enter weight (in pounds): ";
    cin>>weight;
    cout<<endl;
    cout<<"Please enter height (in inches): ";
    cin>>height;
    cout<<endl;

    
    //input based calulation
    weightKilo= weight *0.453592;
    heightMeter= height*0.0254;
    bmiValue = weightKilo / (heightMeter*heightMeter);


    //if statments to determine results
    if(bmiValue < 18.5)
    {
        bmiClassfifcation = Underweight;
    }
    else if ( 18.5 < bmiValue < 25.0)
    {
        bmiClassfifcation = Normal;
    }
    else if ( 25.0 < bmiValue < 30.0)
    {
        bmiClassfifcation = Overweight;
    }
    else if (30.0 < bmiValue)
    {
        bmiClassfifcation = Obese;
    }


    //switch-statment to display final results based on results from if-statment
    switch (bmiClassfifcation)
    {
    case Underweight:
        cout<<"The weight status is: Underweight";
        break;
    case Normal:
        cout<<"The weight status is: Normal";
        break;
    case Overweight:
        cout<<"The weight status is: Overweight";
        break;
    case Obese:
        cout<<"The weight status is: Obese";
        break;
    }



    
    return 0;
}