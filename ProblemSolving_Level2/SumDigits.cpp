#include <iostream>
#include <string>

using namespace std;

int readNumber(string msg){
    int num;
    cout<<msg;
    cin>>num;
    return num;
}

int sumDigits(int Digits){
    int sum = 0;
    while(Digits>0){
        sum += Digits%10;
        Digits /= 10;
    }
    return sum;
}

int main(){

    cout<<"Sum of Digits: "
        <<sumDigits(readNumber("Enter a Number: "))
        <<"\n";

    return 0;
}