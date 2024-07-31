#include <iostream>
#include <string>

using namespace std;

int readNumber(string msg){
    int num;
    cout<<msg;
    cin>>num;
    return num;
}

int reverseNumber(int num){
    int revNum=0;
    while(num>0){
        revNum = revNum*10 + num%10;
        num /= 10;
    }
    return revNum;
}

bool isPalindromeNumber(int num){
    return num == reverseNumber(num);
}

int main(){

    bool res = isPalindromeNumber(readNumber("\nEnter a Number to check if it's Palindrome:\n"));

    if(res)
        cout<<"--> Yes, it's a Palindrome Number"<<endl;
    else
        cout<<"--> NO, it's NOT a Palindrome Number"<<endl;

    return 0;
}