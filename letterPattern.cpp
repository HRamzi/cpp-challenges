#include <iostream>
#include <string>
using namespace std;

int readNumber(string msg){
    int num;
    cout<<msg;
    cin>>num;
    return num;
}

void printLetterPattern(int num){
    for(int i=65; i>=65; i++){
        for(int j=65; j<=i; j++)
            cout<<char(i);
        cout<<"\n";
    }
}

int main(){

    printLetterPattern(readNumber("Enter Number: "));

    return 0;
}