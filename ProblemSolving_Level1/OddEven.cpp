#include <iostream>

using namespace std;

enum enNumberType{odd=1, even=2};

int readNumber(){
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    return num;
}

enNumberType checkNumberType(int num){
    if(num%2==0)
        return enNumberType::even;
    else
        return enNumberType::odd;
}

void printNumberType(enNumberType numberType){
    if(numberType == enNumberType::even)
        cout<<"\nNumber is Even\n";
    else
        cout<<"\nNumber is Odd\n";
}

int main(){
    printNumberType(checkNumberType(readNumber()));
    return 0;
}
