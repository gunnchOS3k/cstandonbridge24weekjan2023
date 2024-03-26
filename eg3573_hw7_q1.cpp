/*
Author: Edmund Gunn Jr
Assignment: hw7 NYU Tandon Bridge J Extened
*/
#include <iostream>
using namespace std;
 
//declare functions
int printMonthCalendar(int numOfDays, int startingDay);
bool leapYear (int year);
void printYearCalendar(int year, int startingDay);
 
 //intizlize print calader function
int printMonthCalendar(int numOfDays, int startingDay){
 
    cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun" << endl;
 
    int currentDay, lastDay;
    int counter = 1;
 
    for(int cell = 1; currentDay < numOfDays; cell++){
 
        currentDay = cell - startingDay + 1;
 
        if(currentDay >= 1){
            cout << currentDay;
        }
 
        if(cell % 7 == 0){
            cout << endl;
        }else{
            cout << "\t";
        }
 
        counter++;
    }
 
    lastDay = (counter - 1) % 7;
 
    return lastDay;
 
}
//intizlize leap year check
bool leapYear (int year){
 
    if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0 ))
        return true;
 
    return false;
}
//intizlize year calander
void printYearCalendar(int year, int startingDay){
 
    bool isLeapYear;
 
    int daysInMonth = 0;
    int lastDay;
 
    isLeapYear = leapYear(year);
 
    for(int month = 1; month <= 12; month++){
 
        if(month == 1){
 
            cout << "January " << year << endl;
            daysInMonth = 31;
 
        }else if(month == 2){
 
            cout << "February " << year << endl;
            if(isLeapYear){
                daysInMonth = 29;
 
            }else{
                daysInMonth = 28;
            }
 
        }else if(month == 3){
 
            cout << "March " << year << endl;
            daysInMonth = 31;
 
        }else if(month == 4){
 
            cout << "April " << year << endl;
            daysInMonth = 30;
 
        }else if(month == 5){
 
            cout << "May " << year << endl;
            daysInMonth = 31;
 
        }else if(month == 6){
 
            cout << "June " << year << endl;
            daysInMonth = 30;
 
        }else if(month == 7){
 
            cout << "July " << year << endl;
            daysInMonth = 31;
 
        }else if(month == 8){
 
            cout << "August " << year << endl;
            daysInMonth = 31;
 
        }else if(month == 9){
 
            cout << "September " << year << endl;
            daysInMonth = 30;
 
        }else if(month == 10){
 
            cout << "October " << year << endl;
            daysInMonth = 31;
 
        }else if(month == 11){
 
            cout << "November " << year << endl;
            daysInMonth = 30;
 
        }else{
            cout << "December " << year << endl;
            daysInMonth = 31;
        }
 
        lastDay = printMonthCalendar(daysInMonth, startingDay);
 
        startingDay = lastDay + 1;
 
        cout << endl << endl;
    }
 
}

//main function
int main() {
 
    int yearEntered, startingDayEntered;
 
    cout << "Enter a year and the starting day: ";
    cin >> yearEntered >> startingDayEntered;
 
    printYearCalendar(yearEntered,startingDayEntered);
 
    return 0;
}