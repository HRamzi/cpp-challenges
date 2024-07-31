#include <iostream>
#include <string>

using namespace std;

int readNumber(string msg){
    int num;
    cout<<msg;
    cin>>num;
    return num;
}

int reverseNumber(int number){
    int revNum = 0;
    while(number>0){
        revNum = revNum*10 + number%10;
        number /= 10;
    }
    return revNum;
}

int main(){

    cout<<"Reverse: \n"
        <<reverseNumber(readNumber("Enter Number: "))
        <<"\n";

    return 0;
}