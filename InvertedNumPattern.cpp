#include <iostream>
#include <string>

using namespace std;

int readNumber(string msg){
    int num;
    cout<<msg;
    cin>>num;
    return num;
}

void printInvertedNumberPattern(int num){
    for(int i=num; i>0; i--){
        for(int j=1; j<=i; j++)
            cout<<i;
        cout<<"\n";
    }
}

int main(){

    printInvertedNumberPattern(readNumber("Enter Number: "));

    return 0;
}