#include <iostream>
#include <string.h>

using namespace std;

int readNumber(){
    
    int num;

    cout<<"Enter a number: ";
    cin>>num;

    return num;
}

float calculHalfNumber(int num){

    return (float)num/2;
}

void printResult(int num){

    string result = "Half of "+to_string(num)+" is "+to_string(calculHalfNumber(num));

    cout<<result<<endl;
}

int main(){

    printResult(readNumber());
    
    return 0;
}