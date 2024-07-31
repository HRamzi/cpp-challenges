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

int MySqrt(float Number){
    return pow(Number, 0.5);
}

int main(){

    float Number;
    Number = readNumber("Enter a Number:\n");

    cout<<"\nMy sqrt Result: "<<MySqrt(Number);
    cout<<"\nC++ sqrt Result: "<<sqrt(Number)<<"\n\n";

    return 0;
}