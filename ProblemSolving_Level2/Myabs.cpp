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

float Myabs(float Number){
    if(Number<0)
        Number = -1 * Number;
    return Number;
}

int main(){

    float Number;
    Number = readNumber("Enter a Number:\n");

    cout<<"\nMy abs Result: "<<Myabs(Number);
    cout<<"\nC++ abs Result: "<<abs(Number)<<"\n\n";

    return 0;
}