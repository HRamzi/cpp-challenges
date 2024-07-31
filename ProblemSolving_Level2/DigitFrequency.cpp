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

int main(){

    int number = readNumber("Enter number: ");
    short DigitToCheck = readNumber("Enter a Digit: ");

    cout<< "\nDigit " << DigitToCheck << " Frequency is "
        << CountDigitFrequency(DigitToCheck, number)
        << " Time(s).\n";

    return 0;
}