#include<iostream>
#include<string>
using namespace std;

int main()
{
     //varible declaration
    int gradYear;
    int currentYear;
    string studentName;
    int yearDif;
    string studentClassification;

    
    //get user input
    cout<<"Please enter your name: ";
    cin>>studentName;
    cout<<endl;
    cout<<"Please enter your graduation year: ";
    cin>>gradYear;
    cout<<endl;
    cout<<"Please enter current year: ";
    cin>>currentYear;
    cout<<endl;


    //input based calcultion
    yearDif = gradYear - currentYear;


    //if-statements to determine results
    if(yearDif>=5){
        studentClassification = "not in college yet";
    }
    else if (yearDif==4)
    {
        studentClassification = "Freshman";
    }
    else if (yearDif==3)
    {
        studentClassification = "Sophmore";
    }
    else if (yearDif==2)
    {
        studentClassification = "Junior";
    }
    else if (yearDif==1)
    {
        studentClassification = "Senior";
    }
    else{
        studentClassification = "Graduated"; 
    }


    //display results to user
    cout<<studentName<<", you are a "<<studentClassification;
    cout<<endl;
    return 0;
}