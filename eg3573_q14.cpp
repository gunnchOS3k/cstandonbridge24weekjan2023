#include <iostream>
#include <string>
using namespace std;

int main(){

    //declare varibales
    int user_input;
    int groupATotal, groupBTotal, groupCTotal, groupDTotal;
    string strcheck;

    //get user input
    cout<<"Please enter a sequence of numbers (with at least 1-digit and at most 8-digits), each one in a separate line. End your sequence by typing -1:";
    cin>>user_input;
    strcheck = to_string(user_input);
    
    // while loop to total the the amount of user 
    while(user_input != -1){
        if(user_input < 0 and user_input > 10){
        groupATotal++;
        }
        else if(user_input < 10 and user_input > 20){
            groupBTotal++;
        }
        else if(user_input < 20 and user_input > 30){
            groupBTotal++;
        }
        else if(user_input <= 30){
            groupBTotal++;
        }

    }

    //display result to user
    

    cout<<"Total count of numbers in the Numbers Group 1: "<<groupATotal;
    cout<<"Total count of numbers in the Numbers Group 2: "<<groupBTotal;
    cout<<"Total count of numbers in the Numbers Group 3: "<<groupCTotal;
    cout<<"Total count of numbers in the Numbers Group 4: "<<groupDTotal;
    return 0;
}