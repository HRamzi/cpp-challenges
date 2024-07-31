#include <iostream>
#include <string>

using namespace std;

int readNumber(string msg){
    int num;
    cout<<msg;
    cin>>num;
    return num;
}

int CountDigitFrequency(short DigitToCheck, int number){
    int FreqCount = 0, Remainder = 0;
    while(number>0){
        Remainder = number%10;
        number = number/10;
        if(DigitToCheck == Remainder)
            FreqCount++;
    }
    return FreqCount;
}

void printAllDigitFrequency(int number){
    for(int i=0; i<10; i++){
        short digitFrequency;
        digitFrequency = CountDigitFrequency(i, number);
        if(digitFrequency>0){
            cout<<"Digit "<<i<<" Frequencey is "
                <<digitFrequency<<" Time(s).\n";
                }
        }
}

int main(){

    int number = readNumber("Enter number: ");

    printAllDigitFrequency(number);

    return 0;
}