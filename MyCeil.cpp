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

int MyCeil(float Number){
    int Intpart = (int)Number;
    if(Number < 0)
        return Intpart;
    return ++Intpart;
}

int main(){

    float Number;
    Number = readNumber("Enter a Number:\n");

    cout<<"\nMy ceil Result: "<<MyCeil(Number);
    cout<<"\nC++ ceil Result: "<<ceil(Number)<<"\n\n";

    return 0;
}