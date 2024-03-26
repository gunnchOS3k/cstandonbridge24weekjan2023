#include <iostream>
#include <string>
using namespace std;

int main (){
    //varible declaration
    int n;
    int ast;
    int counter;
    int total;
    int astcount;
    int lcount;
    int rcount;
    int lspace;
    int rspace;
    string out;
    
    //get user input
    cout << "Please enter a positive integer." <<endl;
    cin >> n;
    
    //input based calculation
    total = 2*n;
    ast = total - 1;
    counter = 2*n;
    astcount = ast;
    lspace = 0;
    rspace = 0;

    //nested while loops to display results
    while(counter>n){
        astcount = ast;
        lcount = lspace;
        rcount = rspace;
        while(astcount > 0){
            out = "*" + out;
            astcount--;
        }
        while(lcount > 0){
            out = " " + out;
            lcount--;
        }
        while(rcount >0){
            out = out + " ";
            rcount--;
        }
        cout << out << endl;
        out = "";
        ast = ast - 2;
        lspace++;
        rspace = lspace;
        counter--;
    }
    ast = 1;
    lspace = (total - 1)/2;
    rspace = lspace;
    while(counter>0){
        astcount = ast;
        lcount = lspace;
        rcount = rspace;
        while(astcount > 0){
            out = "*" + out;
            astcount--;
        }
        while(lcount > 0){
            out = " " + out;
            lcount--;
        }
        while(rcount >0){
            out = out + " ";
            rcount--;
        }
        cout << out << endl;
        out = "";
        ast = ast + 2;
        lspace--;
        rspace = lspace;
        counter--;
    }

    return 0;
}