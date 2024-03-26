#include <iostream>
#include <string>
using namespace std;

int main () { 
     //varible declaration
    int num;
    int num_w;
    int remain;
    int div;
    int remain_w;
    int div_w;
    int counter;

    string roman;
    string rom_one;
    string rom_fiv;

    //get user input
    cout << "Enter decimal number: " << endl;
    cin >> num;
    remain = num;
    num_w = num;
    counter = 0;
    div = 10;
    rom_one = "I";
    rom_fiv = "V";

    
    //ested loops and condutional statments to calculate results
    while(div>0){
        if(counter != 0){
            num_w = div;
        }
        //gets first decimal
        remain = num_w % 10;
        div = num_w / 10;
        remain_w = remain % 5;
        div_w = remain / 5;
        if(counter==1){
            rom_one = "X";
            rom_fiv = "L";
        }
        else if(counter==2){
            rom_one = "C";
            rom_fiv = "D";
        }
        else if(counter == 3){
            rom_one = "M";
            rom_fiv = "MMMMM";
        }
        else if(counter > 3){
            while(remain_w>0){
                roman = "MMMMMMMMMM" + roman;
                remain_w--;
            }
            remain_w = 0;
            div_w = 0;
            div = 0;
        }
        while(remain_w > 0){
            roman = rom_one + roman;
            remain_w--;
        }
        while(div_w > 0){   
            roman = rom_fiv + roman;
            div_w--;
        }
        counter++;
    }


    //display results
    cout << num << " is " << roman << endl;

    return 0;
}