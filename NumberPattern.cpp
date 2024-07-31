#include <iostream>
#include <string>
using namespace std;

int readNumber(string msg){
    int num;
    cout<<msg;
    cin>>num;
    return num;
}

void printNumberPattern(int num){
    for(int i=1; i<=num; i++){
        for(int j=1; j<=i; j++)
            cout<<i;
        cout<<"\n";
    }
}

int main(){

    printNumberPattern(readNumber("Enter Number: "));

    return 0;
}