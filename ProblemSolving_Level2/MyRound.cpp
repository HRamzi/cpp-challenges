#include <iostream>
#include <string>
#include <cmath>
using namespace std;

float readNumber(string msg){
    float number;
    cout<<msg;
    cin>>number;
    return number;
}

float getFractions(float Number){
    return Number - (int)Number;
}

int MyRound(float Number){
    int Intpart = (int)Number;
    float fractionsPart = getFractions(Number);
    if(abs(fractionsPart) >= 0.5){
        if(Number>0)
            return ++Intpart;
        else
            return --Intpart;
    }
    return Intpart;
}

int main(){

    float Number;
    Number = readNumber("Enter a Number:\n");

    cout<<"\nMy round Result: "<<MyRound(Number);
    cout<<"\nC++ round Result: "<<round(Number)<<"\n\n";

    return 0;
}