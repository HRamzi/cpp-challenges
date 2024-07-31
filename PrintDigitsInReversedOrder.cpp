#include <iostream>

using namespace std;

int readNumber(string msg){
    int num;
    cout<<msg;
    cin>>num;
    return num;
}

void printDigitInReversedOrder(int number){
    int remainder = 0;
    while(number>0){
        remainder = number%10;
        cout<<remainder<<endl;
        number = number / 10;
    }
}

int main(){

    printDigitInReversedOrder(readNumber("Enter number: "));

    return 0;
}