/*
Author: Edmund Gunn, Jr.
Question 
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;


//check is lowercase is present
bool isLowerCase(string s){
    for (char c : s){
        if(c < 'a' || c > 'z'){
            return false;
        }
    } 
    return true;
}

//check if number is present
bool hasNumber(string s){
    for (char c : s){
        if(c >= '0' && c <= '9'){
            return true;
        }
    }
    return false;
}

//main
int main(){

    vector<string> inputStrings;
    vector<string> outputStrings;
    string input;
    int count = 0;

    cout<<"Please enter a non-empty sequence of Strings. Each string should \n be in a separate line and consists of only lowercase English \n letters and/or numerical characters. To indicate the end of the \n input, enter an empty string in one line."<<endl;
    while(getline(cin,input) && !input.empty()){
        inputStrings.push_back(input);
    }
    
    for(string s : inputStrings){
        if(!isLowerCase(s) || hasNumber(s)){
        outputStrings.push_back(s);
        }
        else{
            count++;
        }
    }

    for (string s : outputStrings){
        cout << s << endl;
    }

    cout<< "Number of Strings in the input sequence that contain only \n lowercase English letters:"<<endl;
    cout<<count<<endl;


    return 0;
}