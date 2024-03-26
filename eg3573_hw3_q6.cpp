#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int main()
{
     //varible declaration
    const int weekDay = 1;
    const int weekNight = 2;
    const int weekEnd = 3;

    int weight;
    int height;
    int callClassfifcation;
    string militaryTime;
    string dayOfWeek;
    int callLength;
    int hours;
    int mins;
    int pos;
    float callCost;
    string subMin;
    string subHour;

    
    //get user input
    cout<<"Please enter time of call (in 24hr format): ";
    cin>>militaryTime;
    cout<<endl;
    cout<<"Please enter day of week (in Mo Tu We Th Fr Sa Su): ";
    cin>>dayOfWeek;
    cout<<endl;
    cout<<"Please enter call length (in mins): ";
    cin>>callLength;
    cout<<endl;


    //input based string manipulation
    pos = militaryTime.find(":");
    subMin = militaryTime.substr(pos + 1);
    mins = stoi(subMin);
    subHour = militaryTime.substr(0,pos);
    hours = stoi(subHour);

    
    //if statments to determine results
    if( (8< hours and hours <18)and dayOfWeek !="Sa" and dayOfWeek !="Su" )
    {
        callCost = callLength*.40;
        callClassfifcation=1;
    }
    else if ( ((1<hours and hours<8) or (18<hours and hours<23))  and (dayOfWeek !="Sa" and dayOfWeek !="Su") )
    {
        callCost = callLength*.25;
        callClassfifcation=2;
    }
    else if ( (dayOfWeek == "Sa") or (dayOfWeek == "Su"))
    {
        callCost = callLength*.15;
        callClassfifcation=3;
    }


    //switch-statment to display final results based on results from if-statment
    switch (callClassfifcation)
    {
    case weekDay:
        cout<<"The Call during business hours will cost: $"<<callCost<<endl;
        break;
    case weekNight:
        cout<<"The Call weekdays after hours will cost: $"<<callCost<<endl;
        break;
    case weekEnd:
        cout<<"The Call during weekends will cost: $"<<callCost<<endl;
        break;
    }

    
    return 0;
}