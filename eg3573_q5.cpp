/*
Author: Edmund Gunn, Jr.
Question 3


*/
#include <string>
#include <iostream>
using namespace std;
int countConsonants(string S, int length){
    //base case
    if(length <=1 ){
        return 0;
    }
    //recursion
    int count = countConsonants(S, length - 1);
    char lastChar = S[length -1];
    if ((lastChar >= 'a' && lastChar <='z') ||(lastChar >= 'A' && lastChar <='Z') ){
        if(lastChar != 'a' && lastChar != 'e' && lastChar != 'i' && lastChar != 'o' &&  lastChar != 'u' &&
        lastChar != 'A' && lastChar != 'E' && lastChar != 'I' && lastChar != 'O' &&  lastChar != 'U')
        count++;
    }
    return count;

}

int main(){
    return 0;
}