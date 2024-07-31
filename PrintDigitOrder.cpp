#include <iostream>
#include <string>

using namespace std;

int readNumber(string msg){
    int num;
    cout<<msg;
    cin>>num;
    return num;
}

int reverseDigitsNumber(int number){
    int revNumber = 0;
    while(number>0){
        revNumber = revNumber*10 + number%10;
        number /= 10;
    }
    return revNumber;
}

void printDigitInOrder(int number){
    number = reverseDigitsNumber(number);
    while(number>0){
        cout<<number%10<<endl;
        number /= 10;
    }
}

int main(){

    printDigitInOrder(readNumber("Enter Number: "));

    return 0;
}