#include <iostream> 
#include <stdlib.h>  
#include <cmath>
#include <time.h>
using namespace std;

int main() {

    //declare varibles and cosntants
    srand(time(0));
    int x1, x2, x3,guess, x4;
    x1 = rand();
    x2 = rand();
    x3 = rand() % 100;
    x4 = (rand() % 100) + 1;

    int counts=5,l=1,h=100;

    // nested  loop to count how many times a user guessed
    // cascading if statments to adjust the boundaries of the next allowed guess
    while(counts>0)
    {
        cout<<"Enter your guess in between range ["<<l<<", "<<h<<"]: ";
        cin>>guess;
        if(guess==x4)
        {
            cout<<"You guessed it correctly, the number is "<<x4<<" and you have used "<<counts-5<<" guesses"<<endl;
            return 1;
        }
        if(guess>x4)
        {
    cout<<"The number  chosen is bigger"<<endl;
        h=guess-1;
        }
        else
        {

    cout<<"The number chosen is smaller"<<endl;
        l=guess+1;
        }
        counts--;
    }
    cout<<"You're unable to tell the number in five trials, the number was "<<x4<<endl;
    return 0;

}
