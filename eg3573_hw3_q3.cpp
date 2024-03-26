#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int main()
{
     //varible declaration
    double valA;
    double valB;
    double valC;
    double discriminant;
    double realSoltuionOne;
    double realSoltuionTwo;
    string numberOfSolutions;


    
    //get user input
    cout<<"Please enter value of a: ";
    cin>>valA;
    cout<<endl;
    cout<<"Please enter value of b: ";
    cin>>valB;
    cout<<endl;
    cout<<"Please enter value of c: ";
    cin>>valC;
    cout<<endl;


    //input based calcualtion calculate
    discriminant = (valB*valB) - (4*valA*valC);


    //if statments to determine how many solutions are avaible and display results
    if(valA==0 and valB==0 and valC==0){
        cout<<"This equation has infiinite number of solutions"<<endl;    
    }
    else if (valA==0 and valB==0)
    {
        cout<<"This equation has no solutions"<<endl;
    }
    else if (valB==0)
    {
        cout<<"This equation has no real solution"<<endl;
    }
    else if (discriminant == 0)
    {
        realSoltuionOne = ((-valB) + sqrt(discriminant)) /(2*valA);
        cout<<"This equation has 1 real solution x="<<realSoltuionOne;
    }
    else if (discriminant>0)
    {
        realSoltuionOne = ((-valB) + sqrt(discriminant)) /(2*valA);
        realSoltuionTwo = ((-valB) - sqrt(discriminant)) /(2*valA);
        cout<<"This equation has 2 real solutions x="<<realSoltuionOne<<" and "<<realSoltuionTwo;

    }
    
    
    return 0;
}